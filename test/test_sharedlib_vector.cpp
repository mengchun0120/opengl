#include <sstream>
#include <iostream>
#include <gtest/gtest.h>
#include <sharedlib_vector.h>

namespace sharedlib {

class TestVector: public ::testing::Test {
public:
    Vec3 v1_, v2_;

    TestVector():
        v1_{1.0f, 2.0f, 3.0f},
        v2_{2.0f, 2.0f, 3.0f}
    {}
};

TEST_F(TestVector, VectorPlusVector)
{
    Vec3 expected{3.0f, 4.0f, 6.0f};
    EXPECT_EQ(v1_ + v2_, expected);
}

TEST_F(TestVector, VectorMinusVector)
{
    Vec3 expected{-1.0f, 0.0f, 0.0f};
    EXPECT_EQ(v1_ - v2_, expected);
}

TEST_F(TestVector, FloatTimesVector)
{
    Vec3 expected{2.0f, 4.0f, 6.0f};
    EXPECT_EQ(2.0f * v1_, expected);
}

TEST_F(TestVector, VectorTimesFloat)
{
    Vec3 expected{2.0f, 4.0f, 6.0f};
    EXPECT_EQ(v1_ * 2.0f, expected);
}

TEST_F(TestVector, VectorDividedByFloat)
{
    Vec3 expected{0.5f, 1.0f, 1.5f};
    EXPECT_EQ(v1_ / 2.0f, expected);
}

TEST_F(TestVector, VectorDotVector)
{
    EXPECT_EQ(dot(v1_, v2_), 1.0f*2.0f + 2.0f*2.0f + 3.0f*3.0f);
}

TEST_F(TestVector, VectorCrossVector)
{
    Vec3 expected{
        2.0f*3.0f - 2.0f*3.0f,
        2.0f*3.0f - 1.0f*3.0f,
        1.0f*2.0f - 2.0f*2.0f
    };
    EXPECT_EQ(cross(v1_, v2_), expected);
}

TEST_F(TestVector, OutVector)
{
    std::ostringstream out;
    out << v1_;
    std::cout << out.str() << std::endl;
    EXPECT_EQ(out.str(), "[1, 2, 3]");
}

TEST_F(TestVector, InVector)
{
    std::istringstream in("1.0 2.0 3.0");
    Vec3 expected{1.0f, 2.0f, 3.0f};
    in >> v1_;
    EXPECT_EQ(v1_, expected);
}

} // end of namespace sharedlib

