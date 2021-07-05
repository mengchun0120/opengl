#ifndef INCLUDE_SHAREDLIB_BUFFER_BLOCK_H
#define INCLUDE_SHAREDLIB_BUFFER_BLOCK_H

namespace sharedlib {

struct BufferBlock {
    BufferBlock();

    BufferBlock(const void *data,
                unsigned int numVertices,
                unsigned int vertexSize,
                unsigned int stride);

    void validate() const;

    const void *data_;
    unsigned int numVertices_;
    unsigned int vertexSize_;
    unsigned int stride_;
};

} // end of namespace sharedlib

#endif

