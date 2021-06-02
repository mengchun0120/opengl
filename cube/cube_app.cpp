#include <cube_app.h>

using namespace sharedlib;

namespace cube {

CubeApp::CubeApp(const std::string &vertexShaderFile,
                 const std::string &fragShaderFile)
    App(800, 800, "Rotate Cube")
{
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

