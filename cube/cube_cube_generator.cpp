#include <sharedlib_vertex_array.h>
#include <cube_cube_generator.h>

using namespace sharedlib;

namespace cube {

CubeGenerator::CubeGenerator():
    index_(0)
{
}

void CubeGenerator::generate(VertexArray &va,
                             const std::array<Point4, 8> &vertices,
                             const std::array<Color, 6> &colors)
{
    index_ = 0;

    addSide(vertices[0], vertices[1], vertices[2], vertices[3], colors[0]);
    addSide(vertices[4], vertices[7], vertices[6], vertices[5], colors[1]);
    addSide(vertices[0], vertices[4], vertices[5], vertices[1], colors[2]);
    addSide(vertices[3], vertices[2], vertices[6], vertices[7], colors[3]);
    addSide(vertices[0], vertices[3], vertices[7], vertices[4], colors[4]);
    addSide(vertices[1], vertices[5], vertices[6], vertices[2], colors[5]);

    constexpr unsigned int vertexSize = 4 * sizeof(float);
    va.load({
        BufferBlock(vertexArray_.data(), NUM_VERTICES, vertexSize, 0),
        BufferBlock(colorArray_.data(), NUM_VERTICES, vertexSize, 0)
    });
}

void CubeGenerator::addSide(const Point4 &a,
                            const Point4 &b,
                            const Point4 &c,
                            const Point4 &d,
                            const Color &color)
{
    vertexArray_[index_] = a;
    vertexArray_[index_+1] = c;
    vertexArray_[index_+2] = b;
    vertexArray_[index_+3] = a;
    vertexArray_[index_+4] = d;
    vertexArray_[index_+5] = c;

    for (int i = 0; i < 6; ++i)
    {
        colorArray_[index_+i] = color;
    }

    index_ += 6;
}

} // end of namespace cube

