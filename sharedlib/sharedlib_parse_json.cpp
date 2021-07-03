#include <sharedlib_parse_json.h>

namespace sharedlib {

void parseBool(bool& b,
               const rapidjson::Value& v)
{
    if (!v.IsBool())
    {
        THROW_EXCEPT("Json object is not a bool");
    }

    b = v.GetBool();
}

void parseJson(int& i,
               const rapidjson::Value& v)
{
    if (!v.IsInt())
    {
        THROW_EXCEPT("Json object is not an int");
    }

    i = v.GetInt();
}

void parseJson(unsigned int& u,
               const rapidjson::Value& v)
{
    if (!v.IsUint())
    {
        THROW_EXCEPT("Json object is not an unsigned int");
    }

    u = v.GetUint();
}

void parseJson(int64_t& i,
               const rapidjson::Value& v)
{
    if (!v.IsInt64())
    {
        THROW_EXCEPT("Json object is not an int64_t");
    }

    i = v.GetInt64();
}

void parseJson(uint64_t& u,
               const rapidjson::Value& v)
{
    if (!v.IsUint64())
    {
        THROW_EXCEPT("Json object is not a uint64_t");
    }

    u = v.GetUint64();
}

void parseJson(float& f,
               const rapidjson::Value& v)
{
    double d;
    parseJson(d, v);
    f = static_cast<float>(d);
}

void parseJson(double& d,
               const rapidjson::Value& v)
{
    if (!v.IsDouble())
    {
        THROW_EXCEPT("Json object is not a double");
    }

    d = v.GetDouble();
}

void parseJson(std::string& s,
               const rapidjson::Value& v)
{
    if (!v.IsString())
    {
        THROW_EXCEPT("Json object is not a string");
    }

    s = v.GetString();
}

} // end of namespace sharedlib

