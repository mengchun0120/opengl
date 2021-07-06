#include <cmath>
#include <list>
#include <sharedlib_my_exception.h>
#include <sprlgt_sphere_generator.h>

namespace sprlgt {

namespace {

void divideTriangle(std::list<sharedlib::Vector3>& vertexList,
                    const sharedlib::Vector3& a,
                    const sharedlib::Vector3& b,
                    const sharedlib::Vector3& c,
                    unsigned int steps)
{
    using namespace sharedlib;

    if (steps > 0)
    {
        sharedlib::Vector3 a1 = (a + b) / 2.0f;
        sharedlib::Vector3 b1 = (b + c) / 2.0f;
        sharedlib::Vector3 c1 = (a + c) / 2.0f;

        divideTriangle(vertexList, a, a1, c1, steps-1);
        divideTriangle(vertexList, a1, b, b1, steps-1);
        divideTriangle(vertexList, a1, b1, c1, steps-1);
        divideTriangle(vertexList, c1, b1, c, steps-1);
    }
    else
    {
        vertexList.push_back(normalize(a));
        vertexList.push_back(normalize(b));
        vertexList.push_back(normalize(c));
    }
}

void createUnitSphere(std::vector<sharedlib::Vector3>& vertices,
                      unsigned int steps)
{
    using namespace sharedlib;

    static const Vector3 tetra[] = {
        Vector3{0.0f, 1.0f, 0.0f},
        Vector3{-static_cast<float>(sqrt(6.0)/3.0),
                -1.0f/3.0f,
                static_cast<float>(sqrt(2.0)/3.0)},
        Vector3{static_cast<float>(sqrt(6.0)/3.0),
                -1.0f/3.0f,
                static_cast<float>(sqrt(2.0)/3.0)},
        Vector3{0.0f,
                -1.0f/3.0f,
                -static_cast<float>(2.0*sqrt(2.0)/3.0)}
    };
    std::list<Vector3> vertexList;

    divideTriangle(vertexList, tetra[0], tetra[1], tetra[2], steps);
    divideTriangle(vertexList, tetra[0], tetra[3], tetra[1], steps);
    divideTriangle(vertexList, tetra[0], tetra[2], tetra[3], steps);
    divideTriangle(vertexList, tetra[1], tetra[3], tetra[2], steps);

    vertices.reserve(vertexList.size());
    for (auto it = vertexList.begin(); it != vertexList.end(); ++it)
    {
        vertices.push_back(*it);
    }
}

void createSphereFromUnitSphere(std::vector<sharedlib::Vector3>& vertices,
                                const std::vector<sharedlib::Vector3>& unitVertices,
                                float centerX,
                                float centerY,
                                float centerZ,
                                float radius)
{
    using namespace sharedlib;

    Vector3 center{centerX, centerY, centerZ};

    vertices.reserve(unitVertices.size());
    for (std::size_t i = 0; i < unitVertices.size(); ++i)
    {
        vertices[i] = center + unitVertices[i] * radius;
    }
}

} // end of nunamed namespace

RecursiveSphereGenerator::RecursiveSphereGenerator(unsigned int numSteps) noexcept
{
    setNumSteps(numSteps);
}

void RecursiveSphereGenerator::generate(std::vector<sharedlib::Vector3>& vertices,
                                        std::vector<sharedlib::Vector3>& normals,
                                        float centerX,
                                        float centerY,
                                        float centerZ,
                                        float radius)
{
    createUnitSphere(normals, numSteps_);
    createSphereFromUnitSphere(vertices, normals, centerX, centerY, centerZ, radius);
}

void RecursiveSphereGenerator::setNumSteps(unsigned int numSteps)
{
    if (numSteps == 0)
    {
        THROW_EXCEPT("Invalid numSteps");
    }

    numSteps_ = numSteps;
}

} // end of namespace sprlgt

