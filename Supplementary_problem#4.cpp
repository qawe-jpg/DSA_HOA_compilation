#include <iostream>
using namespace std;

int binarySearch(int arr[], int length, int target) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        cout << "Check index " << mid << " with value " << arr[mid] << endl;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            cout << "Value is smaller than " << target << ", look right side" << endl;
            left = mid + 1;
        }
        else {
            cout << "Value is bigger than " << target << ", look left side" << endl;
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int sortedArray[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int length = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int key = 8;

    cout << "Start searching for " << key << " in the list." << endl;

    int index = binarySearch(sortedArray, length, key);

    if (index != -1) {
        cout << "Found " << key << " at index " << index << "!" << endl;
    }
    else {
        cout << key << " is not in the list." << endl;
    }

    return 0;
}

