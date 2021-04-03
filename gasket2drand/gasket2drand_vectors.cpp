#include <random>
#include <iostream>
#include "sharedlib_my_exception.h"
#include "gasket2drand_vectors.h"

using namespace sharedlib;

namespace gasket2drand {

namespace {

unsigned int validate(unsigned int numPoints)
{
    if (numPoints < 1)
    {
        THROW_EXCEPT("numPoints is less than 1");
    }
    return numPoints;
}

Vec2 *generate(const std::array<Vec2, 3> &triangle,
               const Vec2 &initPoint,
               unsigned int numPoints)
{
    Vec2 *data = new Vec2[numPoints];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2);

    data[0] = initPoint;
    for (unsigned int k = 1; k < numPoints; ++k)
    {
        int j = distrib(gen);
        data[k] = (data[k-1] + triangle[j]) / 2.0f;
    }

    return data;
}

} // end of unnamed namespace

Gasket2DRandVectors::Gasket2DRandVectors(const std::array<Vec2, 3> &triangle,
                                         const Vec2 &initPoint,
                                         unsigned int numPoints):
    numPoints_(validate(numPoints)),
    data_(generate(triangle, initPoint, numPoints))
{
}

Gasket2DRandVectors::~Gasket2DRandVectors()
{
    delete[] data_;
}

} // end of namespace gasket2drand

