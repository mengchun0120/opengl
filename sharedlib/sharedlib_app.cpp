#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "sharedlib_my_exception.h"
#include "sharedlib_app.h"

namespace sharedlib {

namespace {

void initGLFW()
{
    if (!glfwInit())
    {
        THROW_EXCEPT("glfwInit failed");
    }
}

void setWindowHints()
{
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow *createWindow(unsigned int width,
                         unsigned int height,
                         const char *title)
{
    GLFWwindow *window = glfwCreateWindow(width, height, title,
                                          nullptr, nullptr);
    if (!window)
    {
        THROW_EXCEPT("glfwCreateWindow failed");
    }

    return window;
}

void makeContextCurrent(GLFWwindow *window)
{
    glfwMakeContextCurrent(window);
}

void setupInputMode(GLFWwindow *window)
{
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

void initGLEW()
{
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        THROW_EXCEPT("glewInit failed");
    }
}

inline bool running(GLFWwindow *window)
{
    return 0 == glfwWindowShouldClose(window);
}

} // end of unnamed namespace

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
    while(running(window_))
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
    window_ = createWindow(width, height, title);
    makeContextCurrent(window_);
    setupInputMode(window_);
}

void App::postProcess()
{
    glfwSwapBuffers(window_);
    glfwPollEvents();
}

} // end of namespace sharedlib

