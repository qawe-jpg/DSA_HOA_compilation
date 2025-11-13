#include "myshellsort.h"

int main() {
    int data[] = {10, 55, 3, 98, 32, 17, 65};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Before Sorting:\n";
    printArray(data, size);

    shellSort(data, size);

    cout << "After Shell Sort:\n";
    printArray(data, size);

    return 0;
}
