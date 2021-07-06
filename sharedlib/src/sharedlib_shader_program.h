#ifndef INCLUDE_OPGL_SHADER_PROGRAM_H
#define INCLUDE_OPGL_SHADER_PROGRAM_H

#include <string>
#include "sharedlib_opengl.h"

namespace sharedlib {

class ShaderProgram {
public:
    ShaderProgram();

    ShaderProgram(const std::string &vertexShaderSrc,
                  const std::string &fragShaderSrc);

    ShaderProgram(const ShaderProgram &other) = delete;

    virtual ~ShaderProgram();

    void load(const std::string &vertexShaderSrc,
              const std::string &fragShaderSrc);

    bool valid() const noexcept
    {
        return vertexShader_ != 0 &&
               fragShader_ != 0 &&
               program_ != 0;
    }

    ShaderProgram& operator=(const ShaderProgram &other) = delete;

    void use();

    GLint getUniformLocation(const char* name);

    GLint getAttribLocation(const char* name);

    const std::string getError() const;

protected:
    GLuint vertexShader_;
    GLuint fragShader_;
    GLuint program_;
};

} // end of namespace sharedlib

#endif

