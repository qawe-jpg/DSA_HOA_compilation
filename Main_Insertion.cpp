#include <iostream>
#include "insertionSort.h"
using namespace std;

int main() {
    int numbers[] = {20, 10, 50, 30, 40};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Call Insertion Sort
    insertionSort(numbers, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
