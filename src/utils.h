#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

std::vector<int> generateRandomArray(int size);
std::vector<int> generateSortedArray(int size);
std::vector<int> generateReverseSortedArray(int size);
bool isSorted(const std::vector<int>& arr);
std::vector<int> copyArray(const std::vector<int>& arr);
void testOneAlgorithm(void (*sortFunc)(std::vector<int>&, long long&), 
                      const std::string& name,
                      const std::vector<int>& data,
                      int size);
void runTests(int size);
void runSingleTest();

#endif
