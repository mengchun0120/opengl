#ifndef INCLUDE_SHAREDLIB_MATH_UTILS_H
#define INCLUDE_SHAREDLIB_MATH_UTILS_H

namespace sharedlib {

constexpr float PI = 3.14159265359;

inline float rad(float degree)
{
    return degree / 180 * PI;
}

} // end of namespace sharedlib

#endif

