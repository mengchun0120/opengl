#include <cube_cube_generator.h>
#include <cube_app.h>

namespace cube {

namespace {

void generateCube(sharedlib::VertexArray &va)
{
    using namespace sharedlib;

    std::array<Point4, 8> vertices{
        Point4{-0.5f, 0.5f, 0.5f, 1.0f},
        Point4{0.5f, 0.5f, 0.5f, 1.0f},
        Point4{0.5f, 0.5f, -0.5f, 1.0f},
        Point4{-0.5f, 0.5f, -0.5f, 1.0f},
        Point4{-0.5f, -0.5f, 0.5f, 1.0f},
        Point4{0.5f, -0.5f, 0.5f, 1.0f},
        Point4{0.5f, -0.5f, -0.5f, 1.0f},
        Point4{-0.5f, -0.5f, -0.5f, 1.0f}
    };

    std::array<Color, 6> colors{
        Color{1.0f, 0.0f, 0.0f, 1.0f},
        Color{0.0f, 1.0f, 0.0f, 1.0f},
        Color{0.0f, 0.0f, 1.0f, 1.0f},
        Color{1.0f, 1.0f, 0.0f, 1.0f},
        Color{1.0f, 0.0f, 1.0f, 1.0f},
        Color{0.0f, 1.0f, 1.0f, 1.0f}
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
                 const std::string &fragShaderFile):
    App(800, 800, "Rotate Cube"),
    program_(vertexShaderFile, fragShaderFile)
{
    generateCube(va_);
    rotateMatrix_ = sharedlib::identityMatrix<4>();
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
    program_.setPositionColor(va_);
    program_.setRotateMatrix(rotateMatrix_);
}

void CubeApp::setupOpenGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

} // end of namespace cube

