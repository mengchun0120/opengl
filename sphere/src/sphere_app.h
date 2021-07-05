#ifndef INCLUDE_SPHERE_APP_H
#define INCLUDE_SPHERE_APP_H

#include <string>
#include <memory>
#include <sharedlib_app.h>

namespace sphere {

class SphereApp: public sharedlib::App {
public:
    static void initInstance(const std::string& vertexShaderFile,
                             const std::string& fragShaderFile,
                             const std::string& configFile);

    static std::shared_ptr<SphereApp> getInstance()
    {
        return instance_;
    }

    ~SphereApp() override;

private:
    SphereApp(const std::string& vertexShaderFile,
              const std::string& fragShaderFile,
              const std::string& configFile);

    void process() override;

private:
    static std::shared_ptr<SphereApp> instance_;
};

} // end of namespace sphere

#endif

