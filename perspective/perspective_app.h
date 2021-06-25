#ifndef INCLUDE_PERSPECTIVE_APP_H
#define INCLUDE_PERSPECTIVE_APP_H

#include <memory>
#include <sharedlib_app.h>
#include <perspective_program.h>

namespace perspective {

class PerspectiveApp: public sharedlib::App {
public:
    static void initInstance(const std::string& vertexShaderFile,
                             const std::string& fragShaderFile);

    static std::shared_ptr<PerspectiveApp> getInstance()
    {
        return k_instance;
    }

    ~PerspectiveApp() override;

private:
    static void onKey(GLFWwindow* window,
                      int key,
                      int scanCode,
                      int action,
                      int mods);

    PerspectiveApp(const std::string& vertexShaderFile,
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
    static std::shared_ptr<PerspectiveApp> k_instance;
    static constexpr std::size_t NUM_CUBES = 8;

    int index_;
    float viewportWidth_;
    float viewportHeight_;
    std::array<sharedlib::VertexArray, NUM_CUBES> cubes_;
    PerspectiveProgram program_;
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

} // end of namespace perspective

#endif

