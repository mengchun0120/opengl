#include <iostream>
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

void CubeApp::onKey(GLFWwindow *window,
                    int key,
                    int scanCode,
                    int action,
                    int mods)
{
    if (k_instance)
    {
        k_instance->handleKey(window, key, scanCode, action, mods);
    }
}

CubeApp::CubeApp(const std::string &vertexShaderFile,
                 const std::string &fragShaderFile):
    App(800, 800, "Rotate Cube"),
    program_(vertexShaderFile, fragShaderFile),
    rotateForwardMatrixX_(sharedlib::rotateXDegree(5.0f)),
    rotateForwardMatrixY_(sharedlib::rotateYDegree(5.0f)),
    rotateForwardMatrixZ_(sharedlib::rotateZDegree(5.0f)),
    rotateBackwardMatrixX_(sharedlib::rotateXDegree(-5.0f)),
    rotateBackwardMatrixY_(sharedlib::rotateYDegree(-5.0f)),
    rotateBackwardMatrixZ_(sharedlib::rotateZDegree(-5.0f)),
    rotateMatrixX_(sharedlib::identityMatrix<4>()),
    rotateMatrixY_(sharedlib::identityMatrix<4>()),
    rotateMatrixZ_(sharedlib::identityMatrix<4>())
{
    generateCube(va_);
    setupInput();
    setupProgram();
    setupOpenGL();
}

CubeApp::~CubeApp()
{
    glfwSetKeyCallback(window(), nullptr);
}

void CubeApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, va_.numVertices(0));
    glFlush();
}

void CubeApp::setupInput()
{
    glfwSetKeyCallback(window(), onKey);
}

void CubeApp::setupProgram()
{
    program_.use();
    program_.setPositionColor(va_);
    program_.setRotateMatrixX(rotateMatrixX_);
    program_.setRotateMatrixY(rotateMatrixY_);
    program_.setRotateMatrixZ(rotateMatrixZ_);
}

void CubeApp::setupOpenGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void CubeApp::handleKey(GLFWwindow *window,
                        int key,
                        int scanCode,
                        int action,
                        int mods)
{
    if (action != GLFW_PRESS)
    {
        return;
    }

    switch (key)
    {
        case GLFW_KEY_X:
            rotateX(!(mods & GLFW_MOD_SHIFT));
            break;
        case GLFW_KEY_Y:
            rotateY(!(mods & GLFW_MOD_SHIFT));
            break;
        case GLFW_KEY_Z:
            rotateZ(!(mods & GLFW_MOD_SHIFT));
            break;
        default:
            return;
    }
}

void CubeApp::rotateX(bool forward)
{
    sharedlib::Mat4 &matrix = forward ?
                                  rotateForwardMatrixX_ :
                                  rotateBackwardMatrixX_;
    rotateMatrixX_ = sharedlib::operator*(matrix, rotateMatrixX_);
    program_.setRotateMatrixX(rotateMatrixX_);
}

void CubeApp::rotateY(bool forward)
{
    sharedlib::Mat4 &matrix = forward ?
                                  rotateForwardMatrixY_ :
                                  rotateBackwardMatrixY_;
    rotateMatrixY_ = sharedlib::operator*(matrix, rotateMatrixY_);
    program_.setRotateMatrixY(rotateMatrixY_);
}

void CubeApp::rotateZ(bool forward)
{
    sharedlib::Mat4 &matrix = forward ?
                                  rotateForwardMatrixZ_ :
                                  rotateBackwardMatrixZ_;
    rotateMatrixZ_ = sharedlib::operator*(matrix, rotateMatrixZ_);
    program_.setRotateMatrixZ(rotateMatrixZ_);
}

} // end of namespace cube

