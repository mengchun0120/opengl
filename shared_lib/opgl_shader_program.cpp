#include <stdexcept>
#include <GL/glew.h>
#include "opgl_shader_program.h"

namespace opgl {

GLuint setupShader(GLenum type,
                   const std::string &fileName);


GLuint createShader(GLenum type)
{
    GLuint shader = glCreateShader(type);
    if (shader == 0)
    {
        throw std::runtime_error("glCreateShader failed");
    }

    return shader;
}

void compileShader(GLuint shader, const std::string &fileName)
{
    std::string src = readFile(fileName);
    const GLchar *source = src.c_str();
    GLint len = src.length();

    glShaderSource(shader, 1, static_cast<const GLchar * const*>&source, &len);
    glCompileShader(shader);
}

void checkShaderCompileStatus(GLuint shader)
{
    GLint compileStatus;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus == 0)
    {
        glDeleteShader(shader);
        throw std::runtime_error("Failed to compile shader");
    }
}

ShaderProgram::ShaderProgram(const std::string &vertexShaderFile,
                             const std::string &fragShaderFile):
    vertexShader_(setupShader(GL_VERTEX_SHADER, vertexShaderFile),
    fragShader_(setupShader(GL_FRAG_SHADER, fragShaderFile),
    
{
    vertexShader_ = setupShader(GL_VERTEX_SHADER, vertexShaderFile);
    fragShader_ = 
}

ShaderProgram::~ShaderProgram()
{
}

void ShaderProgram::use()
{
}

GLuint ShaderProgram::setupShader(GLenum type,
                                  const std::string &fileName)
{
    GLuint shader = createShader(type);
    compileShader(shader, fileName);
    checkShaderCompileStatus(shader);
    return shader;
}

} // end of namespace opgl

