#ifndef INCLUDE_OPGL_VERTEX_ARRAY_H
#define INCLUDE_OPGL_VERTEX_ARRAY_H

#include <GL/glew.h>

namespace opgl {

class VertexArray {
public:
    static void validate(void *data,
                         unsigned int numVertices,
                         unsigned int vertexSize);

    static GLuint createArrayObj();

    static GLuint createBufferObj(GLuint arrayObj,
                                  void *data,
                                  unsigned int numVertices,
                                  unsigned int vertexSize);

    static void destroyArrayObj(GLuint arrayObj);

    static void destroyBufferObj(GLuint bufferObj);

    VertexArray();

    VertexArray(void *data,
                unsigned int numVertices,
                unsigned int vertexSize,
                unsigned int stride=0);

    VertexArray(const VertexArray &other) = delete;

    virtual ~VertexArray();

    void load(void *data,
              unsigned int numVertices,
              unsigned int vertexSize,
              unsigned int stride=0);

    VertexArray &operator=(const VertexArray &other) = delete;

    bool valid() const noexcept
    {
        return arrayObj_ != 0 && bufferObj_ != 0;
    }

    unsigned int numVertices() const noexcept
    {
        return numVertices_;
    }

    unsigned int vertexSize() const noexcept
    {
        return vertexSize_;
    }

    unsigned int stride() const noexcept
    {
        return stride_;
    }

    unsigned int arrayObj() const noexcept
    {
        return arrayObj_;
    }

    unsigned int bufferObj() const noexcept
    {
        return bufferObj_;
    }

private:
    unsigned int numVertices_;
    unsigned int vertexSize_;
    unsigned int stride_;
    GLuint arrayObj_;
    GLuint bufferObj_;
};

} // end of namespace opgl

#endif

