#ifndef INCLUDE_OPGL_APP_H
#define INCLUDE_OPGL_APP_H

#include <string>
#include "sharedlib_opengl.h"

namespace sharedlib {

class App {
public:
    App(unsigned int width,
        unsigned int height,
        const std::string& title);

    virtual ~App();

    void run();

    virtual void process()
    {}

    GLFWwindow *window() const
    {
        return window_;
    }

private:
    void setupWindow(unsigned int width,
                     unsigned int height,
                     const char *title);

    void postProcess();

private:
    GLFWwindow *window_;
};

} // end of namespace sharedlib

#endif

