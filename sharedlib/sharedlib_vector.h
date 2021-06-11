#ifndef INCLUDE_SHAREDLIB_VECTOR_H
#define INCLUDE_SHAREDLIB_VECTOR_H

#include <ostream>
#include <istream>
#include <array>
#include <sharedlib_math_utils.h>

namespace sharedlib {

template <std::size_t N>
using Vec = std::array<float, N>;

using Vec2 = Vec<2>;
using Vec3 = Vec<3>;
using Vec4 = Vec<4>;
using Point2 = Vec2;
using Point3 = Vec3;
using Point4 = Vec4;
using Color = Vec4;

template <std::size_t N>
float dot(const Vec<N> &lhs,
          const Vec<N> &rhs)
{
    float r = 0;
    for (std::size_t i = 0; i < N; ++i)
    {
        r += lhs[i] * rhs[i];
    }
    return r;
}

Vec3 cross(const Vec3 &lhs,
           const Vec3 &rhs);

template <std::size_t N>
Vec<N> &assign(Vec<N> &v,
               float f)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        v[i] = f;
    }
    return v;
}

template <std::size_t N>
Vec<N> minus(const Vec<N> &v)
{
    Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = -v[i];
    }
    return r;
}

template <std::size_t N>
Vec<N> unit(std::size_t n)
{
    Vec<N> r;
    assign(r, 0.0f);
    r[n] = 1.0f;
    return r;
}

template <std::size_t N>
bool fuzzyEqual(const Vec<N> &v1,
                const Vec<N> &v2,
                float threshold=1e-06f)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        if (!fuzzyEqual(v1[i], v2[i], threshold))
        {
            return false;
        }
    }

    return true;
}

} // end of namespace sharedlib

namespace std {

template <std::size_t N>
sharedlib::Vec<N> operator+(const sharedlib::Vec<N> &lhs,
                            const sharedlib::Vec<N> &rhs)
{
    sharedlib::Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs[i] + rhs[i];
    }
    return r;
}

template <std::size_t N>
sharedlib::Vec<N> operator-(const sharedlib::Vec<N> &lhs,
                            const sharedlib::Vec<N> &rhs)
{
    sharedlib::Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs[i] - rhs[i];
    }
    return r;
}


template <std::size_t N>
sharedlib::Vec<N> operator*(const sharedlib::Vec<N> &lhs,
                            float rhs)
{
    sharedlib::Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs[i] * rhs;
    }
    return r;
}


template <std::size_t N>
sharedlib::Vec<N> operator*(float lhs,
                            const sharedlib::Vec<N> &rhs)
{
    sharedlib::Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs * rhs[i];
    }
    return r;
}

template <std::size_t N>
sharedlib::Vec<N> operator/(const sharedlib::Vec<N> &lhs,
                            float rhs)
{
    return lhs * (1.0f / rhs);
}

template <std::size_t N>
std::ostream &operator<<(std::ostream &out,
                         const sharedlib::Vec<N> &v)
{
    out << '[';
    if (N > 0)
    {
        out << v[0];
        for (std::size_t i = 1; i < N; ++i)
        {
            out << ", " << v[i];
        }
    }
    out << ']';

    return out;
}

template <std::size_t N>
std::istream &operator>>(std::istream &in,
                         sharedlib::Vec<N> &v)
{
    for (std::size_t i = 0; in.good() && i < N; ++i)
    {
        in >> v[i];
    }
    return in;
}

} // end of namespace std

#endif

