#include <sphere_app.h>

namespace sphere {

std::shared_ptr<SphereApp> SphereApp::instance_;

void SphereApp::initInstance(const std::string& vertexShaderFile,
                             const std::string& fragShaderFile,
                             const std::string& configFile)
{
    if (!instance_)
    {
        instance_.reset(new SphereApp(vertexShaderFile, fragShaderFile, configFile));
    }
}

SphereApp::SphereApp(const std::string& vertexShaderFile,
              const std::string& fragShaderFile,
              const std::string& configFile)
    : App(800, 800, "Sphere Lighting")
{
}

SphereApp::~SphereApp()
{
}

void SphereApp::process()
{
}


} // end of namespace sphere

