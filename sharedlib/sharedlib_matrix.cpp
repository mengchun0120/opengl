#include <cmath>
#include <sharedlib_math_utils.h>
#include <sharedlib_matrix.h>

namespace sharedlib {

Mat4 &translate(Mat4 &m,
                float dx,
                float dy,
                float dz)
{
    identity(m);
    m[0][3] = dx;
    m[1][3] = dy;
    m[2][3] = dz;

    return m;
}

Mat4 &rotateX(Mat4 &m,
              float cosTheta,
              float sinTheta)
{
    identity(m);
    m[1][1] = cosTheta;
    m[1][2] = -sinTheta;
    m[2][1] = sinTheta;
    m[2][2] = cosTheta;

    return m;
}

Mat4 &rotateX(Mat4 &m,
              float degree)
{
    float theta = rad(degree);
    return rotateX(m, cos(theta), sin(theta));
}

Mat4 &rotateY(Mat4 &m,
              float cosTheta,
              float sinTheta)

{
    identity(m);
    m[0][0] = cosTheta;
    m[0][2] = sinTheta;
    m[2][0] = -sinTheta;
    m[2][2] = cosTheta;

    return m;
}

Mat4 &rotateY(Mat4 &m,
              float degree)
{
    float theta = rad(degree);
    return rotateY(m, cos(theta), sin(theta));
}

Mat4 &rotateZ(Mat4 &m,
              float cosTheta,
              float sinTheta)
{
    identity(m);
    m[0][0] = cosTheta;
    m[0][1] = -sinTheta;
    m[1][0] = sinTheta;
    m[1][1] = cosTheta;

    return m;
}

Mat4 &rotateZ(Mat4 &m,
              float degree)
{
    float theta = rad(degree);
    return rotateZ(m, cos(theta), sin(theta));
}

Mat4 &rotate(Mat4 &m,
             float x,
             float y,
             float z,
             float dx,
             float dy,
             float dz,
             float degree)
{
    float d = sqrt(dx*dx + dy*dy + dz*dz);
    float ax = dx / d;
    float ay = dy / d;
    float az = dz / d;

    identity(m);

    m = m * translate(m, x, y, z);
    m = m * rotateX(m, az/d, -ay/d);
    m = m * rotateY(m, az, ax);
    m = m * rotateZ(m, degree);
    m = m * rotateY(m, az, -ax);
    m = m * rotateX(m, az/d, ay/d);
    m = m * translate(m, -x, -y, -z);

    return m;
}

Mat4 &scale(Mat4 &m,
            float sx,
            float sy,
            float sz)
{
    identity(m);
    m[0][0] = sx;
    m[1][1] = sy;
    m[2][2] = sz;

    return m;
}

} // end of namespace sharedlib

