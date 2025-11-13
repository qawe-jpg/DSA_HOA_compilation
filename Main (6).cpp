#include<iostream>
using namespace std;

const int maxCap = 100;
char stack[maxCap];
int top = -1;

void push(char c) {
    if (top >= maxCap - 1) {
        cout << "Stack Overflow.\n";
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

bool isEmpty() {
    return top == -1;
}

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

void checkBalancedSymbols_Array(const string& expr) {
    top = -1; // reset for each new expression
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) {
                cout << "Error: Extra closing symbol '" << ch << "' at position " << i << endl;
                return;
            }
            char topSymbol = pop();
            if (!isMatchingPair(topSymbol, ch)) {
                cout << "Error: Mismatched symbol '" << ch << "' at position " << i << endl;
                return;
            }
        }
    }

    if (!isEmpty()) {
        cout << "Error: Unmatched opening symbols remain.\n";
    } else {
        cout << "Expression is balanced.\n";
    }
}

int main() {
    string expr;
    cout << "Enter expression to check (Array Stack): ";
    cin >> expr;
    checkBalancedSymbols_Array(expr);
    return 0;
}
