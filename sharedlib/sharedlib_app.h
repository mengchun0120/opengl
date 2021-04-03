#ifndef INCLUDE_OPGL_APP_H
#define INCLUDE_OPGL_APP_H

#include "sharedlib_opengl.h"

namespace sharedlib {

class App {
public:
    App(unsigned int width,
        unsigned int height,
        const char *title);

    virtual ~App();

    virtual void setup()
    {}

    void run();

    virtual void process()
    {}

private:
    void setupWindow(unsigned int width,
                     unsigned int height,
                     const char *title);

    void initGLFW();

    void setWindowHints();

    void createWindow(unsigned int width,
                      unsigned int height,
                      const char *title);

    void makeContextCurrent();

    void setupInputMode();

    void initGLEW();

    bool running()
    {
        return 0 == glfwWindowShouldClose(window_);
    }

    void postProcess();

private:
    GLFWwindow *window_;
};

} // end of namespace sharedlib

#endif

