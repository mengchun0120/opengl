#ifndef INCLUDE_CUBE_PROGRAM_H
#define INCLUDE_CUBE_PROGRAM_H

#include <sharedlib_shader_program.h>

namespace sharedlib {

class VertexArray;
class Mat4;

} // end of namespace sharedlib

namespace cube {

class CubeProgram: public sharedlib::ShaderProgram {
public:
    CubeProgram(const std::string &vertexShaderFile,
                const std::string &fragShaderFile);

    ~CubeProgram() override
    {}

    void setPositionColor(const sharedlib::VertexArray &vertices);

    void setRotateMatrix(const sharedlib::Mat4& matrix);

private:
    GLint positionLocation_;
    GLint colorLocation_;
    GLint rotateMatrixLocation_;
};

} // end of namespace cube

#endif

