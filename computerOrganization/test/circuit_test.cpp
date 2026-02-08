#include <gtest/gtest.h>
#include <print>
#include "circuit.h"

TEST(TESTfullAdder, test1)
{
    auto [s1, c1] = computerOrganization::fullAdder(1, 1, 0);

    EXPECT_EQ(s1, 0);
    EXPECT_EQ(c1, 1);
}


TEST(TESTserialAdder, test1)
{
    auto [s1, c1] = computerOrganization::serialAdder(std::bitset<4>{"1111"}, std::bitset<4>{"1111"}, 0);

    auto s1Str = s1.to_string();

    EXPECT_EQ(s1Str, "1110");
    EXPECT_EQ(c1, 1);
}

TEST(TESTparallelAdder, test1)
{
    auto [s1, c1] = computerOrganization::parallelAdder(std::bitset<4>{"1111"}, std::bitset<4>{"1111"}, 0);

    auto s1Str = s1.to_string();

    EXPECT_EQ(s1Str, "1110");
    EXPECT_EQ(c1, 1);
}