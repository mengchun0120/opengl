#include <sharedlib_file_utils.h>
#include <lookatortho_program.h>

namespace lookatortho {

LookAtOrthoProgram::LookAtOrthoProgram(const std::string& vertexShaderFile,
                                       const std::string& fragShaderFile):
    ShaderProgram(sharedlib::readFile(vertexShaderFile),
                  sharedlib::readFile(fragShaderFile)),
    positionLocation_(glGetAttribLocation(program_, "position")),
    colorLocation_(glGetAttribLocation(program_, "color")),
    modelMatrixLocation_(glGetUniformLocation(program_, "modelMatrix")),
    projMatrixLocation_(glGetUniformLocation(program_, "projMatrix"))
{
}

void LookAtOrthoProgram::setPositionColor(const sharedlib::VertexArray& va)
{
    constexpr int POINT_SIZE = 4;

    glBindVertexArray(va.arrayObj());
    glBindBuffer(GL_ARRAY_BUFFER, va.bufferObj());

    glVertexAttribPointer(positionLocation_, POINT_SIZE, GL_FLOAT, GL_FALSE,
                          va.stride(0), reinterpret_cast<void *>(0));
    glEnableVertexAttribArray(positionLocation_);

    glVertexAttribPointer(colorLocation_, POINT_SIZE, GL_FLOAT, GL_FALSE,
                          va.stride(1), reinterpret_cast<void *>(va.offset(1)));
    glEnableVertexAttribArray(colorLocation_);
}

void LookAtOrthoProgram::setModelMatrix(const sharedlib::Matrix4& matrix)
{
    glUniformMatrix4fv(modelMatrixLocation_, 1, GL_TRUE,
                       reinterpret_cast<const GLfloat *>(matrix.data()));
}

void LookAtOrthoProgram::setProjMatrix(const sharedlib::Matrix4& matrix)
{
    glUniformMatrix4fv(projMatrixLocation_, 1, GL_TRUE,
                       reinterpret_cast<const GLfloat *>(matrix.data()));
}

} // end of namespace lookatortho

