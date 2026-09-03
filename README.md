# Sorting-Algorithm-Analyzer
A C++ program that implements Bubble Sort, Merge Sort, and Quick Sort, then benchmarks their execution time across increasing input sizes to compare real-world performance against theoretical time complexity.

## Features

- Interactive menu system for custom testing
- Tests on random, sorted, and reverse-sorted data
- Measures execution time and operation counts
- Predefined test suites for quick comparison
- Complexity reference table


## Algorithms

| Algorithm | Best Case | Average Case | Worst Case | Space |
|-----------|-----------|--------------|------------|-------|
| Bubble Sort | O(n) | O(n^2) | O(n^2) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n^2) | O(log n) |


## Installation

### Compile
bash
g++ -std=c++11 -O2 src/*.cpp -o sorting_analyzer
### Run 
./sorting_analyzer


### Usage
Select from the main menu:

Custom Test - Choose size, data type, and algorithm

Predefined Tests - Run tests on sizes 10, 100, and 1000

Complexity Comparison - View theoretical complexity

Exit

This project was developed for learning purposes to implement theoretical sorting algorithms into practical C++ code.
