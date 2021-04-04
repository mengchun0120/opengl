#ifndef INCLUDE_GASKET2DLINE_VECTORS_H
#define INCLUDE_GASKET2DLINE_VECTORS_H

#include <array>
#include "sharedlib_vector.h"

namespace gasket2dline {

class Gasket2DLineVectors final {
public:
    Gasket2DLineVectors(const sharedlib::Vec2 &a,
                        const sharedlib::Vec2 &b,
                        const sharedlib::Vec2 &c,
                        unsigned int numDivisions);

    ~Gasket2DLineVectors();

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

} // end of namespace gasket2dline

#endif

