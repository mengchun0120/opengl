#ifndef INCLUDE_CUBE_APP_H
#define INCLUDE_CUBE_APP_H

#include <memory>
#include <sharedlib_app.h>
#include <sharedlib_vertex_array.h>
#include <sharedlib_matrix.h>
#include <cube_program.h>

namespace cube {

class CubeApp: public sharedlib::App {
public:
    static void initInstance(const std::string& vertexShaderFile,
                             const std::string& fragShaderFile);

    static std::shared_ptr<CubeApp> getInstance()
    {
        return k_instance;
    }

    ~CubeApp() override;

private:
    static void onKey(GLFWwindow* window,
                      int key,
                      int scanCode,
                      int action,
                      int mods);

    CubeApp(const std::string& vertexShaderFile,
            const std::string& fragShaderFile);

    void process() override;

    void setupInput();

    void setupProgram();

    void setupOpenGL();

    void handleKey(GLFWwindow* window,
                   int key,
                   int scanCode,
                   int action,
                   int mods);

    void rotateX(bool forward);

    void rotateY(bool forward);

    void rotateZ(bool forward);

private:
    static std::shared_ptr<CubeApp> k_instance;

    sharedlib::VertexArray va_;
    CubeProgram program_;
    sharedlib::Matrix4 rotateForwardMatrixX_;
    sharedlib::Matrix4 rotateForwardMatrixY_;
    sharedlib::Matrix4 rotateForwardMatrixZ_;
    sharedlib::Matrix4 rotateBackwardMatrixX_;
    sharedlib::Matrix4 rotateBackwardMatrixY_;
    sharedlib::Matrix4 rotateBackwardMatrixZ_;
    sharedlib::Matrix4 rotateMatrixX_;
    sharedlib::Matrix4 rotateMatrixY_;
    sharedlib::Matrix4 rotateMatrixZ_;
};

} // end of namespace cube

#endif

