#include <iostream>
#include <cmath>
#include <sharedlib_math_utils.h>
#include <sharedlib_random_utils.h>
#include <lookatortho_cube_generator.h>
#include <lookatortho_app.h>

namespace lookatortho {

std::shared_ptr<LookAtOrthoApp> LookAtOrthoApp::k_instance;

void LookAtOrthoApp::initInstance(const std::string& vertexShaderFile,
                                  const std::string& fragShaderFile)
{
    k_instance.reset(new LookAtOrthoApp(vertexShaderFile, fragShaderFile));
}

void LookAtOrthoApp::onKey(GLFWwindow* window,
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

LookAtOrthoApp::LookAtOrthoApp(const std::string& vertexShaderFile,
                               const std::string& fragShaderFile):
    App(800, 800, "Model & Project Matrix Test"),
    program_(vertexShaderFile, fragShaderFile),
    eyeRadius_{400.0f},
    eyePhi_{90.0f},
    eyeTheta_{0.0f},
    eyeDistX_{0.0f},
    eyeDistZ_{0.0f},
    at_{0.0f, 0.0f, 0.0f},
    up_{0.0f, 1.0f, 0.0f}
{
    using namespace sharedlib;

    setupViewport();
    setupCubes();
    setupOpenGL();
    setupProgram();
    setupModelMatrix();
    setupProjMatrix();
    setupInput();
}

LookAtOrthoApp::~LookAtOrthoApp()
{
    glfwSetKeyCallback(window(), nullptr);
}

void LookAtOrthoApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (std::size_t i = 0; i < NUM_CUBES; ++i)
    {
        program_.setPositionColor(cubes_[i]);
        glDrawArrays(GL_TRIANGLES, 0, cubes_[i].numVertices(0));
    }

    glFlush();
}

void LookAtOrthoApp::setupViewport()
{
    int width, height;

    glfwGetFramebufferSize(window(), &width, &height);
    viewportWidth_ = static_cast<float>(width);
    viewportHeight_ = static_cast<float>(height);
}

void LookAtOrthoApp::setupCubes()
{
    using namespace sharedlib;

    std::array<Color, 6> colors{
        Color{1.0f, 0.0f, 0.0f, 1.0f},
        Color{0.0f, 1.0f, 0.0f, 1.0f},
        Color{0.0f, 0.0f, 1.0f, 1.0f},
        Color{1.0f, 1.0f, 0.0f, 1.0f},
        Color{1.0f, 0.0f, 1.0f, 1.0f},
        Color{0.0f, 1.0f, 1.0f, 1.0f}
    };

    Point3 centers[NUM_CUBES] = {
        Point3{-250.0f, 0.0f, 100.0f},
        Point3{250.0f, 0.0f, 100.0f},
        Point3{-100.0f, 0.0f, -100.0f},
        Point3{100.0f, 0.0f, -80.0f}
    };

    constexpr float LENGTH = 100.0f;

    CubeGenerator gen;
    for (std::size_t i = 0; i < NUM_CUBES; ++i)
    {
        shuffle(colors);
        gen.generate(cubes_[i], centers[i], LENGTH, colors);
    }
}

void LookAtOrthoApp::setupModelMatrix()
{
    using namespace sharedlib;

    float phi = rad(eyePhi_);
    float theta = rad(eyeTheta_);
    float r = eyeRadius_ * sin(phi);

    eye_[0] = eyeDistX_ + r * sin(theta);
    eye_[2] = eyeDistZ_ + r * cos(theta);
    eye_[1] = eyeRadius_ * cos(phi);
    at_[0] = eyeDistX_;
    at_[2] = eyeDistZ_;

    modelMatrix_ = lookAt(eye_, at_, up_);

    program_.setModelMatrix(modelMatrix_);
}

void LookAtOrthoApp::setupProjMatrix()
{
    projMatrix_ = sharedlib::ortho(-viewportWidth_/2.0f, viewportWidth_/2.0f,
                                   -viewportHeight_/2.0f, viewportHeight_/2.0f,
                                   0.0f, 1000.0f);
    program_.setProjMatrix(projMatrix_);
}

void LookAtOrthoApp::setupOpenGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void LookAtOrthoApp::setupProgram()
{
    program_.use();
}

void LookAtOrthoApp::setupInput()
{
    glfwSetKeyCallback(window(), onKey);
}

void LookAtOrthoApp::handleKey(GLFWwindow* window,
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
            rotateEyeX(!(mods & GLFW_MOD_SHIFT));
            break;
        case GLFW_KEY_Y:
            rotateEyeY(!(mods & GLFW_MOD_SHIFT));
            break;
        case GLFW_KEY_A:
            moveEyeLeft();
            break;
        case GLFW_KEY_D:
            moveEyeRight();
            break;
        case GLFW_KEY_W:
            moveEyeForward();
            break;
        case GLFW_KEY_S:
            moveEyeBackward();
            break;
        default:
            return;
    }
}

void LookAtOrthoApp::rotateEyeX(bool forward)
{
    constexpr float INCR = 5.0f;
    constexpr float MAX = 90.0f;
    constexpr float MIN = -90.0f;

    if (forward)
    {
        eyePhi_ += INCR;
    }
    else
    {
        eyePhi_ -= INCR;
    }

    eyePhi_ = sharedlib::clamp(eyePhi_, MIN, MAX);
    setupModelMatrix();
}

void LookAtOrthoApp::rotateEyeY(bool forward)
{
    constexpr float INCR = 5.0f;
    constexpr float MAX = 90.0f;
    constexpr float MIN = -90.0f;

    if (forward)
    {
        eyeTheta_ += INCR;
    }
    else
    {
        eyeTheta_ -= INCR;
    }

    eyeTheta_ = sharedlib::clamp(eyeTheta_, MIN, MAX);
    setupModelMatrix();
}

void LookAtOrthoApp::moveEyeLeft()
{
    constexpr float DELTA = 10.0f;
    constexpr float MIN = -400.0f;

    eyeDistX_ = std::max(eyeDistX_-DELTA, MIN);
    setupModelMatrix();
}

void LookAtOrthoApp::moveEyeRight()
{
    constexpr float DELTA = 10.0f;
    constexpr float MAX = 400.0f;

    eyeDistX_ = std::min(eyeDistX_+DELTA, MAX);
    setupModelMatrix();
}

void LookAtOrthoApp::moveEyeForward()
{
    constexpr float DELTA = 10.0f;
    constexpr float MIN = -400.0f;

    eyeDistZ_ = std::max(eyeDistZ_-DELTA, MIN);
    setupModelMatrix();
}

void LookAtOrthoApp::moveEyeBackward()
{
    constexpr float DELTA = 10.0f;
    constexpr float MAX = 400.0f;

    eyeDistZ_ = std::min(eyeDistZ_+DELTA, MAX);
    setupModelMatrix();
}

} // end of namespace lookatortho

