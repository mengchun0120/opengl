#include "sharedlib_my_exception.h"
#include "sharedlib_vertex_array.h"
#include "gasket3dline_generator.h"

using namespace sharedlib;

namespace gasket3dline {

namespace {

unsigned int getNumPoints(unsigned int numDivisions)
{
    constexpr unsigned int MULTIPLIER_PER_DIVISION = 4;
    unsigned int numPoints = 12;

    for (unsigned int k = 0; k < numDivisions; ++k)
    {
        numPoints *= MULTIPLIER_PER_DIVISION;
    }

    return numPoints;
}

} // end of unnamed namespace

class Result {
public:
    Result(unsigned int numPoints);

    ~Result();

    void addTetrahedron(const Vector3& a,
                        const Vector3& b,
                        const Vector3& c,
                        const Vector3& d,
                        const std::array<Vector3, 4>& colors);

    const Vector3 *positions() const
    {
        return positions_;
    }

    const Vector3 *colors() const
    {
        return colors_;
    }

private:
    void addTriangle(const Vector3& a,
                     const Vector3& b,
                     const Vector3& c,
                     const Vector3& color);
private:
    Vector3 *positions_;
    Vector3 *colors_;
    unsigned int index_;
};

Result::Result(unsigned int numPoints):
    positions_(new Vector3[numPoints]),
    colors_(new Vector3[numPoints]),
    index_(0)
{
}

Result::~Result()
{
    delete[] positions_;
    delete[] colors_;
}

void Result::addTetrahedron(const Vector3& a,
                            const Vector3& b,
                            const Vector3& c,
                            const Vector3& d,
                            const std::array<Vector3, 4>& colors)
{
    addTriangle(a, b, c, colors[0]);
    addTriangle(a, b, d, colors[1]);
    addTriangle(a, c, d, colors[2]);
    addTriangle(b, c, d, colors[3]);
}

void Result::addTriangle(const Vector3& a,
                         const Vector3& b,
                         const Vector3& c,
                         const Vector3& color)
{
    const Vector3* vertices[] = {&a,& b,& c};
    for (int i = 0; i < 3; ++i, ++index_)
    {
        positions_[index_] = *(vertices[i]);
        colors_[index_] = color;
    }
}

void generateImpl(Result& result,
                  const Vector3& a,
                  const Vector3& b,
                  const Vector3& c,
                  const Vector3& d,
                  const std::array<Vector3, 4>& colors,
                  unsigned int numDivisions)
{
    if (numDivisions > 0)
    {
        Vector3 abMid = (a + b) / 2.0f;
        Vector3 acMid = (a + c) / 2.0f;
        Vector3 adMid = (a + d) / 2.0f;
        Vector3 bcMid = (b + c) / 2.0f;
        Vector3 bdMid = (b + d) / 2.0f;
        Vector3 cdMid = (c + d) / 2.0f;
        generateImpl(result, a, abMid, acMid, adMid, colors, numDivisions - 1);
        generateImpl(result, abMid, b, bcMid, bdMid, colors, numDivisions - 1);
        generateImpl(result, acMid, bcMid, c, cdMid, colors, numDivisions - 1);
        generateImpl(result, adMid, bdMid, cdMid, d, colors, numDivisions - 1);
    }
    else
    {
        result.addTetrahedron(a, b, c, d, colors);
    }
}

void Gasket3DLineGenerator::generate(VertexArray& va,
                                     const std::array<Vector3, 4>& tetrahedron,
                                     const std::array<Vector3, 4>& colors,
                                     unsigned int numDivisions)
{
    const unsigned int numPoints = getNumPoints(numDivisions);
    Result result(numPoints);

    generateImpl(result, tetrahedron[0], tetrahedron[1],
                 tetrahedron[2], tetrahedron[3], colors, numDivisions);

    constexpr unsigned int vertexSize = 3 * sizeof(float);
    va.load({
        BufferBlock(result.positions(), numPoints, vertexSize, 0),
        BufferBlock(result.colors(), numPoints, vertexSize, 0)
    });
}

} // end of namespace gasket3dline

