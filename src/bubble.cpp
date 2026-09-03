#include "bubble.h"

void bubbleSort(std::vector<int>& arr, long long& operations) {
    int n = arr.size();
    operations = 0;
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            operations++; // Count comparison
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                operations += 3; 
            }
        }
        if (!swapped) break; 
    }
}
