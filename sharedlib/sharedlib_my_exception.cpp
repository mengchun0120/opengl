#include "sharedlib_my_exception.h"

namespace sharedlib {

MyException::MyException(const std::string &file,
                         unsigned int line,
                         const std::string &message) noexcept:
    file_(file),
    line_(line)
{
    msg_ = "Exception occurred at " + file_ + ":" + std::to_string(line_) +
           " :" + message;
}

} // end of namespace sharedlib

