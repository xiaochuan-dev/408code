#include "sync.h"
#include <gtest/gtest.h>

TEST(SYNCTEST, singleFlagTest)
{
    std::println("start singleFlagTest");
    operationSystem::singleFlag();
    std::println("end singleFlagTest");
}

TEST(SYNCTEST, singleFlagTestFail)
{
    std::println("start singleFlagTestFail");
    operationSystem::singleFlagFail();
    std::println("end singleFlagTestFail");
}

TEST(SYNCTEST, twoFlagsPreCheckTest)
{
    std::println("start twoFlagsPreCheckTest");
    operationSystem::twoFlagsPreCheck();
    std::println("end twoFlagsPreCheckTest");
}

TEST(SYNCTEST, twoFlagsPreCheckTestFail)
{
    std::println("start twoFlagsPreCheckTestFail");
    operationSystem::twoFlagsPreCheckFail();
    std::println("end twoFlagsPreCheckTestFail");
}