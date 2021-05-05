#include <sstream>
#include <iostream>
#include <gtest/gtest.h>
#include <gtest/gtest_pred_impl.h>
#include <sharedlib_matrix.h>

namespace sharedlib {

class TestMatrix: public ::testing::Test {
public:
    Mat<2,3> m1_;
    Mat<2,3> m2_;
    Mat<3,2> m3_;
    Mat4 m4_;
    Vec3 v1_;
    Vec2 v2_;
    Vec4 v4_;

    TestMatrix():
        m1_{Vec3{1.0f, 2.0f, 3.0f}, Vec3{3.0f, 4.0f, 5.0f}},
        m2_{Vec3{2.0f, 3.0f, 4.0f}, Vec3{4.0f, 5.0f, 6.0f}},
        m3_{Vec2{1.0f, 2.0f}, Vec2{2.0f, 3.0f}, Vec2{3.0f, 4.0f}},
        v1_{1.0f, 2.0f, 3.0f},
        v2_{3.0f, 4.0f},
        v4_{1.0f, 2.0f, 3.0f, 1.0f}
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

TEST_F(TestMatrix, Translate)
{
    translate(m4_, 1.0f, 2.0f, 3.0f);
    Vec4 actual = m4_ * v4_;
    Vec4 expected{2.0f, 4.0f, 6.0f, 1.0f};
    EXPECT_TRUE(fuzzyEqual(actual, expected));
}

TEST_F(TestMatrix, RotateX)
{
    rotateX(m4_, 90.0f);
    Vec4 actual = m4_ * v4_;
    Vec4 expected{1.0f, -3.0f, 2.0f, 1.0f};
    EXPECT_TRUE(fuzzyEqual(actual, expected));
}

TEST_F(TestMatrix, RotateY)
{
    rotateY(m4_, 90.0f);
    Vec4 actual = m4_ * v4_;
    Vec4 expected{3.0f, 2.0f, -1.0f, 1.0f};
    EXPECT_TRUE(fuzzyEqual(actual, expected));
}

TEST_F(TestMatrix, RotateZ)
{
    rotateZ(m4_, 90.0f);
    Vec4 actual = m4_ * v4_;
    Vec4 expected{-2.0f, 1.0f, 3.0f, 1.0f};
    EXPECT_TRUE(fuzzyEqual(actual, expected));
}

TEST_F(TestMatrix, Rotate)
{
    rotate(m4_, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 3.0f, 90);
    Vec4 actual = m4_ * v4_;
    Vec4 expected{-2.0f, 1.0f, 3.0f, 1.0f};
    EXPECT_TRUE(fuzzyEqual(actual, expected));
}

} // end of sharedlib

