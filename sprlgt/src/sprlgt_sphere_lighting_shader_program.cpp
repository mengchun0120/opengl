#include <sprlgt_sphere_lighting_shader_program.h>

namespace sprlgt {

SphereLightingShaderProgram::SphereLightingShaderProgram(
                            const std::string& vertexShaderFile,
                            const std::string& fragShaderFile)
{
    
}

void setModelViewMatrix(const sharedlib::Matrix4& m)
{
}

void setProjMatrix(const sharedlib::Matrix4& m)
{
}

void setPositionNormal(const std::vector<sharedlib::Vector3>& positions,
                       const std::vector<sharedlib::Vector3>& normals)
{
}

void setAmbientProduct(const sharedlib::Vector3& v)
{
}

void setDiffuseProduct(const sharedlib::Vector3& v)
{
}

void setSpecularProduct(const sharedlib::Vector3& v)
{
}

void setLightPos(const sharedlib::Vector3& p)
{
}

void setEyePos(const sharedlib::Vector3& p)
{
}


} // end of namespace sprlgt

