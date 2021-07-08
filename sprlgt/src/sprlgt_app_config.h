#ifndef INCLUDE_SPRLGT_APP_CONFIG_H
#define INCLUDE_SPRLGT_APP_CONFIG_H

#include <string>
#include <sharedlib_vector.h>

namespace sprlgt {

class AppConfig {
public:
    AppConfig(const std::string& fileName);

    unsigned int width() const
    {
        return width_;
    }

    unsigned int height() const
    {
        return height_;
    }

    const std::string& title() const
    {
        return title_;
    }

    const sharedlib::Vector3& eye() const
    {
        return eye_;
    }

    const sharedlib::Vector3& at() const
    {
        return at_;
    }

    const sharedlib::Vector3& up() const
    {
        return up_;
    }

    float near() const
    {
        return near_;
    }

    float far() const
    {
        return far_;
    }

    const sharedlib::Vector3& center() const
    {
        return center_;
    }

    float radius() const
    {
        return radius_;
    }

    unsigned int numSteps() const
    {
        return numSteps_;
    }

    const sharedlib::Vector3& lightPos() const
    {
        return lightPos_;
    }

    const sharedlib::Vector3& ambientLight() const
    {
        return ambientLight_;
    }

    const sharedlib::Vector3& diffuseLight() const
    {
        return diffuseLight_;
    }

    const sharedlib::Vector3& specularLight() const
    {
        return specularLight_;
    }

    const sharedlib::Vector3& ambientReflect() const
    {
        return ambientReflect_;
    }

    const sharedlib::Vector3& diffuseReflect() const
    {
        return diffuseReflect_;
    }

    const sharedlib::Vector3& specularReflect() const
    {
        return specularReflect_;
    }

private:
    void load(const std::string& fileName);

private:
    unsigned int width_;
    unsigned int height_;
    std::string title_;
    sharedlib::Vector3 eye_;
    sharedlib::Vector3 at_;
    sharedlib::Vector3 up_;
    float near_;
    float far_;
    sharedlib::Vector3 center_;
    float radius_;
    unsigned int numSteps_;
    sharedlib::Vector3 lightPos_;
    sharedlib::Vector3 ambientLight_;
    sharedlib::Vector3 diffuseLight_;
    sharedlib::Vector3 specularLight_;
    sharedlib::Vector3 ambientReflect_;
    sharedlib::Vector3 diffuseReflect_;
    sharedlib::Vector3 specularReflect_;
};

} // end of namespace sprlgt

#endif

