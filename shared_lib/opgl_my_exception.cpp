#include "opgl_my_exception.h"

namespace opgl {

MyException::MyException(const std::string &file,
                         unsigned int line,
                         const std::string &message) noexcept:
    file_(file),
    line_(line),
    message_(message)
{
}

const char *MyException::what() const noexcept
{
    std::string msg("Exception occurred at " + file_ +
                    ":" + std::to_string(line_) +
                    " :" + message_);
    return msg.c_str();
}

} // end of namespace opgl

