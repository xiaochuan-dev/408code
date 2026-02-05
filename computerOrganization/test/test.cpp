#include <print>
#include <gtest/gtest.h>
#include "cpu.h"


TEST(TEST, printCpuInfo)
{
    auto res = computerOrganization::cpuInfo();
    std::println("{}", res);
}
