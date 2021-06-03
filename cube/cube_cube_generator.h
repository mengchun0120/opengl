#ifndef INCLUDE_CUBE_CUBE_GENERATOR_H
#define INCLUDE_CUBE_CUBE_GENERATOR_H

#include <vector>
#include <memory>
#include <sharedlib_vector.h>
#include <sharedlib_vertex_array.h>

namespace cube {

class CubeGenerator {
public:
    CubeGenerator();

    void generate(sharedlib::VertexArray &va,
                  const std::array<sharedlib::Point4, 8> &vertices,
                  const std::array<sharedlib::Color, 6> &colors);

private:
    void addSide(const sharedlib::Point4 &a,
                 const sharedlib::Point4 &b,
                 const sharedlib::Point4 &c,
                 const sharedlib::Point4 &d,
                 const sharedlib::Color &color);

private:
    static constexpr unsigned int NUM_VERTICES = 36;

    std::array<sharedlib::Point4, NUM_VERTICES> vertexArray_;
    std::array<sharedlib::Color, NUM_VERTICES> colorArray_;
    unsigned int index_;
};

} // end of namespace cube

#endif

