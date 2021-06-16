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
struct Vector: public std::array<float, N> {
    Vector() = default;

    Vector(std::initializer_list<float> l) noexcept;

    Vector(const Vector& other) = default;

    float norm() const noexcept;

    Vector& normalize() noexcept;

    Vector& negate() noexcept;

    Vector& operator+=(const Vector& v) noexcept;

    Vector& operator-=(const Vector& v) noexcept;

    Vector& operator*=(float f) noexcept;

    Vector& operator/=(float f) noexcept;
};

using Vector2 = Vector<2>;
using Vector3 = Vector<3>;
using Vector4 = Vector<4>;
using Point2 = Vector2;
using Point3 = Vector3;
using Point4 = Vector4;
using Color = Vector4;

template <std::size_t N>
Vector<N>::Vector(std::initializer_list<float> l) noexcept
{
    auto it = this->begin();
    for (auto i = l.begin(); it != this->end() && i != l.end(); ++it, ++i)
    {
        *it = *i;
    }
}

template <std::size_t N>
float Vector<N>::norm() const noexcept
{
    float n = 0.0f;
    for (auto it = this->cbegin(); it != this->cend(); ++it)
    {
        n += *it * *it;
    }

    n = sqrt(n);
    return n;
}

template <std::size_t N>
Vector<N>& Vector<N>::normalize() noexcept
{
    return *this /= norm();
}

template <std::size_t N>
Vector<N>& Vector<N>::negate() noexcept
{
    for (auto it = this->begin(); it != this->end(); ++it)
    {
         *it = -(*it);
    }
    return *this;
}

template <std::size_t N>
Vector<N>& Vector<N>::operator+=(const Vector<N>& v) noexcept
{
    auto it = this->begin();
    for (auto i = v.begin(); it != this->end(); ++it, ++i)
    {
         *it += *i;
    }
    return *this;
}

template <std::size_t N>
Vector<N>& Vector<N>::operator-=(const Vector<N>& v) noexcept
{
    auto it = this->begin();
    for (auto i = v.begin(); it != this->end(); ++it, ++i)
    {
         *it -= *i;
    }
    return *this;
}

template <std::size_t N>
Vector<N>& Vector<N>::operator*=(float f) noexcept
{
    for (auto it = this->begin(); it != this->end(); ++it)
    {
         *it += f;
    }
    return *this;
}

template <std::size_t N>
Vector<N>& Vector<N>::operator/=(float f) noexcept
{
    return *this *= (1.0f / f);
}

template <std::size_t N>
Vector<N> operator+(const Vector<N>& lhs,
                    const Vector<N>& rhs)
{
    Vector<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs[i] + rhs[i];
    }
    return r;
}

template <std::size_t N>
Vector<N> operator-(const Vector<N>& lhs,
                    const Vector<N>& rhs)
{
    Vector<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs[i] - rhs[i];
    }
    return r;
}


template <std::size_t N>
Vector<N> operator*(const Vector<N>& lhs,
                    float rhs)
{
    Vector<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs[i] * rhs;
    }
    return r;
}


template <std::size_t N>
Vector<N> operator*(float lhs,
                    const Vector<N>& rhs)
{
    Vector<N> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        r[i] = lhs * rhs[i];
    }
    return r;
}

template <std::size_t N>
Vector<N> operator/(const Vector<N>& lhs,
                    float rhs)
{
    return lhs * (1.0f / rhs);
}

template <std::size_t N>
float dot(const Vector<N>& lhs,
          const Vector<N>& rhs)
{
    float r = 0;
    for (std::size_t i = 0; i < N; ++i)
    {
        r += lhs[i] * rhs[i];
    }
    return r;
}

template <std::size_t N>
bool fuzzyEqual(const Vector<N>& v1,
                const Vector<N>& v2,
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

Vector3 cross(const Vector3& lhs,
              const Vector3& rhs);


} // end of namespace sharedlib

namespace std {

template <std::size_t N>
std::ostream& operator<<(std::ostream& out,
                         const sharedlib::Vector<N>& v)
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
                         sharedlib::Vector<N>& v)
{
    for (std::size_t i = 0; in.good() && i < N; ++i)
    {
        in >> v[i];
    }
    return in;
}

} // end of namespace std

#endif

