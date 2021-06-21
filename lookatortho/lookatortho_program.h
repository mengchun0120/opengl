#ifndef INCLUDE_LOOKATORTHO_PROGRAM_H
#define INCLUDE_LOOKATORTHO_PROGRAM_H

#include <sharedlib_shader_program.h>
#include <sharedlib_vertex_array.h>
#include <sharedlib_matrix.h>

namespace lookatortho {

class LookAtOrthoProgram: public sharedlib::ShaderProgram {
public:
    LookAtOrthoProgram(const std::string& vertexShaderFile,
                const std::string& fragShaderFile);

    ~LookAtOrthoProgram() override
    {}

    void setPositionColor(const sharedlib::VertexArray& va);

    void setModelMatrix(const sharedlib::Matrix4& matrix);

    void setProjMatrix(const sharedlib::Matrix4& matrix);

private:
    GLint positionLocation_;
    GLint colorLocation_;
    GLint modelMatrixLocation_, projMatrixLocation_;
};

} // end of namespace lookatortho

#endif

