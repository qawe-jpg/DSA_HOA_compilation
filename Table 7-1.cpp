#include <iostream>
#include <cstdlib>  
#include <ctime>   
#include "sort_algorithms.h"

using namespace std;

const int SIZE = 100;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int original[SIZE];
    int arr[SIZE];

    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        original[i] = rand() % 1000; 
    }

    cout << "Original Array:\n";
    printArray(original, SIZE);

    copyArray(original, arr, SIZE);
    selectionSort(arr, SIZE);
    cout << "\nArray after Selection Sort:\n";
    printArray(arr, SIZE);

    copyArray(original, arr, SIZE);
    bubbleSort(arr, SIZE);
    cout << "\nArray after Bubble Sort:\n";
    printArray(arr, SIZE);

    copyArray(original, arr, SIZE);
    insertionSort(arr, SIZE);
    cout << "\nArray after Insertion Sort:\n";
    printArray(arr, SIZE);

    copyArray(original, arr, SIZE);
    mergeSort(arr, 0, SIZE - 1);
    cout << "\nArray after Merge Sort:\n";
    printArray(arr, SIZE);

    return 0;
}