#include "sharedlib_opengl.h"
#include "gasket3drand_vectors.h"
#include "gasket3drand_app.h"

using namespace sharedlib;

namespace gasket3drand {

namespace {

void generateGasket(VertexArray &vertices)
{
    constexpr unsigned int POINT_SIZE = 3 * sizeof(float);

    std::array<Vec3, 4> tetrahedron{
        Vec3{-1.0f, -1.0f, -1.0f},
        Vec3{1.0f, -1.0f, -1.0f},
        Vec3{0.0f, 1.0f, -1.0f},
        Vec3{0.0f, 0.0f, 1.0f}
    };
    Vec3 initPoint{0.0f, 0.0f, 0.0f};
    Gasket3DRandVectors points(tetrahedron, initPoint, 5000);

    vertices.load(points.data(), points.numPoints(), POINT_SIZE);
}

} // end of unnamed namespace

Gasket3DRandApp::Gasket3DRandApp(const std::string &vertexShaderFile,
                                 const std::string &fragShaderFile):
    App(500, 500, "Gasket 2D Random Points"),
    program_(vertexShaderFile, fragShaderFile)
{
    generateGasket(vertices_);
    setupProgram();
    setupOpenGL();
}

void Gasket3DRandApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT);
    program_.draw(vertices_);
    glFlush();
}

void Gasket3DRandApp::setupProgram()
{
    program_.setPosition(vertices_);
    program_.use();
}

void Gasket3DRandApp::setupOpenGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

} // end of namespace gasket3drand

