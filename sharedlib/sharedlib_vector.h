#ifndef INCLUDE_SHAREDLIB_VECTOR_H
#define INCLUDE_SHAREDLIB_VECTOR_H

#include <ostream>
#include <istream>
#include <array>

namespace sharedlib {

template <std::size_t N>
using Vec = std::array<float, N>;

using Vec2 = Vec<2>;
using Vec3 = Vec<3>;
using Vec4 = Vec<4>;

template <std::size_t N>
Vec<N> operator+(const Vec<N> &lhs,
                 const Vec<N> &rhs)
{
    Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs[i] + rhs[i];
    }
    return r;
}

template <std::size_t N>
Vec<N> operator-(const Vec<N> &lhs,
                 const Vec<N> &rhs)
{
    Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs[i] - rhs[i];
    }
    return r;
}


template <std::size_t N>
Vec<N> operator*(const Vec<N> &lhs,
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
                 const Vec<N> &rhs)
{
    Vec<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs * rhs[i];
    }
    return r;
}

template <std::size_t N>
Vec<N> operator/(const Vec<N> &lhs,
                 float rhs)
{
    return lhs * (1.0f / rhs);
}

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

} // end of namespace sharedlib

namespace std {

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

