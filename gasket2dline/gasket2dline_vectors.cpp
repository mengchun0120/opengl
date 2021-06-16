#include <utility>
#include "sharedlib_my_exception.h"
#include "gasket2dline_vectors.h"

using namespace sharedlib;

namespace gasket2dline {

namespace {

void validate(unsigned int numDivisions)
{
    if (numDivisions < 1)
    {
        THROW_EXCEPT("numDivisions is less than 1");
    }
}

unsigned int getNumPoints(unsigned int numDivisions)
{
    unsigned int numPoints = 1;

    for (unsigned int k = 0; k <= numDivisions; ++k)
    {
        numPoints *= 3;
    }

    return numPoints;
}

void divide(Vector2*& points,
            const Vector2& a,
            const Vector2& b,
            const Vector2& c,
            unsigned int numDivisions)
{
    if (numDivisions > 0)
    {
        Vector2 a1 = (a + b) / 2.0f;
        Vector2 b1 = (b + c) / 2.0f;
        Vector2 c1 = (c + a) / 2.0f;
        divide(points, a, a1, c1, numDivisions-1);
        divide(points, a1, b, b1, numDivisions-1);
        divide(points, c1, b1, c, numDivisions-1);
    }
    else
    {
        *(points++) = a;
        *(points++) = b;
        *(points++) = c;
    }
}

std::pair<Vector2*, unsigned int> generate(const Vector2& a,
                                           const Vector2& b,
                                           const Vector2& c,
                                           unsigned int numDivisions)
{
    unsigned int numPoints = getNumPoints(numDivisions);
    Vector2* resultPoints = new Vector2[numPoints];
    Vector2* points = resultPoints;

    divide(points, a, b, c, numDivisions);

    return std::make_pair(resultPoints, numPoints);
}

} // end of unnamed namespace

Gasket2DLineVectors::Gasket2DLineVectors(const Vector2& a,
                                         const Vector2& b,
                                         const Vector2& c,
                                         unsigned int numDivisions):
    numPoints_(0),
    data_(nullptr)
{
    validate(numDivisions);
    auto result = generate(a, b, c, numDivisions);
    data_ = result.first;
    numPoints_ = result.second;
}

Gasket2DLineVectors::~Gasket2DLineVectors()
{
    delete[] data_;
}

} // end of namespace gasket2dline

