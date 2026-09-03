#include "utils.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void showComplexity() {
    cout << "\n" << string(65, '=') << endl;
    cout << "  TIME COMPLEXITY COMPARISON" << endl;
    cout << string(65, '=') << endl;
    cout << left << setw(15) << "Algorithm"
         << setw(18) << "Best"
         << setw(18) << "Average"
         << setw(18) << "Worst" << endl;
    cout << string(65, '-') << endl;
    cout << left << setw(15) << "Bubble Sort"
         << setw(18) << "O(n)"
         << setw(18) << "O(n^2)"
         << setw(18) << "O(n^2)" << endl;
    cout << left << setw(15) << "Merge Sort"
         << setw(18) << "O(n log n)"
         << setw(18) << "O(n log n)"
         << setw(18) << "O(n log n)" << endl;
    cout << left << setw(15) << "Quick Sort"
         << setw(18) << "O(n log n)"
         << setw(18) << "O(n log n)"
         << setw(18) << "O(n^2)" << endl;
    cout << string(65, '=') << endl;
}

void showMenu() {
    cout << "\n" << string(50, '=') << endl;
    cout << "  MAIN MENU" << endl;
    cout << string(50, '=') << endl;
    cout << "1. Run Custom Test (Your input)" << endl;
    cout << "2. Run Predefined Tests" << endl;
    cout << "3. Show Complexity Comparison" << endl;
    cout << "4. Exit" << endl;
    cout << string(50, '=') << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    srand(time(0));
    
    int choice;
    do {
        showMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                runSingleTest();
                break;
            case 2:
                cout << "\nRunning Predefined Tests..." << endl;
                cout << string(50, '=') << endl;
                runTests(10);
                runTests(100);
                runTests(1000);
                cout << "\nPredefined tests completed!" << endl;
                break;
            case 3:
                showComplexity();
                break;
            case 4:
                cout << "\nThank you for using Sorting Algorithm Analyzer!" << endl;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}