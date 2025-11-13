#ifndef MYSHELLSORT_H
#define MYSHELLSORT_H

#include <iostream>
#include <iomanip>
using namespace std;

void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
       
        for (i = gap; i < n; i++) {
            temp = arr[i];
            j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    cout << "\nPosition | Number\n";
    cout << "-------------------\n";
    for (int i = 0; i < n; i++) {
        cout << setw(8) << i << " | " << setw(6) << arr[i] << endl;
    }
    cout << endl;
}

#endif
