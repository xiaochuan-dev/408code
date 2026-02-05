#include <print>
#include <gtest/gtest.h>
#include "cpu.h"

TEST(CPUTEST, printCpuInfo)
{
    auto res = computerOrganization::cpuInfo();
    std::println("{}", res);
}

