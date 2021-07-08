#ifndef INCLUDE_SHAREDLIB_PARSE_JSON_H
#define INCLUDE_SHAREDLIB_PARSE_JSON_H

#include <vector>
#include <array>
#include <cstdint>
#include <string>
#include <algorithm>
#include <sharedlib_my_exception.h>
#include <rapidjson/document.h>

namespace sharedlib {

void parseBool(bool& b,
               const rapidjson::Value& v);

void parseJson(int& i,
               const rapidjson::Value& v);

void parseJson(unsigned int& u,
               const rapidjson::Value& v);

void parseJson(int64_t& i,
               const rapidjson::Value& v);

void parseJson(uint64_t& u,
               const rapidjson::Value& v);

void parseJson(float& f,
               const rapidjson::Value& v);

void parseJson(double& d,
               const rapidjson::Value& v);

void parseJson(std::string& s,
               const rapidjson::Value& v);

template <typename T>
void parseJson(std::vector<T>& a,
               const rapidjson::Value& v)
{
    if (!v.IsArray())
    {
        THROW_EXCEPT("Json object is not an array");
    }

    a.resize(v.Capacity());
    for (std::size_t i = 0; i < a.size(); ++i)
    {
        parseJson(a[i], v[i]);
    }
}

template <typename T, std::size_t N>
void parseJson(std::array<T,N>& a,
               const rapidjson::Value& v)
{
    if (!v.IsArray())
    {
        THROW_EXCEPT("Json object is not an array");
    }

    std::size_t sz = std::min(N, v.Capacity());
    for (std::size_t i = 0; i < sz; ++i)
    {
        parseJson(a[i], v[i]);
    }
}

} // end of namespace sharedlib

#endif

