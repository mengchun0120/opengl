#include <sharedlib_file_utils.h>
#include <cube_program.h>

namespace cube {

CubeProgram::CubeProgram(const std::string& vertexShaderFile,
                         const std::string& fragShaderFile):
    ShaderProgram(sharedlib::readFile(vertexShaderFile),
                  sharedlib::readFile(fragShaderFile)),
    positionLocation_(glGetAttribLocation(program_, "position")),
    colorLocation_(glGetAttribLocation(program_, "color")),
    rotateMatrixXLocation_(glGetUniformLocation(program_, "rotateMatrixX")),
    rotateMatrixYLocation_(glGetUniformLocation(program_, "rotateMatrixY")),
    rotateMatrixZLocation_(glGetUniformLocation(program_, "rotateMatrixZ"))
{
}

void CubeProgram::setPositionColor(const sharedlib::VertexArray& va)
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

void CubeProgram::setRotateMatrixX(const sharedlib::Matrix4& matrix)
{
    glUniformMatrix4fv(rotateMatrixXLocation_, 1, GL_FALSE,
                       reinterpret_cast<const GLfloat *>(matrix.data()));
}

void CubeProgram::setRotateMatrixY(const sharedlib::Matrix4& matrix)
{
    glUniformMatrix4fv(rotateMatrixYLocation_, 1, GL_FALSE,
                       reinterpret_cast<const GLfloat *>(matrix.data()));
}

void CubeProgram::setRotateMatrixZ(const sharedlib::Matrix4& matrix)
{
    glUniformMatrix4fv(rotateMatrixZLocation_, 1, GL_FALSE,
                       reinterpret_cast<const GLfloat *>(matrix.data()));
}

} // end of namespace cube

