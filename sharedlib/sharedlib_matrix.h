#ifndef INCLUDE_SHAREDLIB_MATRIX_H
#define INCLUDE_SHAREDLIB_MATRIX_H

#include <sharedlib_vector.h>

namespace sharedlib {

template <std::size_t M, std::size_t N>
using Mat = std::array<Vec<N>, M>;

using Mat2 = Mat<2, 2>;
using Mat3 = Mat<3, 3>;
using Mat4 = Mat<4, 4>;

template <std::size_t M, std::size_t N>
Mat<M, N> operator+(const Mat<M, N> &lhs,
                    const Mat<M, N> &rhs)
{
    Mat<M, N> m;
    for (std::size_t i = 0; i < M; ++i)
    {
        m[i] = lhs[i] + rhs[i];
    }
    return m;
}

template <std::size_t M, std::size_t N>
Mat<M, N> operator-(const Mat<M, N> &lhs,
                    const Mat<M, N> &rhs)
{
    Mat<M, N> m;
    for (std::size_t i = 0; i < M; ++i)
    {
        m[i] = lhs[i] - rhs[i];
    }
    return m;
}

template <std::size_t M, std::size_t N>
Mat<M, N> operator*(const Mat<M, N> &lhs,
                    float rhs)
{
    Mat<M, N> m;
    for (std::size_t i = 0; i < M; ++i)
    {
        m[i] = lhs[i] * rhs;
    }
    return m;
}

template <std::size_t M, std::size_t N>
Mat<M, N> operator*(float f,
                    const Mat<M, N> &rhs)
{
    return rhs * f;
}

template <std::size_t M, std::size_t N>
Vec<M> operator*(const Mat<M, N> &lhs,
                 const Vec<N> &rhs)
{
    Vec<M> v;
    for (std::size_t i = 0; i < M; ++i)
    {
        float s = 0.0f;
        for (std::size_t j = 0; j < N; ++j)
        {
            s += lhs[i][j] * rhs[j];
        }
        v[i] = s;
    }
    return v;
}

template <std::size_t M, std::size_t N>
Vec<N> operator*(const Vec<M> &lhs,
                 const Mat<M, N> &rhs)
{
    Vec<N> v;
    for (std::size_t i = 0; i < N; ++i)
    {
        float s = 0.0f;
        for (std::size_t j = 0; j < M; ++j)
        {
            s += lhs[j] * rhs[j][i];
        }
        v[i] = s;
    }
    return v;
}

template <std::size_t M, std::size_t N, std::size_t P>
Mat<M, P> operator*(const Mat<M, N> &lhs,
                    const Mat<N, P> &rhs)
{
    Mat<M, P> m;
    for (std::size_t i = 0; i < M; ++i)
    {
        m[i] = lhs[i] * rhs;
    }
    return m;
}

template <std::size_t M, std::size_t N>
Mat<N, M> transpose(const Mat<M, N> &m)
{
    Mat<N, M> r;
    for (std::size_t i = 0; i < N; ++i)
    {
        for (std::size_t j = 0; j < M; ++j)
        {
            r[i][j] = m[j][i];
        }
    }
    return r;
}

template <std::size_t M, std::size_t N>
Mat<M, N> minus(const Mat<M, N> &m)
{
    Mat<M, N> r;
    for (std::size_t i = 0; i < M; ++i)
    {
        r[i] = minus(m[i]);
    }
    return r;
}

template <std::size_t M, std::size_t N>
Mat<M, N> &assign(Mat<M, N> &m,
                  float f)
{
    for (std::size_t i = 0; i < M; ++i)
    {
        assign(m[i], f);
    }
    return m;
}

template <std::size_t M>
Mat<M, M> identity()
{
    Mat<M, M> r;
    assign(r, 0.0f);
    for (std::size_t i = 0; i < M; ++i)
    {
        r[i][i] = 1.0f;
    }
    return r;
}

template <std::size_t M, std::size_t N>
bool fuzzyEqual(const Mat<M, N> &m1,
                const Mat<M, N> &m2,
                float threshold=1e-6f)
{
    for (std::size_t i = 0; i < M; ++i)
    {
        if (!fuzzyEqual(m1[i], m2[i], threshold))
        {
            return false;
        }
    }

    return true;
}

Mat4 translate(float dx,
               float dy,
               float dz);

Mat4 rotateXCosSin(float cosTheta,
                   float sinTheta);

Mat4 rotateXRad(float theta);

Mat4 rotateXDegree(float degree);

Mat4 rotateYCosSin(float cosTheta,
                   float sinTheta);

Mat4 rotateYRad(float theta);

Mat4 rotateYDegree(float degree);

Mat4 rotateZCosSin(float cosTheta,
                   float sinTheta);

Mat4 rotateZRad(float theta);

Mat4 rotateZDegree(float degree);

Mat4 rotateCosSin(float x,
                  float y,
                  float z,
                  float dx,
                  float dy,
                  float dz,
                  float cosTheta,
                  float sinTheta);

Mat4 rotateTheta(float x,
                 float y,
                 float z,
                 float dx,
                 float dy,
                 float dz,
                 float theta);

Mat4 rotateDegree(float x,
                  float y,
                  float z,
                  float dx,
                  float dy,
                  float dz,
                  float degree);

Mat4 scale(float sx,
           float sy,
           float sz);

} // end of namespace sharedlib

namespace std {

template <std::size_t M, std::size_t N>
std::ostream &operator<<(std::ostream &out,
                         const sharedlib::Mat<M, N> &m)
{
    out << '[';
    if (M > 0)
    {
        out << m[0];
        for (std::size_t i = 1; i < M; ++i)
        {
            out << ", " << m[i];
        }
    }
    out << ']';

    return out;
}

template <std::size_t M, std::size_t N>
std::istream &operator>>(std::istream &in,
                         sharedlib::Mat<M, N> &m)
{
    for (std::size_t i = 0; in.good() && i < M; ++i)
    {
        in >> m[i];
    }
    return in;
}

} // end of namespace std

#endif

