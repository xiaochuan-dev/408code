#include "Stack.h"
#include <cstring>
#include <gtest/gtest.h>

TEST(StackTest, test1)
{
    datastructure::Stack<> s;

    s.push(3);
    s.push(1);
    s.push(2);

    EXPECT_EQ(s.empty(), false);

    auto t1 = s.pop();
    auto t2 = s.pop();
    auto t3 = s.pop();
    EXPECT_EQ(t1, 2);
    EXPECT_EQ(t2, 1);
    EXPECT_EQ(t3, 3);
    EXPECT_EQ(s.empty(), true);
}

TEST(StackTest, parenMatch)
{
    auto r1 = datastructure::parenMatch(std::string{"(()[[]])"});
    EXPECT_EQ(r1, true);

    auto r2 = datastructure::parenMatch(std::string{"([()[]])"});
    EXPECT_EQ(r2, true);

    auto r3 = datastructure::parenMatch(std::string{"[(()[]])"}.c_str());
    EXPECT_EQ(r3, false);
}

TEST(StackTest, fixTest)
{
    auto s1 = datastructure::infixToSuffix(std::string{"1+2+3"});

    EXPECT_EQ(s1, "12+3+");

    auto s2 = datastructure::infixToSuffix(std::string{"8-(1+2)*2+10/2"});

    EXPECT_EQ(s2, "812+2*-102/+");

    char *s_ch1 = "8-(1+2)*2+10/2";
    char res[20];
    memset(res, 0, 20);
    datastructure::infixToSuffix(s_ch1, res);

    EXPECT_STREQ(res, "812+2*-102/+");
}