#include "sharedlib_file_utils.h"
#include "sharedlib_vertex_array.h"
#include "gasket3drand_program.h"

using namespace sharedlib;

namespace gasket3drand {

Gasket3DRandProgram::Gasket3DRandProgram(const std::string &vertexShaderFile,
                                         const std::string &fragShaderFile):
    ShaderProgram(readFile(vertexShaderFile), readFile(fragShaderFile)),
    positionLocation_(glGetAttribLocation(program_, "position"))
{
}

void Gasket3DRandProgram::draw(const VertexArray &vertices)
{
    glDrawArrays(GL_POINTS, 0, vertices.numVertices(0));
}

void Gasket3DRandProgram::setPosition(const VertexArray &vertices)
{
    constexpr int VERTEX_SIZE = 3;

    glBindVertexArray(vertices.arrayObj());
    glBindBuffer(GL_ARRAY_BUFFER, vertices.bufferObj());

    glVertexAttribPointer(positionLocation_, VERTEX_SIZE, GL_FLOAT, GL_FALSE,
                          vertices.stride(0), (void *)0);
    glEnableVertexAttribArray(positionLocation_);
}

} // end of namespace gasket3drand

