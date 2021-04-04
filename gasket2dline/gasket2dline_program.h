#ifndef INCLUDE_GASKET2DLINE_PROGRAM_H
#define INCLUDE_GASKET2DLINE_PROGRAM_H

#include "sharedlib_shader_program.h"

namespace sharedlib {

class VertexArray;

} // end of namespace sharedlib

namespace gasket2dline {

class Gasket2DLineProgram: public sharedlib::ShaderProgram {
public:
    Gasket2DLineProgram(const std::string &vertexShaderFile,
                        const std::string &fragShaderFile);

    ~Gasket2DLineProgram() override
    {}

    void draw(const sharedlib::VertexArray &vertices);

    void setPosition(const sharedlib::VertexArray &vertices);

private:
    GLint positionLocation_;
};

} // end of namespace gasket2dline

#endif

