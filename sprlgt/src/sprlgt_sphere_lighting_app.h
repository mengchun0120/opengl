#ifndef INCLUDE_SPRLGT_SPHERE_LIGHTING_APP_H
#define INCLUDE_SPRLGT_SPHERE_LIGHTING_APP_H

#include <string>
#include <sharedlib_app.h>
#include <sprlgt_app_config.h>
#include <sprlgt_sphere_lighting_shader_program.h>

namespace sprlgt {

class SphereLightingApp: public sharedlib::App {
public:
    SphereLightingApp(const std::string& vertexShaderFile,
                      const std::string& fragShaderFile,
                      const AppConfig& cfg);

    ~SphereLightingApp() override;

    void process() override;

private:
    void setupOpenGL();

    void setupSphere();

    void setupLighting();

private:
    const AppConfig& cfg_;
    SphereLightingShaderProgram shader_;
    sharedlib::Matrix4 modelViewMatrix_;
    sharedlib::Matrix4 projMatrix_;
    sharedlib::VertexArray va_;
    sharedlib::Vector3 eyePos_;
    sharedlib::Vector3 lightPos_;
    sharedlib::Vector3 ambientProduct_;
    sharedlib::Vector3 diffuseProduct_;
    sharedlib::Vector3 specularProduct_;
};

} // end of namespace sprlgt

#endif

