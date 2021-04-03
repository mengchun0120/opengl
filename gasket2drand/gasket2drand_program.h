#ifndef INCLUDE_GASKET2DRAND_PROGRAM_H
#define INCLUDE_GASKET2DRAND_PROGRAM_H

#include "sharedlib_shader_program.h"

namespace sharedlib {

class VertexArray;

} // end of namespace sharedlib

namespace gasket2drand {

class Gasket2DRandProgram: public sharedlib::ShaderProgram {
public:
    Gasket2DRandProgram(const std::string &vertexShaderFile,
                        const std::string &fragShaderFile);

    ~Gasket2DRandProgram() override
    {}

    void draw(const sharedlib::VertexArray &vertices);

    void setPosition(const sharedlib::VertexArray &vertices);

private:
    GLint positionLocation_;
};

} // end of namespace gasket2drand

#endif

