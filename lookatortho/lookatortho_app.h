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
    static void onKey(GLFWwindow* window,
                      int key,
                      int scanCode,
                      int action,
                      int mods);

    LookAtOrthoApp(const std::string& vertexShaderFile,
                   const std::string& fragShaderFile);

    void process() override;

    void setupViewport();

    void setupCubes();

    void setupOpenGL();

    void setupProgram();

    void setupInput();

    void setupModelMatrix();

    void setupProjMatrix();

    void handleKey(GLFWwindow* window,
                   int key,
                   int scanCode,
                   int action,
                   int mods);

    void rotateEyeX(bool forward);

    void rotateEyeY(bool forward);

    void moveEyeLeft();

    void moveEyeRight();

    void moveEyeForward();

    void moveEyeBackward();

private:
    static std::shared_ptr<LookAtOrthoApp> k_instance;
    static constexpr std::size_t NUM_CUBES = 4;

    float viewportWidth_;
    float viewportHeight_;
    std::array<sharedlib::VertexArray, NUM_CUBES> cubes_;
    LookAtOrthoProgram program_;
    float eyeRadius_;
    float eyePhi_;
    float eyeTheta_;
    float eyeDistX_;
    float eyeDistZ_;
    sharedlib::Point3 eye_;
    sharedlib::Point3 at_;
    sharedlib::Point3 up_;
    sharedlib::Matrix4 modelMatrix_;
    sharedlib::Matrix4 projMatrix_;
};

} // end of namespace lookatortho

#endif

