#include "opgl_my_exception.h"
#include "opgl_shader_program.h"

namespace opgl {

GLuint ShaderProgram::createShader(GLenum type,
                                   const std::string &src)
{
    GLuint shader = glCreateShader(type);
    if (shader == 0)
    {
        THROW_EXCEPT("glCreateShader failed");
    }

    if (!compileShader(shader, src))
    {
        THROW_EXCEPT("Failed to compile shader: " + getShaderInfo(shader));
    }

    return shader;
}

bool ShaderProgram::compileShader(GLuint shader, const std::string &src)
{
    const GLchar *source = src.c_str();
    GLint len = src.length();

    glShaderSource(shader, 1, static_cast<const GLchar * const*>(&source), &len);
    glCompileShader(shader);

    return isShaderCompileSuccessful(shader);
}

bool ShaderProgram::isShaderCompileSuccessful(GLuint shader)
{
    GLint compileStatus;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
    return compileStatus != 0;
}

std::string ShaderProgram::getShaderInfo(GLuint shader)
{
    GLint infoLen;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

    char *info = new char[infoLen + 1];
    glGetShaderInfoLog(shader, infoLen, NULL, info);

    std::string msg(info);

    delete[] info;

    return msg;
}

GLuint ShaderProgram::createProgram(GLuint vertexShader,
                                     GLuint fragShader)
{
    GLuint program = glCreateProgram();
    if (program == 0)
    {
        THROW_EXCEPT("glCreateProgram failed");
    }

    if (!linkProgram(program, vertexShader, fragShader))
    {
        THROW_EXCEPT("Failed to link program: " + getProgramInfo(program));
    }

    return program;
}


bool ShaderProgram::linkProgram(GLuint program,
                                GLuint vertexShader,
                                GLuint fragShader)
{
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);
    return isProgramLinkSuccessful(program);
}

bool ShaderProgram::isProgramLinkSuccessful(GLuint program)
{
    GLint linkStatus;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
    return linkStatus != 0;
}

std::string ShaderProgram::getProgramInfo(GLuint program)
{
    GLint infoLen;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLen);

    char *info = new char[infoLen + 1];
    glGetProgramInfoLog(program, infoLen, NULL, info);

    std::string msg(info);

    delete[] info;

    return msg;
}

void ShaderProgram::destroyShader(GLuint program,
                                  GLuint shader)
{
    if (program != 0 && shader != 0)
    {
        glDetachShader(program, shader);
        glDeleteShader(shader);
    }
}

void ShaderProgram::destroyProgram(GLuint program)
{
    if (program != 0)
    {
        glDeleteProgram(program);
    }
}

ShaderProgram::ShaderProgram():
    vertexShader_(0),
    fragShader_(0),
    program_(0)
{
}

ShaderProgram::ShaderProgram(const std::string &vertexShaderSrc,
                             const std::string &fragShaderSrc):
    ShaderProgram()
{
    load(vertexShaderSrc, fragShaderSrc);
}

ShaderProgram::~ShaderProgram()
{
    destroyShader(program_, vertexShader_);
    destroyShader(program_, fragShader_);
    destroyProgram(program_);
}

void ShaderProgram::load(const std::string &vertexShaderSrc,
                         const std::string &fragShaderSrc)
{
    vertexShader_ = createShader(GL_VERTEX_SHADER, vertexShaderSrc);
    fragShader_ = createShader(GL_FRAGMENT_SHADER, fragShaderSrc);
    program_ = createProgram(vertexShader_, fragShader_);
}

void ShaderProgram::use()
{
    glUseProgram(program_);
}

} // end of namespace opgl

