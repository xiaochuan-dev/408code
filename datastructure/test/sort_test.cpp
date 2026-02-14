#include <gtest/gtest.h>
#include <print>
#include "sort.h"

TEST(SortTest, testInsertSort)
{
    int arr[] = {2, 1, 3, 5, 4};

    datastructure::insertSort(arr, sizeof(arr) / sizeof(int));

}
