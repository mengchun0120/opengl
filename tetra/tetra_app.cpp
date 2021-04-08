#include "sharedlib_vector.h"
#include "tetra_app.h"

using namespace sharedlib;

namespace tetra {

namespace {

void addTriangle(Vec3 *positions,
                 Vec3 *colors,
                 const Vec3 &a,
                 const Vec3 &b,
                 const Vec3 &c,
                 const Vec3 &color)
{
    const Vec3 *vertices[] = {&a, &b, &c};
    for (int i = 0; i < 3; ++i, ++positions, ++colors)
    {
        *positions = *(vertices[i]);
        *colors = color;
    }
}

void addTetra(Vec3 *positions,
              Vec3 *colors,
              const Vec3 &a,
              const Vec3 &b,
              const Vec3 &c,
              const Vec3 &d,
              const Vec3 *baseColor)
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
    addTriangle(positions, colors, a, c, d, baseColor[3]);
}

void generateTetrahedron(VertexArray &va)
{
    constexpr int NUM_POINTS = 12;
    constexpr int VERTEX_SIZE = 3 * sizeof(float);
    Vec3 a{-1.0f, -1.0f, -1.0f};
    Vec3 b{1.0f, -1.0f, -1.0f};
    Vec3 c{0.0f, 1.0f, -1.0f};
    Vec3 d{0.0f, 0.0f, 1.0f};
    Vec3 baseColor[] = {
        Vec3{1.0f, 0.0f, 0.0f},
        Vec3{0.0f, 1.0f, 0.0f},
        Vec3{0.0f, 0.0f, 1.0f},
        Vec3{0.0f, 0.0f, 0.0f}
    };
    Vec3 positions[NUM_POINTS];
    Vec3 colors[NUM_POINTS];

    addTetra(positions, colors, a, b, c, d, baseColor);

    va.load({
        BufferBlock(positions, NUM_POINTS, VERTEX_SIZE, 0),
        BufferBlock(colors, NUM_POINTS, VERTEX_SIZE, 0)
    });
}

} // end of unnamed namespace

TetraApp::TetraApp(const std::string &vertexShaderFile,
                   const std::string &fragShaderFile):
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

