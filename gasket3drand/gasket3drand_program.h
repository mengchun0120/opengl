#ifndef INCLUDE_GASKET3DRAND_PROGRAM_H
#define INCLUDE_GASKET3DRAND_PROGRAM_H

#include "sharedlib_shader_program.h"

namespace sharedlib {

class VertexArray;

} // end of namespace sharedlib

namespace gasket3drand {

class Gasket3DRandProgram: public sharedlib::ShaderProgram {
public:
    Gasket3DRandProgram(const std::string &vertexShaderFile,
                        const std::string &fragShaderFile);

    ~Gasket3DRandProgram() override
    {}

    void draw(const sharedlib::VertexArray &vertices);

    void setPosition(const sharedlib::VertexArray &vertices);

private:
    GLint positionLocation_;
};

} // end of namespace gasket3drand

#endif

