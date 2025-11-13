#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int globalVar = 0;
mutex mtx;

void add(int value) {
    lock_guard<mutex> lock(mtx);
    globalVar += value;
    cout << "Thread adding " << value << ", globalVar = " << globalVar << endl;
}

int main() {
    thread t1(add, 5);
    thread t2(add, 10);
    thread t3(add, 15);

    t1.join();
    cout << "After T1.join(), globalVar = " << globalVar << endl;

    t2.join();
    cout << "After T2.join(), globalVar = " << globalVar << endl;

    t3.join();
    cout << "After T3.join(), globalVar = " << globalVar << endl;

    cout << "Final globalVar = " << globalVar << endl;
    return 0;
}
