#include "utils.h"
#include "bubble.h"
#include "merge.h"
#include "quick.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100000);
    for (int i = 0; i < size; i++) arr[i] = dis(gen);
    return arr;
}

vector<int> generateSortedArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) arr[i] = i + 1;
    return arr;
}

vector<int> generateReverseSortedArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) arr[i] = size - i;
    return arr;
}

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

vector<int> copyArray(const std::vector<int>& arr) {
    vector<int> copy(arr.size());
    for (size_t i = 0; i < arr.size(); i++) copy[i] = arr[i];
    return copy;
}

void testOneAlgorithm(void (*sortFunc)(std::vector<int>&, long long&), 
                      const string& name,
                      const vector<int>& data,
                      int size) {
    vector<int> arr = copyArray(data);
    long long ops = 0;
    
    auto start = high_resolution_clock::now();
    sortFunc(arr, ops);
    auto end = high_resolution_clock::now();
    
    double time = duration<double, milli>(end - start).count();
    
    cout << left << setw(10) << name
         << setw(8) << size
         << setw(12) << fixed << setprecision(3) << time
         << setw(15) << ops
         << (isSorted(arr) ? "PASS" : "FAIL") << endl;
}

void runTests(int size) {
    cout << "\n" << string(55, '=') << endl;
    cout << "  SIZE: " << size << endl;
    cout << string(55, '=') << endl;
    
    vector<int> randomData = generateRandomArray(size);
    vector<int> sortedData = generateSortedArray(size);
    vector<int> reverseData = generateReverseSortedArray(size);
    
    cout << "\n[RANDOM DATA]" << endl;
    cout << "Algorithm  Size    Time(ms)   Operations     Status" << endl;
    cout << string(55, '-') << endl;
    testOneAlgorithm(bubbleSort, "Bubble", randomData, size);
    testOneAlgorithm(mergeSort, "Merge", randomData, size);
    testOneAlgorithm(quickSort, "Quick", randomData, size);
    
    cout << "\n[SORTED DATA]" << endl;
    cout << "Algorithm  Size    Time(ms)   Operations     Status" << endl;
    cout << string(55, '-') << endl;
    testOneAlgorithm(bubbleSort, "Bubble", sortedData, size);
    testOneAlgorithm(mergeSort, "Merge", sortedData, size);
    testOneAlgorithm(quickSort, "Quick", sortedData, size);
    
    cout << "\n[REVERSE DATA]" << endl;
    cout << "Algorithm  Size    Time(ms)   Operations     Status" << endl;
    cout << string(55, '-') << endl;
    testOneAlgorithm(bubbleSort, "Bubble", reverseData, size);
    testOneAlgorithm(mergeSort, "Merge", reverseData, size);
    testOneAlgorithm(quickSort, "Quick", reverseData, size);
    
    cout << "\n" << string(55, '=') << endl;
}

void runSingleTest() {
    int choice, size, dataType;
    
    cout << "\n" << string(50, '=') << endl;
    cout << "  CUSTOM TEST" << endl;
    cout << string(50, '=') << endl;
    
    cout << "Enter array size: ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid size! Using size 10." << endl;
        size = 10;
    }
    
    cout << "\nSelect data type:" << endl;
    cout << "1. Random" << endl;
    cout << "2. Sorted" << endl;
    cout << "3. Reverse Sorted" << endl;
    cout << "Enter choice (1-3): ";
    cin >> dataType;
    
    vector<int> testData;
    switch(dataType) {
        case 1: testData = generateRandomArray(size); break;
        case 2: testData = generateSortedArray(size); break;
        case 3: testData = generateReverseSortedArray(size); break;
        default: 
            cout << "Invalid choice! Using Random." << endl;
            testData = generateRandomArray(size);
    }
    
    cout << "\nSelect sorting algorithm:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Merge Sort" << endl;
    cout << "3. Quick Sort" << endl;
    cout << "4. Test All" << endl;
    cout << "Enter choice (1-4): ";
    cin >> choice;
    
    cout << "\n" << string(50, '=') << endl;
    
    switch(choice) {
        case 1:
            cout << "\nTesting Bubble Sort..." << endl;
            testOneAlgorithm(bubbleSort, "Bubble", testData, size);
            break;
        case 2:
            cout << "\nTesting Merge Sort..." << endl;
            testOneAlgorithm(mergeSort, "Merge", testData, size);
            break;
        case 3:
            cout << "\nTesting Quick Sort..." << endl;
            testOneAlgorithm(quickSort, "Quick", testData, size);
            break;
        case 4:
            cout << "\nTesting All Algorithms..." << endl;
            cout << "Algorithm  Size    Time(ms)   Operations     Status" << endl;
            cout << string(55, '-') << endl;
            testOneAlgorithm(bubbleSort, "Bubble", testData, size);
            testOneAlgorithm(mergeSort, "Merge", testData, size);
            testOneAlgorithm(quickSort, "Quick", testData, size);
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}
