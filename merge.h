#ifndef MERGE_H
#define MERGE_H

#include <iostream>
using namespace std;

// Function to combine two sorted parts of the array
void combine(int a[], int low, int mid, int high) {
    int n1 = mid - low + 1;   // size of left subarray
    int n2 = high - mid;      // size of right subarray

    int leftArr[n1], rightArr[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = a[low + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = a[mid + 1 + j];

    // Merge the two temporary arrays back into a[]
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            a[k] = leftArr[i];
            i++;
        } else {
            a[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements
    while (i < n1) {
        a[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive merge sort function
void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Sort first half
        mergeSort(a, low, mid);

        // Sort second half
        mergeSort(a, mid + 1, high);

        // Combine the sorted halves
        combine(a, low, mid, high);
    }
}

// Function to display the array
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

#endif
