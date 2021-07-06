#ifndef INCLUDE_SPRLGT_SPHERE_LIGHTING_SHADER_PROGRAM_H
#define INCLUDE_SPRLGT_SPHERE_LIGHTING_SHADER_PROGRAM_H

#include <vector>
#include <sharedlib_matrix.h>
#include <sharedlib_vertex_array.h>
#include <sharedlib_shader_program.h>

namespace sprlgt {

class SphereLightingShaderProgram: public sharedlib::ShaderProgram {
public:
    SphereLightingShaderProgram(const std::string& vertexShaderFile,
                                const std::string& fragShaderFile);

    void setModelViewMatrix(const sharedlib::Matrix4& m);

    void setProjMatrix(const sharedlib::Matrix4& m);

    void setPositionNormal(const sharedlib::VertexArray& va);

    void setAmbientProduct(const sharedlib::Vector3& v);

    void setDiffuseProduct(const sharedlib::Vector3& v);

    void setSpecularProduct(const sharedlib::Vector3& v);

    void setLightPos(const sharedlib::Vector3& p);

    void setEyePos(const sharedlib::Vector3& p);

private:
    GLint modelViewMatrixLoc_;
    GLint projMatrixLoc_;
    GLint inPosLoc_;
    GLint inNormalLoc_;
    GLint ambientProductLoc_;
    GLint diffuseProductLoc_;
    GLint specularProductLoc_;
    GLint lightPosLoc_;
    GLint eyePosLoc_;
    GLint shinenessLoc_;
};


} // end of namespace sprlgt

#endif

