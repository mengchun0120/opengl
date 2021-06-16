#include "gasket3dline_generator.h"
#include "gasket3dline_app.h"

using namespace sharedlib;

namespace gasket3dline {

namespace {

void generateGasket(VertexArray& va)
{
    std::array<Vector3, 4> tetrahedron{
        Vector3{-1.0f, -1.0f, 1.0f},
        Vector3{1.0f, -1.0f, 1.0f},
        Vector3{0.0f, 1.0f, 1.0f},
        Vector3{0.0f, 0.0f, -1.0f}
    };
    std::array<Vector3, 4> colors{
        Vector3{1.0f, 0.0f, 0.0f},
        Vector3{0.0f, 1.0f, 0.0f},
        Vector3{0.0f, 0.0f, 1.0f},
        Vector3{1.0f, 1.0f, 0.0f}
    };
    constexpr unsigned int numDivisions = 2;

    Gasket3DLineGenerator::generate(va, tetrahedron, colors, numDivisions);
}

} // end of unnamed namespace

Gasket3DLineApp::Gasket3DLineApp(const std::string& vertexShaderFile,
                                 const std::string& fragShaderFile):
    App(500, 500, "Gasket 3D Triangles"),
    program_(vertexShaderFile, fragShaderFile)
{
    generateGasket(va_);
    setupProgram();
    setupOpenGL();
}

void Gasket3DLineApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, va_.numVertices(0));
    glFlush();
}

void Gasket3DLineApp::setupProgram()
{
    program_.use();
    program_.setPositionColor(va_);
}

void Gasket3DLineApp::setupOpenGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

} // end of namespace gasket3dline

