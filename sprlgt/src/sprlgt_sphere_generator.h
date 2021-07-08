#ifndef INCLUDE_SPRLGT_SPHERE_GENERATOR_H
#define INCLUDE_SPRLGT_SPHERE_GENERATOR_H

#include <vector>
#include <sharedlib_vector.h>

namespace sprlgt {

class SphereGenerator {
public:
    SphereGenerator() = default;

    virtual ~SphereGenerator() = default;

    virtual void generate(std::vector<sharedlib::Vector3>& vertices,
                          std::vector<sharedlib::Vector3>& normals,
                          const sharedlib::Vector3& center,
                          float radius) = 0;
};

class RecursiveSphereGenerator: public SphereGenerator {
public:
    RecursiveSphereGenerator(unsigned int numSteps=4) noexcept;

    unsigned int getNumSteps() const noexcept
    {
        return numSteps_;
    }

    void setNumSteps(unsigned int numSteps);

    void generate(std::vector<sharedlib::Vector3>& vertices,
                  std::vector<sharedlib::Vector3>& normals,
                  const sharedlib::Vector3& center,
                  float radius);

private:
    unsigned int numSteps_;
};

} // end of namespace sprlgt

#endif

