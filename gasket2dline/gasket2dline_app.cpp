#include "gasket2dline_vectors.h"
#include "gasket2dline_app.h"

using namespace sharedlib;

namespace gasket2dline {

namespace {

void generateGasket(VertexArray& vertices)
{
    constexpr unsigned int POINT_SIZE = 2 * sizeof(float);

    Vector2 a{0.0f, 1.0f};
    Vector2 b{-1.0f, -1.0f};
    Vector2 c{1.0f, -1.0f};
    unsigned int numDivisions = 5;

    Gasket2DLineVectors vectors(a, b, c, numDivisions);
    vertices.load(vectors.data(), vectors.numPoints(), POINT_SIZE);
}

} // end of unnamed namespace

Gasket2DLineApp::Gasket2DLineApp(const std::string& vertexShaderFile,
                                 const std::string& fragShaderFile):
    App(500, 500, "Gasket 2D Lines"),
    program_(vertexShaderFile, fragShaderFile)
{
    generateGasket(vertices_);
    setupProgram();
    setupOpenGL();
}

void Gasket2DLineApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT);
    program_.draw(vertices_);
    glFlush();
}

void Gasket2DLineApp::setupProgram()
{
    program_.use();
    program_.setPosition(vertices_);
}

void Gasket2DLineApp::setupOpenGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

} // end of namespace gasket2dline

