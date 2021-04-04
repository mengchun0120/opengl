#ifndef INCLUDE_OPGL_VECTOR_H
#define INCLUDE_OPGL_VECTOR_H

#include <ostream>

namespace sharedlib {

struct Vec2 {
    float x;
    float y;
};

struct Vec3 {
    float x;
    float y;
    float z;
};

inline Vec2 operator+(const Vec2 &lhs,
                      const Vec2 &rhs)
{
    return Vec2{lhs.x+rhs.x, lhs.y+rhs.y};
}

inline Vec2 operator-(const Vec2 &lhs,
                      const Vec2 &rhs)
{
    return Vec2{lhs.x-rhs.x, lhs.y-rhs.y};
}

inline Vec2 operator*(const Vec2 &v,
                      float f)
{
    return Vec2{v.x*f, v.y*f};
}

inline Vec2 operator*(float f,
                      const Vec2 &v)
{
    return v * f;
}

inline Vec2 operator/(const Vec2 &v,
                      float f)
{
    return v * (1.0f/f);
}

inline Vec3 operator+(const Vec3 &lhs,
                      const Vec3 &rhs)
{
    return Vec3{lhs.x+rhs.x, lhs.y+rhs.y, lhs.z+rhs.z};
}

inline Vec3 operator-(const Vec3 &lhs,
                      const Vec3 &rhs)
{
    return Vec3{lhs.x-rhs.x, lhs.y-rhs.y, lhs.z-rhs.z};
}

inline Vec3 operator*(const Vec3 &v,
                      float f)
{
    return Vec3{v.x*f, v.y*f};
}

inline Vec3 operator*(float f,
                      const Vec3 &v)
{
    return v * f;
}

inline Vec3 operator/(const Vec3 &v,
                      float f)
{
    return v * (1.0f/f);
}


} // end of namespace sharedlib

namespace std {

inline std::ostream &operator<<(std::ostream &os,
                                const sharedlib::Vec2 &v)
{
    return os << '(' << v.x << ", " << v.y << ')';
}

inline std::ostream &operator<<(std::ostream &os,
                                const sharedlib::Vec3 &v)
{
    return os << '(' << v.x << ", " << v.y << ", " << v.z << ')';
}



} // end of namespace std

#endif

