#ifndef INCLUDE_CUBE_APP_H
#define INCLUDE_CUBE_APP_H

#include <sharedlib_app.h>
#include <sharedlib_vertex_array.h>
#include <sharedlib_matrix.h>
#include <cube_program.h>

namespace cube {

class CubeApp: public sharedlib::App {
public:



private:
    CubeApp(const std::string &vertexShaderFile,
            const std::string &fragShaderFile);

    void process() override;

    void setupProgram();

    void setupOpenGL();

private:
    sharedlib::vertexArray va_;
    sharedlib::Mat4 rotateMatrix_;
    CubeProgram program_;
};

} // end of namespace cube

#endif

