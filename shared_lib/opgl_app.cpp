#include <stdexcept>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "opgl_app.h"

namespace opgl {

App::App(unsigned int width,
         unsigned int height,
         const char *title)
{
    setupWindow(width, height, title);
    initGLEW();
}

App::~App()
{
    if (!window_)
    {
        glfwTerminate();
    }
}

void App::run()
{
    while(running())
    {
        process();
        postProcess();
    }
}

void App::setupWindow(unsigned int width,
                      unsigned int height,
                      const char *title)
{
    initGLFW();
    setWindowHints();
    createWindow();
    makeContextCurrent();
    setupInputMode();
}

void App::initGLFW()
{
    if (!glfwInit())
    {
        throw std::runtime_error("glfwInit failed");
    }
}

void App::setWindowHints()
{
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void App::createWindow(unsigned int width,
                       unsigned int height,
                       const char *title)
{
    window_ = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window_)
    {
        throw std::runtime_error("glfwCreateWindow failed");
    }
}

void App::makeContextCurrent()
{
    glfwMakeContextCurrent(window_);
}

void App::setupInputMode()
{
    glfwSetInputMode(window_, GLFW_STICKY_KEYS, GL_TRUE);
}

void App::initGLEW()
{
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        throw std::runtime_error("glewInit failed");
    }
}

void App::postProcess()
{
    glfwSwapBuffers(window_);
    glfwPollEvents();
}

} // end of namespace opgl

