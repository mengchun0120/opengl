#include <gtest/gtest.h>
#include <sharedlib_validator.h>

TEST(TestValidator, Default)
{
    using namespace sharedlib;

    Validator v;

    EXPECT_TRUE(v());
    EXPECT_EQ(v.rule(), "");
}

TEST(TestValidator, Eq)
{
    using namespace sharedlib;

    int i = 1, j = 1;
    Validator v = eq(i, j);

    EXPECT_TRUE(v());
    EXPECT_EQ(v.rule(), "(1 == 1)");

    j = 2;
    EXPECT_FALSE(v());
    EXPECT_EQ(v.rule(), "(1 == 2)");
}

TEST(TestValidator, Ne)
{
    using namespace sharedlib;

    int i = 1, j = 2;
    Validator v = ne(i, j);

    EXPECT_TRUE(v());
    EXPECT_EQ(v.rule(), "(1 != 2)");

    j = 1;
    EXPECT_FALSE(v());
    EXPECT_EQ(v.rule(), "(1 != 1)");
}

TEST(TestValidator, Lt)
{
    using namespace sharedlib;

    int i = 1, j = 2;
    Validator v = lt(i, j);

    EXPECT_TRUE(v());
    EXPECT_EQ(v.rule(), "(1 < 2)");

    j = 0;
    EXPECT_FALSE(v());
    EXPECT_EQ(v.rule(), "(1 < 0)");
}

TEST(TestValidator, Le)
{
    using namespace sharedlib;

    int i = 1, j = 1;
    Validator v = le(i, j);

    EXPECT_TRUE(v());
    EXPECT_EQ(v.rule(), "(1 <= 1)");

    j = 0;
    EXPECT_FALSE(v());
    EXPECT_EQ(v.rule(), "(1 <= 0)");
}

TEST(TestValidator, Gt)
{
    using namespace sharedlib;

    int i = 2, j = 1;
    Validator v = gt(i, j);

    EXPECT_TRUE(v());
    EXPECT_EQ(v.rule(), "(2 > 1)");

    j = 3;
    EXPECT_FALSE(v());
    EXPECT_EQ(v.rule(), "(2 > 3)");
}

TEST(TestValidator, Ge)
{
    using namespace sharedlib;

    int i = 2, j = 1;
    Validator v = ge(i, j);

    EXPECT_TRUE(v());
    EXPECT_EQ(v.rule(), "(2 >= 1)");

    j = 3;
    EXPECT_FALSE(v());
    EXPECT_EQ(v.rule(), "(2 >= 3)");
}

TEST(TestValidator, And)
{
    using namespace sharedlib;

    int i = 1, j = 2, k = 3;
    Validator v = lt(i, j) && gt(k, j);

    EXPECT_TRUE(v());
    EXPECT_EQ(v.rule(), "((1 < 2) && (3 > 2))");

    k = 0;
    EXPECT_FALSE(v());
    EXPECT_EQ(v.rule(), "((1 < 2) && (0 > 2))");
}

TEST(TestValidator, Or)
{
    using namespace sharedlib;

    int i = 1, j = 2, k = 3;
    Validator v = lt(j, i) || gt(k, j);

    EXPECT_TRUE(v());
    EXPECT_EQ(v.rule(), "((2 < 1) || (3 > 2))");

    k = 0;
    EXPECT_FALSE(v());
    EXPECT_EQ(v.rule(), "((2 < 1) || (0 > 2))");
}

TEST(TestValidator, Not)
{
    using namespace sharedlib;

    int i = 1, j = 1;
    Validator v = !lt(j, i);

    EXPECT_TRUE(v());
    EXPECT_EQ(v.rule(), "!(1 < 1)");

    j = 0;
    EXPECT_FALSE(v());
    EXPECT_EQ(v.rule(), "!(0 < 1)");
}

TEST(TestValidator, Complex)
{
    using namespace sharedlib;

    int i = 1, j = 1, k = 2, t = 3;
    Validator v = (le(j, i) || ge(j, t)) && !eq(k, t);

    EXPECT_TRUE(v());
    EXPECT_EQ(v.rule(), "(((1 <= 1) || (1 >= 3)) && !(2 == 3))");

    t = 2;
    EXPECT_FALSE(v());
    EXPECT_EQ(v.rule(), "(((1 <= 1) || (1 >= 2)) && !(2 == 2))");
}

