#ifndef INCLUDE_SHAREDLIB_STRINGIFY_H
#define INCLUDE_SHAREDLIB_STRINGIFY_H

#include <sstream>
#include <sharedlib_out.h>

namespace sharedlib {

template <typename T>
std::string toString(const T& v)
{
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

} // end of namespace sharedlib

#endif

