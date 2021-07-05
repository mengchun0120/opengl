#ifndef INCLUDE_SHAREDLIB_RANDOM_UTILS_H
#define INCLUDE_SHAREDLIB_RANDOM_UTILS_H

#include <random>
#include <algorithm>

namespace sharedlib {

template <typename T>
void shuffle(T& t)
{
    const int sz = static_cast<int>(t.size());
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(0, 1);

    for (int i = 0; i < sz - 1; ++i)
    {
        int j = i + static_cast<int>(distrib(gen) * (sz - i));
        if (i != j)
        {
            std::swap(t[i], t[j]);
        }
    }
}

} // end of namespace sharedlib

#endif

