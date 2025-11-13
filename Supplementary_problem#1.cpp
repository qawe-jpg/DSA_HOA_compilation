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

int searchArray(int elements[], int length, int key, int &compCount) {
    compCount = 0;
    for (int i = 0; i < length; ++i) {
        ++compCount;
        if (elements[i] == key) return i;
    }
    return -1;
}

int searchList(Node* head, int key, int &compCount) {
    compCount = 0;
    int position = 0;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        ++compCount;
        if (curr->value == key) return position;
        ++position;
    }
    return -1;
}

int main() {
    int elements[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int length = sizeof(elements) / sizeof(elements[0]);
    int key = 18;
    int arrayComparisons = 0, listComparisons = 0;

    Node* head = createList(elements, length);

    int posInArray = searchArray(elements, length, key, arrayComparisons);
    int posInList = searchList(head, key, listComparisons);

    if (posInArray != -1)
        cout << "Array: Found " << key << " at index " << posInArray << " after " << arrayComparisons << " comparisons.\n";
    else
        cout << "Array: " << key << " not found after " << arrayComparisons << " comparisons.\n";

    if (posInList != -1)
        cout << "Linked List: Found " << key << " at node " << posInList << " after " << listComparisons << " comparisons.\n";
    else
        cout << "Linked List: " << key << " not found after " << listComparisons << " comparisons.\n";

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

