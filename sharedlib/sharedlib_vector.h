#ifndef INCLUDE_SHAREDLIB_VECTOR_H
#define INCLUDE_SHAREDLIB_VECTOR_H

#include <initializer_list>
#include <ostream>
#include <istream>
#include <array>
#include <algorithm>
#include <sharedlib_math_utils.h>

namespace sharedlib {

template <std::size_t N>
struct Vec: public std::array<float, N> {
    Vec() = default;

    Vec(std::initializer_list<float> l) noexcept;

    Vec(const Vec& other) = default;

    float norm() const noexcept;

    Vec& normalize() noexcept;

    Vec& negate() noexcept;

    Vec& operator+=(const Vec& v) noexcept;

    Vec& operator-=(const Vec& v) noexcept;

    Vec& operator*=(float f) noexcept;

    Vec& operator/=(float f) noexcept;
};

using Vec2 = Vec<2>;
using Vec3 = Vec<3>;
using Vec4 = Vec<4>;
using Point2 = Vec2;
using Point3 = Vec3;
using Point4 = Vec4;
using Color = Vec4;

template <std::size_t N>
Vec<N> operator+(const Vec<N>& lhs,
                 const Vec<N>& rhs)
{
    Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs[i] + rhs[i];
    }
    return r;
}

template <std::size_t N>
Vec<N> operator-(const Vec<N>& lhs,
                 const Vec<N>& rhs)
{
    Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs[i] - rhs[i];
    }
    return r;
}


template <std::size_t N>
Vec<N> operator*(const Vec<N>& lhs,
                 float rhs)
{
    Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs[i] * rhs;
    }
    return r;
}


template <std::size_t N>
Vec<N> operator*(float lhs,
                 const Vec<N>& rhs)
{
    Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs * rhs[i];
    }
    return r;
}

template <std::size_t N>
Vec<N> operator/(const Vec<N>& lhs,
                 float rhs)
{
    return lhs * (1.0f / rhs);
}

template <std::size_t N>
float dot(const Vec<N>& lhs,
          const Vec<N>& rhs)
{
    float r = 0;
    for (std::size_t i = 0; i < N; ++i)
    {
        r += lhs[i] * rhs[i];
    }
    return r;
}

Vec3 cross(const Vec3& lhs,
           const Vec3& rhs);

template <std::size_t N>
void negate(const Vec<N>& v)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        v[i] = -v[i];
    }
}

template <std::size_t N>
bool fuzzyEqual(const Vec<N>& v1,
                const Vec<N>& v2,
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

template <std::size_t N>
float norm(const Vec<N>& v)
{
    float n = 0.0f;
    for (std::size_t i = 0; i < N; ++i)
    {
        n += v[i] * v[i];
    }

    n = sqrt(n);
    return n;
}

template <std::size_t N>
void normalize(Vec<N>& v)
{
    float n = norm(v);
}
} // end of namespace sharedlib

namespace std {

template <std::size_t N>
std::ostream& operator<<(std::ostream& out,
                         const sharedlib::Vec<N>& v)
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
std::istream& operator>>(std::istream& in,
                         sharedlib::Vec<N>& v)
{
    for (std::size_t i = 0; in.good() && i < N; ++i)
    {
        in >> v[i];
    }
    return in;
}

} // end of namespace std

namespace sharedlib {



} // end of namespace sharedlib

#endif

