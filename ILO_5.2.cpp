#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int maxSize;
    int head;
    int tail;
    int count;

public:
    CircularQueue(int capacity) {
        maxSize = capacity;
        arr = new int[maxSize];
        head = 0;
        tail = maxSize - 1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == maxSize;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! " << value << endl;
            return;
        }
        tail = (tail + 1) % maxSize;
        arr[tail] = value;
        count++;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! " << endl;
            return;
        }
        cout << "Dequeued: " << arr[head] << endl;
        head = (head + 1) % maxSize;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue contents: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(head + i) % maxSize] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); 
    q.display();

    return 0;
}

