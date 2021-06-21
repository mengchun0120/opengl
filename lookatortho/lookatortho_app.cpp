#include <iostream>
#include <lookatortho_cube_generator.h>
#include <lookatortho_app.h>

namespace lookatortho {

std::shared_ptr<LookAtOrthoApp> LookAtOrthoApp::k_instance;

void LookAtOrthoApp::initInstance(const std::string& vertexShaderFile,
                                  const std::string& fragShaderFile)
{
    k_instance.reset(new LookAtOrthoApp(vertexShaderFile, fragShaderFile));
}

LookAtOrthoApp::LookAtOrthoApp(const std::string& vertexShaderFile,
                               const std::string& fragShaderFile):
    App(800, 800, "Model & Project Matrix Test"),
    program_(vertexShaderFile, fragShaderFile)
{
    using namespace sharedlib;

    setupViewport();
    setupCube();
    setupModelMatrix();
    setupProjMatrix();
    setupOpenGL();
    setupProgram();
}

LookAtOrthoApp::~LookAtOrthoApp()
{
}

void LookAtOrthoApp::process()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, va_.numVertices(0));
    glFlush();
}

void LookAtOrthoApp::setupViewport()
{
    int width, height;

    glfwGetFramebufferSize(window(), &width, &height);
    viewportWidth_ = static_cast<float>(width);
    viewportHeight_ = static_cast<float>(height);
}

void LookAtOrthoApp::setupCube()
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

//    CubeGenerator gen;
    gen_.generate(va_, 0.0f, 0.0f, 0.0f, 1.0f, colors);
}

void LookAtOrthoApp::setupModelMatrix()
{
    modelMatrix_ = sharedlib::lookAt(0.0f, 0.0f, 1.0f,
                                     0.0f, 0.0f, 0.0f,
                                     0.0f, 1.0f, 0.0f);
    std::cerr << "model matrix=" << modelMatrix_ << std::endl;
}

void LookAtOrthoApp::setupProjMatrix()
{
    projMatrix_ = sharedlib::ortho(-1.0f,
                                   1.0f,
                                   -1.0f,
                                   1.0f,
                                   0.0f,
                                   2.0f);
    std::cerr << "proj matrix=" << projMatrix_ << std::endl;
    sharedlib::Matrix4 m = projMatrix_ * modelMatrix_;
    std::cerr << "m=" << m << std::endl;
    for (std::size_t i = 0; i < gen_.vertexArray_.size(); ++i)
    {
        sharedlib::Point4 v = m * gen_.vertexArray_[i];
        std::cerr << i << ") original: " << gen_.vertexArray_[i] << std::endl;
        std::cerr << i << ") after: " << v << std::endl;
        std::cerr << std::endl;
    }
    //projMatrix_ = sharedlib::identityMatrix<4>();
}

void LookAtOrthoApp::setupOpenGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void LookAtOrthoApp::setupProgram()
{
    program_.use();
    program_.setPositionColor(va_);
    program_.setModelMatrix(modelMatrix_);
    program_.setProjMatrix(projMatrix_);
}

} // end of namespace lookatortho

