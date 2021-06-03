#include <cmath>
#include <sharedlib_math_utils.h>
#include <sharedlib_matrix.h>

namespace sharedlib {

Mat4 translate(float dx,
               float dy,
               float dz)
{
    Mat4 m = identityMatrix<4>();
    m[0][3] = dx;
    m[1][3] = dy;
    m[2][3] = dz;

    return m;
}

Mat4 rotateXCosSin(float cosTheta,
                   float sinTheta)
{
    Mat4 m = identityMatrix<4>();
    m[1][1] = cosTheta;
    m[1][2] = -sinTheta;
    m[2][1] = sinTheta;
    m[2][2] = cosTheta;

    return m;
}

Mat4 rotateXRad(float theta)
{
    return rotateXCosSin(cos(theta), sin(theta));
}

Mat4 rotateXDegree(float degree)
{
    return rotateXRad(rad(degree));
}

Mat4 rotateYCosSin(float cosTheta,
                   float sinTheta)

{
    Mat4 m = identityMatrix<4>();
    m[0][0] = cosTheta;
    m[0][2] = sinTheta;
    m[2][0] = -sinTheta;
    m[2][2] = cosTheta;

    return m;
}

Mat4 rotateYRad(float theta)
{
    return rotateYCosSin(cos(theta), sin(theta));
}

Mat4 rotateYDegree(float degree)
{
    return rotateYRad(rad(degree));
}

Mat4 rotateZCosSin(float cosTheta,
                   float sinTheta)
{
    Mat4 m = identityMatrix<4>();
    m[0][0] = cosTheta;
    m[0][1] = -sinTheta;
    m[1][0] = sinTheta;
    m[1][1] = cosTheta;

    return m;
}

Mat4 rotateZRad(float theta)
{
    return rotateZCosSin(cos(theta), sin(theta));
}

Mat4 rotateZDegree(float degree)
{
    return rotateZRad(rad(degree));
}

int findPivotAxis(float dx,
                  float dy,
                  float dz)
{
    float a[] = {static_cast<float>(fabs(dx)),
                 static_cast<float>(fabs(dy)),
                 static_cast<float>(fabs(dz))};
    int pivot = 0;

    for (int i = 1; i < 2; ++i)
    {
        if (a[i] > a[pivot])
        {
            pivot = i;
        }
    }

    return pivot;
}

Mat4 rotatePivotXCosSin(float x,
                        float y,
                        float z,
                        float dx,
                        float dy,
                        float dz,
                        float cosTheta,
                        float sinTheta)
{
    float dxz = sqrt(dx*dx + dz*dz);
    float cosAlpha = dx / dxz;
    float sinAlpha = dz / dxz;
    float dxy = sqrt(dx*dx + dy*dy);
    float cosBeta = dx / dxy;
    float sinBeta = dy / dxy;

    Mat4 r = translate(x, y, z) *
             rotateYCosSin(cosAlpha, -sinAlpha) *
             rotateZCosSin(cosBeta, sinBeta) *
             rotateXCosSin(cosTheta, sinTheta) *
             rotateZCosSin(cosBeta, -sinBeta) *
             rotateYCosSin(cosAlpha, sinAlpha) *
             translate(-x, -y, -z);

    return r;
}

Mat4 rotatePivotYCosSin(float x,
                        float y,
                        float z,
                        float dx,
                        float dy,
                        float dz,
                        float cosTheta,
                        float sinTheta)
{
    float dxy = sqrt(dx*dx + dy*dy);
    float cosAlpha = dy / dxy;
    float sinAlpha = dx / dxy;
    float dyz = sqrt(dy*dy + dz*dz);
    float cosBeta = dy / dyz;
    float sinBeta = dz / dyz;

    Mat4 r = translate(x, y, z) *
             rotateZCosSin(cosAlpha, -sinAlpha) *
             rotateXCosSin(cosBeta, sinBeta) *
             rotateYCosSin(cosTheta, sinTheta) *
             rotateXCosSin(cosBeta, -sinBeta) *
             rotateZCosSin(cosAlpha, sinAlpha) *
             translate(-x, -y, -z);

    return r;
}

Mat4 rotatePivotZCosSin(float x,
                        float y,
                        float z,
                        float dx,
                        float dy,
                        float dz,
                        float cosTheta,
                        float sinTheta)
{
    float dyz = sqrt(dy*dy + dz*dz);
    float cosAlpha = dz / dyz;
    float sinAlpha = dy / dyz;
    float dxz = sqrt(dx*dx + dz*dz);
    float cosBeta = dz / dxz;
    float sinBeta = dx / dxz;

    Mat4 r = translate(x, y, z) *
             rotateXCosSin(cosAlpha, -sinAlpha) *
             rotateYCosSin(cosBeta, sinBeta) *
             rotateZCosSin(cosTheta, sinTheta) *
             rotateYCosSin(cosBeta, -sinBeta) *
             rotateXCosSin(cosAlpha, sinAlpha) *
             translate(-x, -y, -z);

    return r;
}

Mat4 rotateCosSin(float x,
                  float y,
                  float z,
                  float dx,
                  float dy,
                  float dz,
                  float cosTheta,
                  float sinTheta)
{
    int pivot = findPivotAxis(dx, dy, dz);
    Mat4 r;

    if (0 == pivot)
    {
        r = rotatePivotXCosSin(x, y, z, dx, dy, dz, cosTheta, sinTheta);
    }
    else if (1 == pivot)
    {
        r = rotatePivotYCosSin(x, y, z, dx, dy, dz, cosTheta, sinTheta);
    }
    else
    {
        r = rotatePivotZCosSin(x, y, z, dx, dy, dz, cosTheta, sinTheta);
    }

    return r;
}

Mat4 rotateRad(float x,
               float y,
               float z,
               float dx,
               float dy,
               float dz,
               float theta)
{
    return rotateCosSin(x, y, z, dx, dy, dz, cos(theta), sin(theta));
}

Mat4 rotateDegree(float x,
                  float y,
                  float z,
                  float dx,
                  float dy,
                  float dz,
                  float degree)
{
    return rotateRad(x, y, z, dx, dy, dz, rad(degree));
}

Mat4 scale(float sx,
           float sy,
           float sz)
{
    Mat4 m = identityMatrix<4>();
    m[0][0] = sx;
    m[1][1] = sy;
    m[2][2] = sz;

    return m;
}

} // end of namespace sharedlib

