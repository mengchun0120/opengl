#include "opgl_vec.h"

namespace opgl {

Vec2 operator+(const Vec2 &v1,
               const Vec2 &v2)
{
    return Vec2{v1.x + v2.x, v1.y + v2.y};
}

Vec2 operator-(const Vec2 &v1,
               const Vec2 &v2)
{
    return Vec2{v1.x - v2.x, v1.y - v2.y};
}

Vec2 operator*(const Vec2 &v,
               float f)
{
    return Vec2{v.x * f, v.y * f};
}

Vec2 operator*(float f,
               const Vec2 &v)
{
    return v * f;
}

Vec2 operator/(const Vec2 &v,
               float f)
{
    return v * (1.0f / f);
}


} // end of namespace opgl

