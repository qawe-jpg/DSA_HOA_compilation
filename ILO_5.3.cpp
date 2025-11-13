#include <iostream>
using namespace std;

class SimpleQueue {
private:
    int* data;
    int maxCapacity;
    int start;
    int end;
    int currentSize;

public:
    SimpleQueue(int cap) {
        maxCapacity = cap;
        data = new int[maxCapacity];
        start = 0;
        end = -1;
        currentSize = 0;
    }

    ~SimpleQueue() {
        delete[] data;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == maxCapacity;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        end = (end + 1) % maxCapacity;
        data[end] = val;
        currentSize++;
        cout << "Enqueued: " << val << "\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Dequeued: " << data[start] << "\n";
        start = (start + 1) % maxCapacity;
        currentSize--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < currentSize; i++) {
            cout << data[(start + i) % maxCapacity] << " ";
        }
        cout << "\n";
    }
};

int main() {
    SimpleQueue q(5);

    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(20);
    q.display();

    return 0;
}

