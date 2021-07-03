#ifndef INCLUDE_SHAREDLIB_JSON_PARAM_H
#define INCLUDE_SHAREDLIB_JSON_PARAM_H

#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <rapidjson/document.h>
#include <sharedlib_my_exception.h>
#include <sharedlib_stringify.h>
#include <sharedlib_validator.h>
#include <sharedlib_json_utils.h>
#include <sharedlib_parse_json.h>

namespace sharedlib {

class JsonParam {
public:
    JsonParam(std::initializer_list<std::string> path,
              bool required=true,
              const Validator& v=Validator()) noexcept
        : path_(path)
        , required_(required)
        , validator_(v)
    {}

    virtual void parse(const rapidjson::Document& doc) = 0;

protected:
    std::vector<std::string> path_;
    bool required_;
    Validator validator_;
};

using JsonParamPtr = std::shared_ptr<JsonParam>;

template <typename T>
class TypedJsonParam: public JsonParam {
public:
    TypedJsonParam(T& var,
                   const std::initializer_list<std::string> path,
                   bool required=true,
                   Validator v=Validator()) noexcept
        : JsonParam(path, required, v)
        , var_(var)
    {}

    void parse(const rapidjson::Document& doc) override;

protected:
    T& var_;
};

template <typename T>
JsonParamPtr jsonParam(T& var,
                       const std::initializer_list<std::string> path,
                       bool required=true,
                       Validator v=Validator())
{
    return JsonParamPtr(new TypedJsonParam<T>(var, path, required, v));
}

template <typename T>
void TypedJsonParam<T>::parse(const rapidjson::Document& doc)
{
    const rapidjson::Value* v = findJson(doc, path_);
    if (!v)
    {
        if (required_)
        {
            THROW_EXCEPT("Failed to find path " + toString(path_));
        }

        return;
    }

    parseJson(var_, *v);

    if (!validator_())
    {
        THROW_EXCEPT("Validation failed: " + validator_.rule());
    }
}

void parse(std::vector<JsonParamPtr>& params,
           const rapidjson::Document& doc)
{
    for (auto it = params.begin(); it != params.end(); ++it)
    {
        (*it)->parse(doc);
    }
}

} // end of namespace sharedlib

#endif

