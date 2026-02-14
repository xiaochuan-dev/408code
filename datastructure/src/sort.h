#pragma once

namespace datastructure
{
void insertSort(int arr[], int n){
    int i, j, temp;
    for (i = 1; i < n; i++){
        if (arr[i] < arr[i - 1]) {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; j--){
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}
}
