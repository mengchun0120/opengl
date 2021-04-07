#ifndef INCLUDE_GASKET3DLINE_PROGRAM_H
#define INCLUDE_GASKET3DLINE_PROGRAM_H

#include "sharedlib_shader_program.h"

namespace sharedlib {

class VertexArray;

} // end of namespace sharedlib

namespace gasket3dline {

class Gasket3DLineProgram: public sharedlib::ShaderProgram {
public:
    Gasket3DLineProgram(const std::string &vertexShaderFile,
                        const std::string &fragShaderFile);

    ~Gasket3DLineProgram() override
    {}

    void setPositionColor(const sharedlib::VertexArray &vertices);

private:
    GLint positionLocation_;
    GLint colorLocation_;
};

} // end of namespace gasket3dline

#endif

