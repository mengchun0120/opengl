#include <lookatortho_cube_generator.h>

namespace lookatortho {

CubeGenerator::CubeGenerator():
    index_(0)
{
}

void CubeGenerator::generate(sharedlib::VertexArray& va,
                             const std::array<sharedlib::Point4, 8>& vertices,
                             const std::array<sharedlib::Color, 6>& colors)
{
    using namespace sharedlib;

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

void CubeGenerator::generate(sharedlib::VertexArray& va,
                             float centerx,
                             float centery,
                             float centerz,
                             float length,
                             const std::array<sharedlib::Color, 6>& colors)
{
    using namespace sharedlib;

    float h = length / 2.0f;
    std::array<Point4, 8> vertices{
        Point4{centerx - h, centery + h, centerz + h, 1.0f},
        Point4{centerx + h, centery + h, centerz + h, 1.0f},
        Point4{centerx + h, centery + h, centerz - h, 1.0f},
        Point4{centerx - h, centery + h, centerz - h, 1.0f},
        Point4{centerx - h, centery - h, centerz + h, 1.0f},
        Point4{centerx + h, centery - h, centerz + h, 1.0f},
        Point4{centerx + h, centery - h, centerz - h, 1.0f},
        Point4{centerx - h, centery - h, centerz - h, 1.0f}
    };

    generate(va, vertices, colors);
}

void CubeGenerator::generate(sharedlib::VertexArray& va,
                             sharedlib::Point3& center,
                             float length,
                             const std::array<sharedlib::Color, 6>& colors)
{
    generate(va, center[0], center[1], center[2], length, colors);
}

void CubeGenerator::addSide(const sharedlib::Point4& a,
                            const sharedlib::Point4& b,
                            const sharedlib::Point4& c,
                            const sharedlib::Point4& d,
                            const sharedlib::Color& color)
{
    vertexArray_[index_] = a;
    vertexArray_[index_+1] = b;
    vertexArray_[index_+2] = c;
    vertexArray_[index_+3] = a;
    vertexArray_[index_+4] = c;
    vertexArray_[index_+5] = d;

    for (int i = 0; i < 6; ++i)
    {
        colorArray_[index_+i] = color;
    }

    index_ += 6;
}

} // end of namespace lookatortho

