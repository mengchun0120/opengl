#ifndef INCLUDE_LOOKATORTHO_APP_H
#define INCLUDE_LOOKATORTHO_APP_H

#include <memory>
#include <sharedlib_app.h>
#include <lookatortho_program.h>

namespace lookatortho {

class LookAtOrthoApp: public sharedlib::App {
public:
    static void initInstance(const std::string& vertexShaderFile,
                             const std::string& fragShaderFile);

    static std::shared_ptr<LookAtOrthoApp> getInstance()
    {
        return k_instance;
    }

    ~LookAtOrthoApp() override;

private:
    LookAtOrthoApp(const std::string& vertexShaderFile,
                   const std::string& fragShaderFile);

    void process() override;

    void setupViewport();

    void setupCube();

    void setupModelMatrix();

    void setupProjMatrix();

    void setupOpenGL();

    void setupProgram();

private:
    static std::shared_ptr<LookAtOrthoApp> k_instance;

    float viewportWidth_;
    float viewportHeight_;
    sharedlib::VertexArray va_;
    LookAtOrthoProgram program_;
    sharedlib::Matrix4 modelMatrix_;
    sharedlib::Matrix4 projMatrix_;
};

} // end of namespace lookatortho

#endif

