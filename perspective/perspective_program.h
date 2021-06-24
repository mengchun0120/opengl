#ifndef INCLUDE_PERSPECTIVE_PROGRAM_H
#define INCLUDE_PERSPECTIVE_PROGRAM_H

#include <sharedlib_shader_program.h>
#include <sharedlib_vertex_array.h>
#include <sharedlib_matrix.h>

namespace perspective {

class PerspectiveProgram: public sharedlib::ShaderProgram {
public:
    PerspectiveProgram(const std::string& vertexShaderFile,
                       const std::string& fragShaderFile);

    ~PerspectiveProgram() override
    {}

    void setPositionColor(const sharedlib::VertexArray& va);

    void setModelMatrix(const sharedlib::Matrix4& matrix);

    void setProjMatrix(const sharedlib::Matrix4& matrix);

private:
    GLint positionLocation_;
    GLint colorLocation_;
    GLint modelMatrixLocation_, projMatrixLocation_;
};

} // end of namespace perspective

#endif

