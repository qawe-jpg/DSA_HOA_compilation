#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include "bubble_sort.h"  

using namespace std;

const int SIZE = 100;  

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[SIZE];

    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        numbers[i] = rand() % 1000; 
    }

    cout << "Original Array:\n";
    printArray(numbers, SIZE);

    bubbleSort(numbers, SIZE);

    cout << "\nArray After Bubble Sort:\n";
    printArray(numbers, SIZE);

    return 0;
}
