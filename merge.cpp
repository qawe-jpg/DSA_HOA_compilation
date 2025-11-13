#include "merge.h"

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Array before sorting: ";
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Array after sorting: ";
    display(arr, n);

    return 0;
}
