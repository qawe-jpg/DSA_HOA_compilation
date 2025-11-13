#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <iostream>
using namespace std;

template <typename T>
void insertionSort(T arr[], const int N) {
    int K = 1;   
    while (K < N) {
        T temp = arr[K];  
        int J = K - 1;    

        while (J >= 0 && arr[J] > temp) {
            arr[J + 1] = arr[J];
            J--;
        }

        arr[J + 1] = temp;
        K++;
    }
}

#endif
