#include "sharedlib_vector.h"

namespace sharedlib {

Vec3 cross(const Vec3 &lhs,
           const Vec3 &rhs)
{
    Vec3 v;
    v[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];
    v[1] = lhs[2] * rhs[0] - lhs[0] * rhs[2];
    v[2] = lhs[0] * rhs[1] - lhs[1] * rhs[0];
    return v;
}

} // end of namespace sharedlib

