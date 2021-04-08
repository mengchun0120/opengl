#include "sharedlib_file_utils.h"
#include "sharedlib_vertex_array.h"
#include "gasket3dline_program.h"

using namespace sharedlib;

namespace gasket3dline {

Gasket3DLineProgram::Gasket3DLineProgram(const std::string &vertexShaderFile,
                                         const std::string &fragShaderFile):
    ShaderProgram(readFile(vertexShaderFile), readFile(fragShaderFile)),
    positionLocation_(glGetAttribLocation(program_, "position")),
    colorLocation_(glGetAttribLocation(program_, "color"))
{
}

void Gasket3DLineProgram::setPositionColor(const VertexArray &va)
{
    constexpr int POINT_SIZE = 3;

    glBindVertexArray(va.arrayObj());
    glBindBuffer(GL_ARRAY_BUFFER, va.bufferObj());

    glVertexAttribPointer(positionLocation_, POINT_SIZE, GL_FLOAT, GL_FALSE,
                          va.stride(0), (void *)0);
    glEnableVertexAttribArray(positionLocation_);

    glVertexAttribPointer(colorLocation_, POINT_SIZE, GL_FLOAT, GL_FALSE,
                          va.stride(1), (void *)va.offset(1));
    glEnableVertexAttribArray(colorLocation_);
}

} // end of namespace gasket2drand

