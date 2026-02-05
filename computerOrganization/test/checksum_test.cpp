#include "checknum.h"
#include <gtest/gtest.h>
#include <print>

TEST(TESTCHEKSUM, test1)
{
    auto [flag1, strWithCheckSum1] = computerOrganization::generateEven("01010001");

    EXPECT_EQ(flag1, 1);
    EXPECT_EQ(strWithCheckSum1, "010100011");

    auto [flag2, strWithCheckSum2] = computerOrganization::generateOdd("01010001");
    EXPECT_EQ(flag2, 0);
    EXPECT_EQ(strWithCheckSum2, "010100010");
    /**
     * 接收方和发送方使用的算法一样
     * 即生成校验码和对加了校验码的数据进行校验进行的算法一样
     * 进行校验时再进行一边校验码生成算法，这次带上了校验码，生成的新的结果1表示有错，0表示无错
     */
    auto [flag3, _] = computerOrganization::generateEven("010100011");
    EXPECT_EQ(flag3, 0);
    auto [flag4, _] = computerOrganization::generateOdd("010100010");
    EXPECT_EQ(flag4, 0);

    auto [flag5, _] = computerOrganization::generateOdd("010110010");
    EXPECT_EQ(flag5, 1);
}
