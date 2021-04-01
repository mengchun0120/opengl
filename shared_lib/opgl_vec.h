#ifndef INCLUDE_OPGL_VEC_H
#define INCLUDE_OPGL_VEC_H

namespace opgl {

struct Vec2 {
    float x;
    float y;
};

Vec2 operator+(const Vec2 &v1,
               const Vec2 &v2);

Vec2 operator-(const Vec2 &v1,
               const Vec2 &v2);

Vec2 operator*(const Vec2 &v,
               float f);

Vec2 operator*(float f,
               const Vec2 &v);

Vec2 operator/(const Vec2 &v,
               float f);

} // end of namespace opgl

#endif

