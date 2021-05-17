#include <cmath>
#include <sharedlib_math_utils.h>
#include <sharedlib_matrix.h>

namespace sharedlib {

Mat4 translate(float dx,
               float dy,
               float dz)
{
    Mat4 m = identity<4>();
    m[0][3] = dx;
    m[1][3] = dy;
    m[2][3] = dz;

    return m;
}

Mat4 rotateX(float cosTheta,
             float sinTheta)
{
    Mat4 m = identity<4>();
    m[1][1] = cosTheta;
    m[1][2] = -sinTheta;
    m[2][1] = sinTheta;
    m[2][2] = cosTheta;

    return m;
}

Mat4 rotateX(float degree)
{
    float theta = rad(degree);
    return rotateX(cos(theta), sin(theta));
}

Mat4 rotateY(float cosTheta,
             float sinTheta)

{
    Mat4 m = identity<4>();
    m[0][0] = cosTheta;
    m[0][2] = sinTheta;
    m[2][0] = -sinTheta;
    m[2][2] = cosTheta;

    return m;
}

Mat4 rotateY(float degree)
{
    float theta = rad(degree);
    return rotateY(cos(theta), sin(theta));
}

Mat4 rotateZ(float cosTheta,
             float sinTheta)
{
    Mat4 m = identity<4>();
    m[0][0] = cosTheta;
    m[0][1] = -sinTheta;
    m[1][0] = sinTheta;
    m[1][1] = cosTheta;

    return m;
}

Mat4 rotateZ(float degree)
{
    float theta = rad(degree);
    return rotateZ(cos(theta), sin(theta));
}

Mat4 scale(float sx,
           float sy,
           float sz)
{
    Mat4 m = identity<4>();
    m[0][0] = sx;
    m[1][1] = sy;
    m[2][2] = sz;

    return m;
}

} // end of namespace sharedlib

