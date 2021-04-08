#ifndef INCLUDE_OPGL_VERTEX_ARRAY_H
#define INCLUDE_OPGL_VERTEX_ARRAY_H

#include <initializer_list>
#include <vector>
#include <algorithm>
#include "sharedlib_opengl.h"
#include "sharedlib_buffer_block.h"

namespace sharedlib {

class VertexArray {

    struct BufferDescriptor {
        void init(const BufferBlock &block,
                  unsigned int offset);

        unsigned int offset_;
        unsigned int numVertices_;
        unsigned int vertexSize_;
        unsigned int totalSize_;
        unsigned int stride_;
    };

public:

    VertexArray();

    VertexArray(const void *data,
                unsigned int numVertices,
                unsigned int vertexSize,
                unsigned int stride=0);

    VertexArray(const std::initializer_list<BufferBlock> &blocks);

    template <typename Iterator>
    VertexArray(Iterator begin,
                Iterator end);

    VertexArray(const VertexArray &other) = delete;

    virtual ~VertexArray();

    void load(const void *data,
              unsigned int numVertices,
              unsigned int vertexSize,
              unsigned int stride=0);

    void load(const std::initializer_list<BufferBlock> &blocks);

    template <typename Iterator>
    void load(Iterator begin,
              Iterator end);

    VertexArray &operator=(const VertexArray &other) = delete;

    bool valid() const noexcept
    {
        return arrayObj_ != 0 && bufferObj_ != 0;
    }

    unsigned int numBufferBlocks() const noexcept
    {
        return descriptors_.size();
    }

    unsigned int offset(unsigned int idx) const
    {
        return descriptors_[idx].offset_;
    }

    unsigned int numVertices(unsigned int idx) const
    {
        return descriptors_[idx].numVertices_;
    }

    unsigned int vertexSize(unsigned int idx) const
    {
        return descriptors_[idx].vertexSize_;
    }

    unsigned int stride(unsigned int idx) const
    {
        return descriptors_[idx].stride_;
    }

    unsigned int arrayObj() const
    {
        return arrayObj_;
    }

    unsigned int bufferObj() const
    {
        return bufferObj_;
    }

private:
    template <typename Iterator>
    unsigned int getNumBufferBlocks(Iterator begin,
                                    Iterator end);

    template <typename Iterator>
    unsigned int getTotalSize(Iterator begin,
                              Iterator end);

    void createArrayObj();

    void createBufferObj();

    void storeBufferBlock(BufferDescriptor &descriptor,
                          const BufferBlock &block,
                          unsigned int offset);

private:
    std::vector<BufferDescriptor> descriptors_;
    GLuint arrayObj_;
    GLuint bufferObj_;
};

template <typename Iterator>
VertexArray::VertexArray(Iterator begin, Iterator end):
    VertexArray()
{
    load(begin, end);
}

template <typename Iterator>
unsigned int VertexArray::getNumBufferBlocks(Iterator begin,
                                             Iterator end)
{
    unsigned int num = 0;
    for (Iterator it = begin; it != end; ++it)
    {
        ++num;
    }
    return num;
}

template <typename Iterator>
unsigned int VertexArray::getTotalSize(Iterator begin,
                                       Iterator end)
{
    unsigned int size = 0;
    for (Iterator it = begin; it != end; ++it)
    {
        size += it->numVertices_ * it->vertexSize_;
    }
    return size;
}


template <typename Iterator>
void VertexArray::load(Iterator begin, Iterator end)
{
    createArrayObj();
    createBufferObj();

    unsigned int numBufferBlocks = getNumBufferBlocks(begin, end);
    unsigned int totalSize = getTotalSize(begin, end);

    descriptors_.resize(numBufferBlocks);
    glBindBuffer(GL_ARRAY_BUFFER, bufferObj_);
    glBufferData(GL_ARRAY_BUFFER, totalSize, nullptr, GL_STATIC_DRAW);

    unsigned int i =0, offset = 0;

    for (auto it = begin; it != end; ++it, ++i)
    {
        storeBufferBlock(descriptors_[i], *it, offset);
        offset += descriptors_[i].totalSize_;
    }
}

} // end of namespace sharedlib

#endif

