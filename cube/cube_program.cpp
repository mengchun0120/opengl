#include <cube_program.h>

namespace cube {

CubeProgram::CubeProgram(const std::string &vertexShaderFile,
                         const std::string &fragShaderFile):
    ShaderProgram(vertexShaderFile, fragShaderFile),
    positionLocation_(glGetAttribLocation(program_, "position")),
    colorLocation_(glGetAttribLocation(program_, "color")),
    rotateMatrixLocation_(glGetUniformLocation(program_, "rotateMatrix"))
{
}

void CubeProgram::setPositionColor(const sharedlib::VertexArray &va)
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

void CubeProgram::setRotateMatrix(const sharedlib::Mat4 &matrix)
{
    glUniformMatrix4fv(rotateMatrixLocation_, 1, GL_FALSE,
                       reinterpret_cast<const GLfloat *>(matrix.data()));
}

} // end of namespace cube

