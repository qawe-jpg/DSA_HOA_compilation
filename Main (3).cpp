#include<iostream>
const size_t maxCap = 100;
int stack[maxCap]; // stack with max of 100 elements
int top = -1, i, newData;

void push();
void pop();
void Top();
bool isEmpty();

int main() {
    int choice;
    std::cout << "Enter number of max elements for new stack: ";
    std::cin >> i;

    while(true) {
        std::cout << "Stack Operations: " << std::endl;
        std::cout << "1. PUSH, 2. POP, 3. TOP, 4. isEMPTY" << std::endl;
        std::cin >> choice;

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                Top();
                break;
            case 4:
                std::cout << "Stack Empty? " << (isEmpty() ? "Yes" : "No") << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    }
}

// Implementation of push
void push() {
    if(top >= i - 1) {
        std::cout << "Stack Overflow." << std::endl;
        return;
    }
    std::cout << "Enter data to push: ";
    std::cin >> newData;
    stack[++top] = newData;
    std::cout << "Pushed: " << newData << std::endl;
}

// Implementation of pop
void pop() {
    // check if empty -> if yes, return error
    if(isEmpty()) {
        std::cout << "Stack Underflow." << std::endl;
        return;
    }
    // display the top value
    std::cout << "Popping: " << stack[top] << std::endl;
    // decrement top value from stack
    top--;
}

// Implementation of Top
void Top() {
    if(isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return;
    }
    std::cout << "The element on the top of the stack is " << stack[top] << std::endl;
}

// Implementation of isEmpty
bool isEmpty() {
    return top == -1;
}
