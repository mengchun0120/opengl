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
    static void initInstance(const std::string &vertexShaderFile,
                             const std::string &fragShaderFile);

    static std::shared_ptr<CubeApp> getInstance()
    {
        return k_instance;
    }

    ~CubeApp() override
    {}

private:
    CubeApp(const std::string &vertexShaderFile,
            const std::string &fragShaderFile);

    void process() override;

    void setupProgram();

    void setupOpenGL();

private:
    static std::shared_ptr<CubeApp> k_instance;

    sharedlib::VertexArray va_;
    sharedlib::Mat4 rotateMatrix_;
    CubeProgram program_;
};

} // end of namespace cube

#endif

