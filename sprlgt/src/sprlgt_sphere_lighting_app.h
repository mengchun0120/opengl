#ifndef INCLUDE_SPRLGT_SPHERE_LIGHTING_APP_H
#define INCLUDE_SPRLGT_SPHERE_LIGHTING_APP_H

#include <string>
#include <memory>
#include <sharedlib_app.h>

namespace sprlgt {

class SphereLightingApp: public sharedlib::App {
public:
    static void initInstance(const std::string& vertexShaderFile,
                             const std::string& fragShaderFile,
                             const std::string& configFile);

    static std::shared_ptr<SphereLightingApp> getInstance()
    {
        return instance_;
    }

    ~SphereLightingApp() override;

private:
    SphereLightingApp(const std::string& vertexShaderFile,
                      const std::string& fragShaderFile,
                      const std::string& configFile);

    void process() override;

private:
    static std::shared_ptr<SphereLightingApp> instance_;
};

} // end of namespace sprlgt

#endif

