#ifndef INCLUDE_SHAREDLIB_OUT_H
#define INCLUDE_SHAREDLIB_OUT_H

#include <ostream>
#include <vector>

namespace std {

template <typename T>
std::ostream& operator<<(std::ostream& os,
                         const std::vector<T>& v)
{
    os << '[';
    if (v.size() > 0)
    {
        os << v[0];
        for (std::size_t i = 1; i < v.size(); ++i)
        {
            os << ", " << v[i];
        }
    }
    os << ']';
    return os;
}

} // end of namespace std

#endif

