#include "sharedlib_vector.h"
#include "tetra_app.h"

using namespace sharedlib;

namespace tetra {

namespace {

void addTriangle(Vector3* positions,
                 Vector3* colors,
                 const Vector3& a,
                 const Vector3& b,
                 const Vector3& c,
                 const Vector3& color)
{
    const Vector3 *vertices[] = {&a,& b,& c};
    for (int i = 0; i < 3; ++i, ++positions, ++colors)
    {
        *positions = *(vertices[i]);
        *colors = color;
    }
}

void addTetra(Vector3* positions,
              Vector3* colors,
              const Vector3& a,
              const Vector3& b,
              const Vector3& c,
              const Vector3& d,
              const Vector3* baseColor)
{
    addTriangle(positions, colors, a, b, c, baseColor[0]);
    positions += 3;
    colors += 3;
    addTriangle(positions, colors, a, b, d, baseColor[1]);
    positions += 3;
    colors += 3;
    addTriangle(positions, colors, a, c, d, baseColor[2]);
    positions += 3;
    colors += 3;
    addTriangle(positions, colors, b, c, d, baseColor[3]);
}

void generateTetrahedron(VertexArray& va)
{
    constexpr int NUM_POINTS = 12;
    constexpr int VERTEX_SIZE = 3 * sizeof(float);
    Vector3 a{-1.0f, -1.0f, 1.0f};
    Vector3 b{1.0f, -1.0f, 1.0f};
    Vector3 c{0.0f, 1.0f, 1.0f};
    Vector3 d{0.0f, 0.0f, -1.0f};
    Vector3 baseColor[] = {
        Vector3{1.0f, 0.0f, 0.0f},
        Vector3{0.0f, 1.0f, 0.0f},
        Vector3{0.0f, 0.0f, 1.0f},
        Vector3{1.0f, 1.0f, 0.0f}
    };
    Vector3 positions[NUM_POINTS];
    Vector3 colors[NUM_POINTS];

    addTetra(positions, colors, a, b, c, d, baseColor);

    va.load({
        BufferBlock(positions, NUM_POINTS, VERTEX_SIZE, 0),
        BufferBlock(colors, NUM_POINTS, VERTEX_SIZE, 0)
    });
}

} // end of unnamed namespace

TetraApp::TetraApp(const std::string& vertexShaderFile,
                   const std::string& fragShaderFile):
    App(500, 500, "Tetrahedron"),
    program_(vertexShaderFile, fragShaderFile)
{
    generateTetrahedron(va_);
    setupProgram();
    setupOpenGL();
}

void TetraApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, va_.numVertices(0));
    glFlush();
}

void TetraApp::setupProgram()
{
    program_.use();
    program_.setPositionColor(va_);
}

void TetraApp::setupOpenGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

} // end of namespace tetra

