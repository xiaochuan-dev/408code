#include "List.h"
#include <gtest/gtest.h>

TEST(ListTest, test1)
{
    datastructure::List<> l;
    l.add(4);
    l.add(2);

    EXPECT_EQ(l.head->next->data, 4);
    EXPECT_EQ(l.head->next->next->data, 2);
}