#include "quick.h"
#include <cstdlib>
#include <ctime>

int partition(std::vector<int>& arr, int low, int high, long long& ops) {
    
    int random = low + rand() % (high - low + 1);
    
    int temp = arr[random];
    arr[random] = arr[high];
    arr[high] = temp;
    ops += 3;
    
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        ops++; 
        if (arr[j] <= pivot) {
            i++;
            
            int temp2 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp2;
            ops += 3;
        }
    }
    
    int temp3 = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp3;
    ops += 3;
    
    return i + 1;
}

void quickSortHelper(std::vector<int>& arr, int low, int high, long long& ops) {
    if (low < high) {
        int pi = partition(arr, low, high, ops);
        quickSortHelper(arr, low, pi - 1, ops);
        quickSortHelper(arr, pi + 1, high, ops);
    }
}

void quickSort(std::vector<int>& arr, long long& operations) {
    operations = 0;
    quickSortHelper(arr, 0, arr.size() - 1, operations);
}
