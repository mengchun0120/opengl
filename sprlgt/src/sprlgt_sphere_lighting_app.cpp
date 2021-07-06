#include <sprlgt_sphere_lighting_app.h>

namespace sprlgt {

std::shared_ptr<SphereLightingApp> SphereLightingApp::instance_;

void SphereLightingApp::initInstance(const std::string& vertexShaderFile,
                                     const std::string& fragShaderFile,
                                     const std::string& configFile)
{
    if (!instance_)
    {
        instance_.reset(new SphereLightingApp(vertexShaderFile, fragShaderFile,
                                              configFile));
    }
}

SphereLightingApp::SphereLightingApp(const std::string& vertexShaderFile,
                                     const std::string& fragShaderFile,
                                     const std::string& configFile)
    : App(800, 800, "Sphere Lighting")
{
}

SphereLightingApp::~SphereLightingApp()
{
}

void SphereLightingApp::process()
{
}


} // end of namespace sprlgt

