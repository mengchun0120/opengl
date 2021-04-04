#include "sharedlib_file_utils.h"
#include "sharedlib_vertex_array.h"
#include "gasket2dline_program.h"

using namespace sharedlib;

namespace gasket2dline {

Gasket2DLineProgram::Gasket2DLineProgram(const std::string &vertexShaderFile,
                                         const std::string &fragShaderFile):
    ShaderProgram(readFile(vertexShaderFile), readFile(fragShaderFile)),
    positionLocation_(glGetAttribLocation(program_, "position"))
{
}

void Gasket2DLineProgram::draw(const VertexArray &vertices)
{
    glDrawArrays(GL_TRIANGLES, 0, vertices.numVertices());
}

void Gasket2DLineProgram::setPosition(const VertexArray &vertices)
{
    glBindVertexArray(vertices.arrayObj());
    glBindBuffer(GL_ARRAY_BUFFER, vertices.bufferObj());

    glVertexAttribPointer(positionLocation_, 2, GL_FLOAT, GL_FALSE,
                          vertices.stride(), (void *)0);
    glEnableVertexAttribArray(positionLocation_);
}

} // end of namespace gasket2drand

