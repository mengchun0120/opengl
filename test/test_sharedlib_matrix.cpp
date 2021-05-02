#include <sstream>
#include <iostream>
#include <gtest/gtest.h>
#include <sharedlib_matrix.h>

namespace sharedlib {

class TestMatrix: public ::testing::Test {
public:
    Mat<2,3> m1_;
    Mat<2,3> m2_;
    Mat<3,2> m3_;
    Vec3 v1_;
    Vec2 v2_;

    TestMatrix():
        m1_{Vec3{1.0f, 2.0f, 3.0f}, Vec3{3.0f, 4.0f, 5.0f}},
        m2_{Vec3{2.0f, 3.0f, 4.0f}, Vec3{4.0f, 5.0f, 6.0f}},
        m3_{Vec2{1.0f, 2.0f}, Vec2{2.0f, 3.0f}, Vec2{3.0f, 4.0f}},
        v1_{1.0f, 2.0f, 3.0f},
        v2_{3.0f, 4.0f}
    {}
};

TEST_F(TestMatrix, MatrixPlusMatrix)
{
    Mat<2,3> expected{
        Vec3{1.0f+2.0f, 2.0f+3.0f, 3.0f+4.0f},
        Vec3{3.0f+4.0f, 4.0f+5.0f, 5.0f+6.0f}
    };
    EXPECT_EQ(m1_ + m2_, expected);
}

TEST_F(TestMatrix, MatrixMinusMatrix)
{
    Mat<2,3> expected{
        Vec3{1.0f-2.0f, 2.0f-3.0f, 3.0f-4.0f},
        Vec3{3.0f-4.0f, 4.0f-5.0f, 5.0f-6.0f}
    };
    EXPECT_EQ(m1_ - m2_, expected);
}

TEST_F(TestMatrix, FloatTimesMatrix)
{
    Mat<2,3> expected{
        Vec3{1.0f*2.0f, 2.0f*2.0f, 3.0f*2.0f},
        Vec3{3.0f*2.0f, 4.0f*2.0f, 5.0f*2.0f}
    };
    EXPECT_EQ(2.0f * m1_, expected);
}

TEST_F(TestMatrix, MatrixTimesFloat)
{
    Mat<2,3> expected{
        Vec3{1.0f*2.0f, 2.0f*2.0f, 3.0f*2.0f},
        Vec3{3.0f*2.0f, 4.0f*2.0f, 5.0f*2.0f}
    };
    EXPECT_EQ(m1_ * 2.0f, expected);
}

TEST_F(TestMatrix, MatrixTimesVector)
{
    Vec2 expected{
        1.0f*1.0f + 2.0f*2.0f + 3.0f*3.0f,
        3.0f*1.0f + 4.0f*2.0f + 5.0f*3.0f
    };
    EXPECT_EQ(m1_ * v1_, expected);
}

TEST_F(TestMatrix, VectorTimesMatrix)
{
    Vec3 expected{
        3.0f*1.0f + 4.0f*3.0f,
        3.0f*2.0f + 4.0f*4.0f,
        3.0f*3.0f + 4.0f*5.0f
    };
    EXPECT_EQ(v2_ * m1_, expected);
}

TEST_F(TestMatrix, MatrixTimesMatrix)
{
    Mat<2,2> expected{
        Vec2{
            1.0f*1.0f + 2.0f*2.0f + 3.0f*3.0f,
            1.0f*2.0f + 2.0f*3.0f + 3.0f*4.0f
        },
        Vec2{
            3.0f*1.0f + 4.0f*2.0f + 5.0f*3.0f,
            3.0f*2.0f + 4.0f*3.0f + 5.0f*4.0f
        }
    };
    EXPECT_EQ(m1_ * m3_, expected);
}

} // end of sharedlib

