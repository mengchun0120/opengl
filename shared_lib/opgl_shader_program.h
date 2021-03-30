#ifndef INCLUDE_OPGL_SHADER_PROGRAM_H
#define INCLUDE_OPGL_SHADER_PROGRAM_H

#include <string>
#include <GL/glew.h>

namespace opgl {

class ShaderProgram {
public:
    ShaderProgram(const std::string &vertexShaderFile,
                  const std::string &fragShaderFile);

    virtual ~ShaderProgram();

    void use();

private:
    void linkProgram();

protected:
    GLuint vertexShader_;
    GLuint fragShader_;
    GLuint program_;
};

} // end of namespace opgl

#endif

