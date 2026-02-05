#include "Stack.h"
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
    auto r1 = datastructure::parenMatch(std::string{ "(()[[]])" });
    EXPECT_EQ(r1, true);

    auto r2 = datastructure::parenMatch(std::string{ "([()[]])" });
    EXPECT_EQ(r2, true);

    auto r3 = datastructure::parenMatch(std::string{ "[(()[]])" });
    EXPECT_EQ(r3, false);
}
