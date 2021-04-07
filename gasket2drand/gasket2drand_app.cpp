#include <iostream>
#include "sharedlib_opengl.h"
#include "gasket2drand_vectors.h"
#include "gasket2drand_app.h"

using namespace sharedlib;
using namespace std;

namespace gasket2drand {

namespace {

void generateGasket(VertexArray &vertices)
{
    constexpr unsigned int POINT_SIZE = 2 * sizeof(float);

    std::array<Vec2, 3> triangle{
        Vec2{-1.0f, -1.0f},
        Vec2{0.0f, 1.0f},
        Vec2{1.0f, -1.0f}
    };
    Vec2 initPoint{0.25f, 0.5f};
    Gasket2DRandVectors points(triangle, initPoint, 5000);

    vertices.load(points.data(), points.numPoints(), POINT_SIZE);
}

} // end of unnamed namespace

Gasket2DRandApp::Gasket2DRandApp(const std::string &vertexShaderFile,
                                 const std::string &fragShaderFile):
    App(500, 500, "Gasket 2D Random Points"),
    program_(vertexShaderFile, fragShaderFile)
{
    generateGasket(vertices_);
    setupProgram();
    setupOpenGL();
}

void Gasket2DRandApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT);
    program_.draw(vertices_);
}

void Gasket2DRandApp::setupProgram()
{
    program_.setPosition(vertices_);
    program_.use();
}

void Gasket2DRandApp::setupOpenGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

} // end of namespace gasket2drand

