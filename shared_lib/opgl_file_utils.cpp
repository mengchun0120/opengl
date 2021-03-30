#include <fstream>
#include <sstream>
#include <stdexcept>
#include "opgl_file_utils.h"

namespace opgl {

std::string readFile(const std::string &fileName)
{
    std::ifstream in(fileName);

    if (!in)
    {
        throw std::runtime_error("Failed to open file");
    }

    std::stringstream ss;
    ss << in.rdbuf();

    if (in.bad())
    {
        throw std::runtime_error("Failed to read file");
    }

    return ss.str();
}

} // end of namespace opgl

