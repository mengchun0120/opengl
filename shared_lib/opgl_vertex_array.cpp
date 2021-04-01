#include "opgl_my_exception.h"
#include "opgl_vertex_array.h"

namespace opgl {

void VertexArray::validate(void *data,
                           unsigned int numVertices,
                           unsigned int vertexSize)
{
    if (nullptr == data)
    {
        THROW_EXCEPT("data is null");
    }

    if (0 == numVertices)
    {
        THROW_EXCEPT("numVertices is zero");
    }

    if (0 == vertexSize)
    {
        THROW_EXCEPT("vertexSize is zero");
    }
}

GLuint VertexArray::createArrayObj()
{
    GLuint arrayObj;

    glGenVertexArrays(1, &arrayObj);
    if (0 == arrayObj)
    {
        THROW_EXCEPT("glGenVertexArrayFailed: " + std::to_string(glGetError()));
    }

    return arrayObj;
}

GLuint VertexArray::createBufferObj(GLuint arrayObj,
                                    void *data,
                                    unsigned int numVertices,
                                    unsigned int vertexSize)
{
    glBindVertexArray(arrayObj);

    GLuint bufferObj;

    glGenBuffers(1, &bufferObj);
    if (0 == bufferObj)
    {
        THROW_EXCEPT("glGenBufferFailed: " + std::to_string(glGetError()));
    }

    glBindBuffer(GL_ARRAY_BUFFER, bufferObj);
    glBufferData(GL_ARRAY_BUFFER, numVertices * vertexSize,
                 data, GL_STATIC_DRAW);

    return bufferObj;
}

void VertexArray::destroyArrayObj(GLuint arrayObj)
{
    if (arrayObj != 0)
    {
        glDeleteVertexArrays(1, &arrayObj);
    }
}

void VertexArray::destroyBufferObj(GLuint bufferObj)
{
    if (bufferObj != 0)
    {
        glDeleteBuffers(1, &bufferObj);
    }
}

VertexArray::VertexArray():
    numVertices_(0),
    vertexSize_(0),
    stride_(0),
    arrayObj_(0),
    bufferObj_(0)
{
}

VertexArray::VertexArray(void *data,
                         unsigned int numVertices,
                         unsigned int vertexSize,
                         unsigned int stride):
    VertexArray()
{
    load(data, numVertices, vertexSize, stride);
}

VertexArray::~VertexArray()
{
    destroyBufferObj(bufferObj_);
    destroyArrayObj(arrayObj_);
}

void VertexArray::load(void *data,
                       unsigned int numVertices,
                       unsigned int vertexSize,
                       unsigned int stride)
{
    validate(data, numVertices, vertexSize);
    arrayObj_ = createArrayObj();
    bufferObj_ = createBufferObj(arrayObj_, data, numVertices, vertexSize);
    numVertices_ = numVertices;
    vertexSize_ = vertexSize;
    stride_ = stride;
}

} // end of namespace opgl

