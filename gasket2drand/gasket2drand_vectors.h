#ifndef INCLUDE_GASKET2DRAND_VECTORS_H
#define INCLUDE_GASKET2DRAND_VECTORS_H

#include <array>
#include "sharedlib_vector.h"

namespace gasket2drand {

class Gasket2DRandVectors final {
public:
    Gasket2DRandVectors(const std::array<sharedlib::Vec2, 3> &triangle,
                        const sharedlib::Vec2 &initPoint,
                        unsigned int numPoints);

    ~Gasket2DRandVectors();

    unsigned int numPoints() const noexcept
    {
        return numPoints_;
    }

    const sharedlib::Vec2 *data() const noexcept
    {
        return data_;
    }

private:
    unsigned int numPoints_;
    sharedlib::Vec2 *data_;
};

} // end of namespace gasket2drand

#endif

