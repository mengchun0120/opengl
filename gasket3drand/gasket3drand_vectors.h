#ifndef INCLUDE_GASKET3DRAND_VECTORS_H
#define INCLUDE_GASKET3DRAND_VECTORS_H

#include <array>
#include "sharedlib_vector.h"

namespace gasket3drand {

class Gasket3DRandVectors final {
public:
    Gasket3DRandVectors(const std::array<sharedlib::Vector3, 4>& tetra,
                        const sharedlib::Vector3& initPoint,
                        unsigned int numPoints);

    ~Gasket3DRandVectors();

    unsigned int numPoints() const noexcept
    {
        return numPoints_;
    }

    const sharedlib::Vector3 *data() const noexcept
    {
        return data_;
    }

private:
    unsigned int numPoints_;
    sharedlib::Vector3 *data_;
};

} // end of namespace gasket3drand

#endif

