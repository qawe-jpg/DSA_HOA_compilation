#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

int totalSum = 0;
mutex mtx;

void partialSum(vector<int>& arr, int start, int end) {
    int localSum = 0;
    for (int i = start; i < end; ++i)
        localSum += arr[i];
    lock_guard<mutex> lock(mtx);
    totalSum += localSum;
}

int main() {
    vector<int> numbers = {1,2,3,4,5,6,7,8,9};
    int n = numbers.size();

    thread t1(partialSum, ref(numbers), 0, n/3);
    thread t2(partialSum, ref(numbers), n/3, 2*n/3);
    thread t3(partialSum, ref(numbers), 2*n/3, n);

    t1.join();
    t2.join();
    t3.join();

    cout << "Total Sum of array using threads: " << totalSum << endl;
    return 0;
}
