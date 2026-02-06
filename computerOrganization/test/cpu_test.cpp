#include "cpu.h"
#include <gtest/gtest.h>
#include <print>

TEST(CPUTEST, printCpuInfo)
{
    auto res = computerOrganization::cpuInfo();
    std::println("{}", res);
}
