#ifndef INCLUDE_GASKET3DLINE_Generator_H
#define INCLUDE_GASKET3DLINE_Generator_H

#include <array>
#include "sharedlib_vector.h"
#include "sharedlib_vertex_array.h"

namespace gasket3dline {

class Gasket3DLineGenerator final {
public:
    static void generate(sharedlib::VertexArray &va,
                         const std::array<sharedlib::Vec3, 4> &tetrahedron,
                         const std::array<sharedlib::Vec3, 4> &colors,
                         unsigned int numDivisions);
};

} // end of namespace gasket3dline

#endif

