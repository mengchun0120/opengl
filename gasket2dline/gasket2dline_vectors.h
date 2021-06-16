#ifndef INCLUDE_GASKET2DLINE_VECTORS_H
#define INCLUDE_GASKET2DLINE_VECTORS_H

#include <array>
#include "sharedlib_vector.h"

namespace gasket2dline {

class Gasket2DLineVectors final {
public:
    Gasket2DLineVectors(const sharedlib::Vector2& a,
                        const sharedlib::Vector2& b,
                        const sharedlib::Vector2& c,
                        unsigned int numDivisions);

    ~Gasket2DLineVectors();

    unsigned int numPoints() const noexcept
    {
        return numPoints_;
    }

    const sharedlib::Vector2* data() const noexcept
    {
        return data_;
    }

private:
    unsigned int numPoints_;
    sharedlib::Vector2* data_;
};

} // end of namespace gasket2dline

#endif

