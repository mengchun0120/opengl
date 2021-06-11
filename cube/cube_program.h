#ifndef INCLUDE_CUBE_PROGRAM_H
#define INCLUDE_CUBE_PROGRAM_H

#include <sharedlib_shader_program.h>
#include <sharedlib_vertex_array.h>
#include <sharedlib_matrix.h>

namespace cube {

class CubeProgram: public sharedlib::ShaderProgram {
public:
    CubeProgram(const std::string &vertexShaderFile,
                const std::string &fragShaderFile);

    ~CubeProgram() override
    {}

    void setPositionColor(const sharedlib::VertexArray &va);

    void setRotateMatrixX(const sharedlib::Mat4 &matrix);

    void setRotateMatrixY(const sharedlib::Mat4 &matrix);

    void setRotateMatrixZ(const sharedlib::Mat4 &matrix);

private:
    GLint positionLocation_;
    GLint colorLocation_;
    GLint rotateMatrixXLocation_, rotateMatrixYLocation_, rotateMatrixZLocation_;
};

} // end of namespace cube

#endif

