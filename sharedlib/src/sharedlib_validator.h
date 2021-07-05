#ifndef INCLUDE_SHAREDLIB_VALIDATOR
#define INCLUDE_SHAREDLIB_VALIDATOR

#include <functional>
#include <string>
#include <sstream>

namespace sharedlib {

class Validator {
public:
    using VerifyFunc = std::function<bool(void)>;
    using RuleFunc = std::function<std::string(void)>;

    Validator() = default;

    Validator(const Validator& v) = default;

    void setVerifyFunc(VerifyFunc func)
    {
        verifyFunc_ = func;
    }

    bool operator()() const
    {
        return verifyFunc_ ? verifyFunc_() : true;
    }

    void setRuleFunc(RuleFunc func)
    {
        ruleFunc_ = func;
    }

    std::string rule() const
    {
        return ruleFunc_ ? ruleFunc_() : std::string();
    }

private:
    VerifyFunc verifyFunc_;
    RuleFunc ruleFunc_;
};

template <typename T, typename U>
Validator eq(const T& t, const U& e)
{
    Validator v;

    v.setVerifyFunc(
        [&]()->bool
        {
            return t == e;
        }
    );

    v.setRuleFunc(
        [&]()->std::string
        {
            std::ostringstream oss;
            oss << "(" << t << " == " << e << ")";
            return oss.str();
        }
    );

    return v;
}

template <typename T, typename U>
Validator ne(const T& t, const U& e)
{
    Validator v;

    v.setVerifyFunc(
        [&]()->bool
        {
            return t != e;
        }
    );

    v.setRuleFunc(
        [&]()->std::string
        {
            std::ostringstream oss;
            oss << "(" << t << " != " << e << ")";
            return oss.str();
        }
    );

    return v;
}

template <typename T, typename U>
Validator lt(const T& t, const U& upper)
{
    Validator v;

    v.setVerifyFunc(
        [&]()->bool
        {
            return t < upper;
        }
    );

    v.setRuleFunc(
        [&]()->std::string
        {
            std::ostringstream oss;
            oss << "(" << t << " < " << upper << ")";
            return oss.str();
        }
    );

    return v;
}

template <typename T, typename U>
Validator le(const T& t, const U& upper)
{
    Validator v;

    v.setVerifyFunc(
        [&]()->bool
        {
            return t <= upper;
        }
    );

    v.setRuleFunc(
        [&]()->std::string
        {
            std::ostringstream oss;
            oss << "(" << t << " <= " << upper << ")";
            return oss.str();
        }
    );

    return v;
}

template <typename T, typename U>
Validator gt(const T& t, const U& lower)
{
    Validator v;

    v.setVerifyFunc(
        [&]()->bool
        {
            return t > lower;
        }
    );

    v.setRuleFunc(
        [&]()->std::string
        {
            std::ostringstream oss;
            oss << "(" << t << " > " << lower << ")";
            return oss.str();
        }
    );

    return v;
}

template <typename T, typename U>
Validator ge(const T& t, const U& lower)
{
    Validator v;

    v.setVerifyFunc(
        [&]()->bool
        {
            return t >= lower;
        }
    );

    v.setRuleFunc(
        [&]()->std::string
        {
            std::ostringstream oss;
            oss << "(" << t << " >= " << lower << ")";
            return oss.str();
        }
    );

    return v;
}

Validator operator&&(const Validator& a, const Validator& b);

Validator operator||(const Validator& a, const Validator& b);

Validator operator!(const Validator& a);

} // end of namespace sharedlib

#endif

