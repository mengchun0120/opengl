#include <sharedlib_file_utils.h>
#include <sprlgt_sphere_lighting_shader_program.h>

using namespace sharedlib;

namespace sprlgt {

SphereLightingShaderProgram::SphereLightingShaderProgram(
                            const std::string& vertexShaderFile,
                            const std::string& fragShaderFile)
    : ShaderProgram(readFile(vertexShaderFile),
                    readFile(fragShaderFile))
    , modelViewMatrixLoc_(getUniformLocation("modelViewMatrix"))
    , projMatrixLoc_(getUniformLocation("projMatrix"))
    , inPosLoc_(getAttribLocation("inPos"))
    , inNormalLoc_(getAttribLocation("inNormal"))
    , ambientProductLoc_(getUniformLocation("ambientProduct"))
    , diffuseProductLoc_(getUniformLocation("diffuseProduct"))
    , specularProductLoc_(getUniformLocation("specularProduct"))
    , lightPosLoc_(getUniformLocation("lightPos"))
    , eyePosLoc_(getUniformLocation("eyePos"))
    , shinenessLoc_(getUniformLocation("shineness"))
{
}

void SphereLightingShaderProgram::setModelViewMatrix(const Matrix4& m)
{
    glUniformMatrix4fv(modelViewMatrixLoc_, 1, GL_TRUE,
                       reinterpret_cast<const GLfloat *>(m.data()));
}

void SphereLightingShaderProgram::setProjMatrix(const Matrix4& m)
{
    glUniformMatrix4fv(projMatrixLoc_, 1, GL_TRUE,
                       reinterpret_cast<const GLfloat *>(m.data()));
}

void SphereLightingShaderProgram::setPositionNormal(const VertexArray& va)
{
    constexpr int POINT_SIZE = 3;

    glBindVertexArray(va.arrayObj());
    glBindBuffer(GL_ARRAY_BUFFER, va.bufferObj());

    glVertexAttribPointer(inPosLoc_, POINT_SIZE, GL_FLOAT, GL_FALSE,
                          va.stride(0), reinterpret_cast<void *>(0));
    glEnableVertexAttribArray(inPosLoc_);

    glVertexAttribPointer(inNormalLoc_, POINT_SIZE, GL_FLOAT, GL_FALSE,
                          va.stride(1), reinterpret_cast<void *>(va.offset(1)));
    glEnableVertexAttribArray(inNormalLoc_);
}

void SphereLightingShaderProgram::setAmbientProduct(const sharedlib::Vector3& v)
{
    glUniform3fv(ambientProductLoc_, 1, static_cast<const GLfloat*>(v.data()));
}

void SphereLightingShaderProgram::setDiffuseProduct(const sharedlib::Vector3& v)
{
    glUniform3fv(diffuseProductLoc_, 1, static_cast<const GLfloat*>(v.data()));
}

void SphereLightingShaderProgram::setSpecularProduct(const sharedlib::Vector3& v)
{
    glUniform3fv(specularProductLoc_, 1, static_cast<const GLfloat*>(v.data()));
}

void SphereLightingShaderProgram::setLightPos(const sharedlib::Vector3& p)
{
    glUniform3fv(lightPosLoc_, 1, static_cast<const GLfloat*>(p.data()));
}

void SphereLightingShaderProgram::setEyePos(const sharedlib::Vector3& p)
{
    glUniform3fv(eyePosLoc_, 1, static_cast<const GLfloat*>(p.data()));
}


} // end of namespace sprlgt

