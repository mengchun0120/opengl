#include <iostream>
#include "sharedlib_file_utils.h"
#include "sharedlib_vertex_array.h"
#include "gasket2drand_program.h"

using namespace sharedlib;

namespace gasket2drand {

Gasket2DRandProgram::Gasket2DRandProgram(const std::string &vertexShaderFile,
                                         const std::string &fragShaderFile):
    ShaderProgram(readFile(vertexShaderFile), readFile(fragShaderFile)),
    positionLocation_(glGetAttribLocation(program_, "position"))
{
}

void Gasket2DRandProgram::draw(const VertexArray &vertices)
{
    glDrawArrays(GL_POINTS, 0, vertices.numVertices());
}

void Gasket2DRandProgram::setPosition(const VertexArray &vertices)
{
    glBindVertexArray(vertices.arrayObj());
    glBindBuffer(GL_ARRAY_BUFFER, vertices.bufferObj());

    glVertexAttribPointer(positionLocation_, 2, GL_FLOAT, GL_FALSE,
                          vertices.stride(), (void *)0);
    glEnableVertexAttribArray(positionLocation_);
}

} // end of namespace gasket2drand

