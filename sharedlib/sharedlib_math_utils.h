#ifndef INCLUDE_SHAREDLIB_MATH_UTILS_H
#define INCLUDE_SHAREDLIB_MATH_UTILS_H

#include <cmath>

namespace sharedlib {

constexpr float PI = 3.14159265359;

inline float rad(float degree)
{
    return degree / 180 * PI;
}

inline bool fuzzyEqual(float a, float b, float threshold=1.0e-6f)
{
    return fabs(a - b) <= threshold;
}

} // end of namespace sharedlib

#endif

