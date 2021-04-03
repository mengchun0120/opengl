#include <fstream>
#include <sstream>
#include "sharedlib_my_exception.h"
#include "sharedlib_file_utils.h"

namespace sharedlib {

std::string readFile(const std::string &fileName)
{
    std::ifstream in(fileName);

    if (!in)
    {
        THROW_EXCEPT("Failed to open file " + fileName);
    }

    std::stringstream ss;
    ss << in.rdbuf();

    if (in.bad())
    {
        THROW_EXCEPT("Failed to read file " + fileName);
    }

    return ss.str();
}

} // end of namespace sharedlib

