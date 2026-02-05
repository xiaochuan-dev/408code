#include "num.h"
#include <format>
#include <gtest/gtest.h>
#include <print>

TEST(TESTNum, testnum1)
{
    /**
     * 返回值分别是 最大值十六进制，最大值2进制，最小值十六进制，最小值2进制
     */
    auto [s1, s2, s3, s4] = computerOrganization::getInt16Duration();

    EXPECT_EQ(s1, "7fff");
    EXPECT_EQ(s2, "0111111111111111");
    EXPECT_EQ(s3, "8000");
    EXPECT_EQ(s4, "1000000000000000");
}

TEST(TESTNum, testFloat1)
{
    auto [s1, s2, s3, s4] = computerOrganization::getFloatDuration();

    /**
     * 不在这两个数的范围内即是溢出
     * 即计算过程中指数变成了全1或者全0
     */
    /**
     * 最大的浮点指数不能全为1，全为1要么是NAN要么是无穷大
     */
    EXPECT_EQ(s1, "7f7fffff");
    EXPECT_EQ(s2, "01111111011111111111111111111111");

    /**
     * 同样最小的浮点数指数页不能全为0，全为0时尾数全为0是0为非0是非规格化数
     * 这个数等于 1 * 2^{1-127} = 2^{-126}
     */
    EXPECT_EQ(s3, "00800000");
    EXPECT_EQ(s4, "00000000100000000000000000000000");
}

TEST(TESTNum, testnum2)
{
    /**
     * 有符号数和无符号数的转换，不改变存储的值，只改变解释的方式
     */
    char a = -3;

    auto s1 = std::format("{:08b}", a);

    unsigned char b = (unsigned char)a;
    auto s2 = std::format("{:08b}", b);

    EXPECT_EQ(s1, "11111101");
    EXPECT_EQ(s2, "11111101");
}

/**
 * 长转短直接高位截断
 * 短转长高位补符号位
 */
TEST(TESTNum, testnum3)
{
    short a = -3;
    auto s1 = std::format("{:016b}", std::bit_cast<unsigned short>(a));
    EXPECT_EQ(s1, "1111111111111101");

    int b = (int)a;
    auto s2 = std::format("{:032b}", std::bit_cast<unsigned int>(b));
    EXPECT_EQ(s2, "11111111111111111111111111111101");
}

TEST(TESTNum, testnum4)
{
    unsigned short a = 3;
    auto s1 = std::format("{:016b}", a);
    EXPECT_EQ(s1, "0000000000000011");

    unsigned int b = (unsigned int)a;
    auto s2 = std::format("{:032b}", b);
    EXPECT_EQ(s2, "00000000000000000000000000000011");
}

TEST(TESTNum, testnum5)
{
    int a = -3;
    auto s1 = std::format("{:032b}", std::bit_cast<unsigned int>(a));
    EXPECT_EQ(s1, "11111111111111111111111111111101");

    short b = (short)a;
    auto s2 = std::format("{:016b}", std::bit_cast<unsigned short>(b));
    EXPECT_EQ(s2, "1111111111111101");
}
