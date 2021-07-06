#include <iostream>
#include <gtest/gtest.h>
#include <sharedlib_math_utils.h>
#include <sprlgt_sphere_generator.h>

bool verifySphere(const std::vector<sharedlib::Vector3>& vertices,
                  const std::vector<sharedlib::Vector3>& normals,
                  float centerX,
                  float centerY,
                  float centerZ,
                  float radius)
{
    using namespace std;
    using namespace sharedlib;

    Vector3 center{centerX, centerY, centerZ};

    for (size_t i = 0; i < vertices.size(); ++i)
    {
        float d = dist(center, vertices[i]);
        if (!fuzzyEqual(d, radius))
        {
            cerr << "Distance from vertices[" << i << "] " << vertices[i]
                 << " to center " << center << " != " << radius << endl;
            return false;
        }

        if (!fuzzyEqual(normals[i].norm(), 1.0f))
        {
            cerr << "The norm of normals[" << i << "] " << normals[i]
                 << " is not of unit length" << endl;
            return false;
        }

        Vector3 n = normalize(vertices[i] - center);
        if (!fuzzyEqual(n, normals[i]))
        {
            cerr << "The normal vector at vertices[" << i << "] " << vertices[i]
                 << " doesn't match normals[" << i << "]" << endl;
            return false;
        }
    }

    return true;
}

TEST(TestSphereGenerator, TestRecursiveSphereGenerator)
{
    using namespace sprlgt;
    using namespace sharedlib;

    RecursiveSphereGenerator g;
    std::vector<Vector3> vertices, normals;
    float centerX = 1.0f;
    float centerY = 2.0f;
    float centerZ = 3.0f;
    float radius = 5.0f;

    g.generate(vertices, normals, centerX, centerY, centerZ, radius);
    ASSERT_TRUE(verifySphere(vertices, normals, centerX, centerY, centerZ, radius));
}

