#pragma once

namespace datastructure
{
// 插入排序
void insertSort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; j--){
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}
// 折半插入排序
void binaryInsertSort(int arr[], int n) {
    int i, j, low, high, mid;
    int temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        low = 0;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] > temp) high = mid - 1;
            else low = mid + 1;
        }
        for (j = i - 1; j >= low; j--)
            arr[j + 1] = arr[j];
        arr[low] = temp;
    }
}

void shellSort(int arr[], int n) {
    int temp, j;
    for (int dk = n / 2; dk >= 1; dk = dk / 2) {
        for (int i = dk; i < n; i++) {
            if (arr[i] < arr[i - dk]) {
                temp = arr[i];
                for (j = i - dk; j >= 0 && temp < arr[j]; j -= dk)
                    arr[j + dk] = arr[j];
                arr[j + dk] = temp;
            }
        }
    }
}
}
