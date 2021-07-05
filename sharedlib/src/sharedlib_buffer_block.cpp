#include "sharedlib_my_exception.h"
#include "sharedlib_buffer_block.h"

namespace sharedlib {

BufferBlock::BufferBlock():
    data_(nullptr),
    numVertices_(0),
    vertexSize_(0),
    stride_(0)
{}

BufferBlock::BufferBlock(const void *data,
                         unsigned int numVertices,
                         unsigned int vertexSize,
                         unsigned int stride):
    data_(data),
    numVertices_(numVertices),
    vertexSize_(vertexSize),
    stride_(stride)
{}

void BufferBlock::validate() const
{
    if (nullptr == data_)
    {
        THROW_EXCEPT("data_ is null");
    }

    if (0 == numVertices_)
    {
        THROW_EXCEPT("numVertices_ is zero");
    }

    if (0 == vertexSize_)
    {
        THROW_EXCEPT("vertexSize_ is zero");
    }
}


} // end of namespace sharedlib

