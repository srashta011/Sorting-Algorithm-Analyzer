#include "merge.h"

void merge(std::vector<int>& arr, int left, int mid, int right, long long& ops) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
 
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);
    
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
        ops++;
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
        ops++;
    }
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        ops++; 
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
        ops += 3; 
    }
    
   
    while (i < n1) {
        arr[k] = leftArr[i];
        i++; k++;
        ops += 3;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++; k++;
        ops += 3;
    }
}

void mergeSortHelper(std::vector<int>& arr, int left, int right, long long& ops) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid, ops);
        mergeSortHelper(arr, mid + 1, right, ops);
        merge(arr, left, mid, right, ops);
    }
}

void mergeSort(std::vector<int>& arr, long long& operations) {
    operations = 0;
    mergeSortHelper(arr, 0, arr.size() - 1, operations);
}