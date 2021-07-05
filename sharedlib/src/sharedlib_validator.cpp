#include <sharedlib_validator.h>

namespace sharedlib {

Validator operator&&(const Validator& a, const Validator& b)
{
    Validator v;

    v.setVerifyFunc(
        [&]()->bool
        {
            return a() && b();
        }
    );

    v.setRuleFunc(
        [&]()->std::string
        {
            std::ostringstream oss;
            oss << "(" << a.rule() << " && " << b.rule() << ")";
            return oss.str();
        }
    );

    return v;
}

Validator operator||(const Validator& a, const Validator& b)
{
    Validator v;

    v.setVerifyFunc(
        [&]()->bool
        {
            return a() || b();
        }
    );

    v.setRuleFunc(
        [&]()->std::string
        {
            std::ostringstream oss;
            oss << "(" << a.rule() << " || " << b.rule() << ")";
            return oss.str();
        }
    );

    return v;
}

Validator operator!(const Validator& a)
{
    Validator v;

    v.setVerifyFunc(
        [&]()->bool
        {
            return !a();
        }
    );

    v.setRuleFunc(
        [&]()->std::string
        {
            std::ostringstream oss;
            oss << "!" << a.rule();
            return oss.str();
        }
    );

    return v;
}

} // end of namespace sharedlib

