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
              const Validator& v=Validator(),
              bool required=true) noexcept
        : path_(path)
        , validator_(v)
        , required_(required)
    {}

    const std::vector<std::string>& path() const noexcept
    {
        return path_;
    }

    bool required() const noexcept
    {
        return required_;
    }

    const Validator validator() const noexcept
    {
        return validator_;
    }

    virtual void parse(const rapidjson::Document& doc) = 0;

private:
    std::vector<std::string> path_;
    Validator validator_;
    bool required_;
};

using JsonParamPtr = std::shared_ptr<JsonParam>;

template <typename T>
class TypedJsonParam: public JsonParam {
public:
    TypedJsonParam(T& var,
                   const std::initializer_list<std::string> path,
                   Validator v=Validator(),
                   bool required=true)
        : JsonParam(path, v, required)
        , var_(var)
    {}

    void parse(const rapidjson::Document& doc) override;

protected:
    T& var_;
};

template <typename T>
JsonParamPtr jsonParam(T& var,
                       const std::initializer_list<std::string> path,
                       Validator v=Validator(),
                       bool required=true)
{
    return JsonParamPtr(new TypedJsonParam<T>(var, path, v, required));
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

