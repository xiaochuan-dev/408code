#include "checknum.h"
#include <gtest/gtest.h>
#include <print>

TEST(TESTCHEKSUM, test1)
{

    uint8_t num1 = 0b1010001;
    auto [flag1, numWithCheckSum1, strWithCheckSum1] =
        computerOrganization::generateEven(num1);
    EXPECT_EQ(flag1, 1);
    EXPECT_EQ(strWithCheckSum1, "10100011");

    uint8_t num2 = 0b1010001;
    auto [flag2, numWithCheckSum2, strWithCheckSum2] =
        computerOrganization::generateOdd(num2);
    EXPECT_EQ(flag2, 0);
    EXPECT_EQ(strWithCheckSum2, "10100010");
    EXPECT_EQ(numWithCheckSum2, 0b10100010);
    /**
     * 接收方和发送方使用的算法一样
     * 即生成校验码和对加了校验码的数据进行校验进行的算法一样
     * 进行校验时再进行一边校验码生成算法，这次带上了校验码，生成的新的结果1表示有错，0表示无错
     * 下面两个是接收方校验
     */

    auto [flag3, _, _] = computerOrganization::generateEven(numWithCheckSum1);
    EXPECT_EQ(flag3, 0);
    auto [flag4, _, _] = computerOrganization::generateOdd(numWithCheckSum2);
    EXPECT_EQ(flag4, 0);

    /**
     * 这是一个出错的偶检验码
     */
    uint8_t num5 = 0b10110010;
    auto [flag5, _, _] = computerOrganization::generateOdd(num5);
    EXPECT_EQ(flag5, 1);
}

TEST(TESTCHEKSUM, testCRC)
{
    uint32_t num1 = 0b11111111;
    auto [s1, outNum1, checkNum1] = computerOrganization::crc(num1);
    EXPECT_EQ(1, 1);
}
