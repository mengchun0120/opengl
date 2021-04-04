#include <random>
#include "sharedlib_my_exception.h"
#include "gasket3drand_vectors.h"

using namespace sharedlib;

namespace gasket3drand {

namespace {

unsigned int validate(unsigned int numPoints)
{
    if (numPoints < 1)
    {
        THROW_EXCEPT("numPoints is less than 1");
    }
    return numPoints;
}

Vec3 *generate(const std::array<Vec3, 4> &tetrahedron,
               const Vec3 &initPoint,
               unsigned int numPoints)
{
    Vec3 *data = new Vec3[numPoints];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 3);

    data[0] = initPoint;
    for (unsigned int k = 1; k < numPoints; ++k)
    {
        int j = distrib(gen);
        data[k] = (data[k-1] + tetrahedron[j]) / 2.0f;
    }

    return data;
}

} // end of unnamed namespace

Gasket3DRandVectors::Gasket3DRandVectors(const std::array<Vec3, 4> &tetrahedron,
                                         const Vec3 &initPoint,
                                         unsigned int numPoints):
    numPoints_(validate(numPoints)),
    data_(generate(tetrahedron, initPoint, numPoints))
{
}

Gasket3DRandVectors::~Gasket3DRandVectors()
{
    delete[] data_;
}

} // end of namespace gasket3drand

