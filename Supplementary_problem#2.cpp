#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* createList(int elements[], int length) {
    if (length == 0) return nullptr;
    Node* head = new Node{elements[0], nullptr};
    Node* currentNode = head;
    for (int i = 1; i < length; ++i) {
        currentNode->next = new Node{elements[i], nullptr};
        currentNode = currentNode->next;
    }
    return head;
}

int countOccurrencesArray(int elements[], int length, int key, int &compCount) {
    compCount = 0;
    int count = 0;
    for (int i = 0; i < length; ++i) {
        ++compCount;
        if (elements[i] == key) ++count;
    }
    return count;
}

int countOccurrencesList(Node* head, int key, int &compCount) {
    compCount = 0;
    int count = 0;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        ++compCount;
        if (curr->value == key) ++count;
    }
    return count;
}

int main() {
    int elements[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int length = sizeof(elements) / sizeof(elements[0]);
    int key = 18;
    int arrayComparisons = 0, listComparisons = 0;

    Node* head = createList(elements, length);

    int countInArray = countOccurrencesArray(elements, length, key, arrayComparisons);
    int countInList = countOccurrencesList(head, key, listComparisons);

    cout << "Array: Key " << key << " occurs " << countInArray << " times with " << arrayComparisons << " comparisons.\n";
    cout << "Linked List: Key " << key << " occurs " << countInList << " times with " << listComparisons << " comparisons.\n";

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

