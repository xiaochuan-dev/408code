#include <gtest/gtest.h>
#include <print>

TEST(TESTCMEM, test)
{
    short a = 0xff00;

    auto addr1 = &a;

    auto b = std::endian::native == std::endian::little;

    std::println("");
}