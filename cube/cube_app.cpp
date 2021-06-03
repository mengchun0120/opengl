#include <cube_cube_generator.h>
#include <cube_app.h>

using namespace sharedlib;

namespace cube {

namespace {

void generateCube(VertexArray &va)
{
    std::array<Point4, 8> vertices{
        Point4(-0.5f, 0.5f, 0.5f, 1.0f),
        Point4(0.5f, 0.5f, 0.5f, 1.0f),
        Point4(0.5f, 0.5f, -0.5f, 1.0f),
        Point4(-0.5f, 0.5f, -0.5f, 1.0f),
        Point4(-0.5f, -0.5f, 0.5f, 1.0f),
        Point4(0.5f, -0.5f, 0.5f, 1.0f),
        Point4(0.5f, -0.5f, -0.5f, 1.0f),
        Point4(-0.5f, -0.5f, -0.5f, 1.0f)
    };

    std::array<Color, 6> colors{
        Color(1.0f, 0.0f, 0.0f, 1.0f),
        Color(0.0f, 1.0f, 0.0f, 1.0f),
        Color(0.0f, 0.0f, 1.0f, 1.0f),
        Color(1.0f, 1.0f, 0.0f, 1.0f),
        Color(1.0f, 0.0f, 1.0f, 1.0f),
        Color(0.0f, 1.0f, 1.0f, 1.0f)
    };

    CubeGenerator gen;
    gen.generate(va, vertices, colors);
}

} // end of unnamed namespace

std::shared_ptr<CubeApp> CubeApp::k_instance;

void CubeApp::initInstance(const std::string &vertexShaderFile,
                           const std::string &fragShaderFile)
{
    k_instance.reset(new CubeApp(vertexShaderFile, fragShaderFile));
}

CubeApp::CubeApp(const std::string &vertexShaderFile,
                 const std::string &fragShaderFile)
    App(800, 800, "Rotate Cube"),
    program_(vertexShaderFile, fragShaderFile)
{
    generateCube(va_);
    rotateMatrix_ = identityMatrix();
    setupProgram();
    setupOpenGL();
}

void CubeApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, va_.numVertices(0));
    glFlush();
}

void CubeApp::setupProgram()
{
    program_.use();
}

void CubeApp::setupOpenGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

} // end of namespace cube

