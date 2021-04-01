#include <fstream>
#include <sstream>
#include "opgl_my_exception.h"
#include "opgl_file_utils.h"

namespace opgl {

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

} // end of namespace opgl

