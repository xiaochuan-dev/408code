#include <gtest/gtest.h>
#include "Queue.h"

TEST(QueueTest, test1)
{
    datastructure::Queue<> q {4};
    q.enQueue(2);
    q.enQueue(1);
    q.enQueue(3);

    EXPECT_EQ(q.full(), true);

    auto f1 = q.getFront();
    auto fp1 = q.deQueue();

    EXPECT_EQ(f1, 2);
    EXPECT_EQ(fp1, 2);

    q.enQueue(4);
    EXPECT_EQ(q.full(), true);
    EXPECT_EQ(q.getFront(), 1);
    EXPECT_EQ(q.getRear(), 4);
}

