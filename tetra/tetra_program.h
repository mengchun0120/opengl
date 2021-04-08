#ifndef INCLUDE_TETRA_PROGRAM_H
#define INCLUDE_TETRA_PROGRAM_H

#include "sharedlib_shader_program.h"
#include "sharedlib_vertex_array.h"

namespace tetra {

class TetraProgram: public sharedlib::ShaderProgram {
public:
    TetraProgram(const std::string &vertexShaderFile,
                 const std::string &fragShaderFile);

    void setPositionColor(const sharedlib::VertexArray &vertices);

private:
    GLint positionLocation_;
    GLint colorLocation_;
};

} // end of namespace tetra


#endif

