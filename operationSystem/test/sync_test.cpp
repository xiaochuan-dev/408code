#include <gtest/gtest.h>
#include "sync.h"

TEST(SYNCTEST, singleFlagTest) 
{
    operationSystem::singleFlag();
    operationSystem::singleFlagFail();
}
