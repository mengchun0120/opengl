#ifndef INCLUDE_OPGL_MY_EXCEPTION_H
#define INCLUDE_OPGL_MY_EXCEPTION_H

#include <exception>
#include <string>

namespace sharedlib {

class MyException: public std::exception {
public:
    MyException(const std::string &file,
                unsigned int line,
                const std::string &message) noexcept;

    const char *what() const noexcept override
    {
        return msg_.c_str();
    }

    const std::string &file() const noexcept
    {
        return file_;
    }

    unsigned int line() const noexcept
    {
        return line_;
    }

private:
    std::string file_;
    unsigned int line_;
    std::string msg_;
};

#define THROW_EXCEPT(msg) \
    throw sharedlib::MyException(__FILE__, __LINE__, (msg));

} // end of namespace sharedlib

#endif

