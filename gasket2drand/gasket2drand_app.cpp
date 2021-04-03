#include <iostream>
#include "sharedlib_opengl.h"
#include "gasket2drand_vectors.h"
#include "gasket2drand_app.h"

using namespace sharedlib;

namespace gasket2drand {

namespace {

void generateGasket(VertexArray &vertices)
{
    std::array<Vec2, 3> triangle{
        Vec2{-1.0f, -1.0f},
        Vec2{0.0f, 1.0f},
        Vec2{1.0f, -1.0f}
    };
    Vec2 initPoint{0.25f, 0.5f};
    Gasket2DRandVectors points(triangle, initPoint, 5000);

    vertices.load(points.data(), points.numPoints(), 2 * sizeof(float));
}

} // end of unnamed namespace

Gasket2DRandApp::Gasket2DRandApp(const std::string &vertexShaderFile,
                                 const std::string &fragShaderFile):
    App(500, 500, "Gasket 2D Random Points"),
    program_(vertexShaderFile, fragShaderFile)
{
    program_.use();
    generateGasket(vertices_);
}

void Gasket2DRandApp::setup()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    program_.setPosition(vertices_);
}

void Gasket2DRandApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT);
    program_.draw(vertices_);
}

} // end of namespace gasket2drand

