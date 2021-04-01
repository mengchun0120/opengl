#ifndef INCLUDE_OPGL_SHADER_PROGRAM_H
#define INCLUDE_OPGL_SHADER_PROGRAM_H

#include <string>
#include <GL/glew.h>

namespace opgl {

class ShaderProgram {
public:
    static GLuint createShader(GLenum type,
                               const std::string &src);

    static bool compileShader(GLuint shader,
                              const std::string &src);

    static bool isShaderCompileSuccessful(GLuint shader);

    static std::string getShaderInfo(GLuint shader);

    static GLuint createProgram(GLuint vertexShader,
                                GLuint fragShader);

    static bool linkProgram(GLuint program,
                            GLuint vertexShader,
                            GLuint fragShader);

    static bool isProgramLinkSuccessful(GLuint program);

    static std::string getProgramInfo(GLuint program);

    static void destroyShader(GLuint program,
                              GLuint shader);

    static void destroyProgram(GLuint program);

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

private:
    GLuint vertexShader_;
    GLuint fragShader_;
    GLuint program_;
};

} // end of namespace opgl

#endif

