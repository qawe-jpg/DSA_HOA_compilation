#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char data;
    vector<Node*> children;
};

Node* newNode(char data) {
    Node* node = new Node();
    node->data = data;
    return node;
}

// === Build the tree ===
Node* buildTree() {
    Node* A = newNode('A');
    Node* B = newNode('B');
    Node* C = newNode('C');
    Node* D = newNode('D');
    Node* E = newNode('E');
    Node* F = newNode('F');
    Node* G = newNode('G');
    Node* H = newNode('H');
    Node* I = newNode('I');
    Node* J = newNode('J');
    Node* K = newNode('K');
    Node* L = newNode('L');
    Node* M = newNode('M');
    Node* N = newNode('N');
    Node* P = newNode('P');
    Node* Q = newNode('Q');
    Node* O = newNode('O'); // new node

    A->children = {B, C, D, E, F, G};
    D->children = {H};
    E->children = {I, J};
    J->children = {P, Q};
    F->children = {K, L, M};
    G->children = {N, O}; // added O

    return A;
}

void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    for (auto c : root->children)
        preOrder(c);
}

void postOrder(Node* root) {
    if (!root) return;
    for (auto c : root->children)
        postOrder(c);
    cout << root->data << " ";
}

void inOrder(Node* root) {
    if (!root) return;
    if (!root->children.empty())
        inOrder(root->children[0]);
    cout << root->data << " ";
    for (int i = 1; i < root->children.size(); i++)
        inOrder(root->children[i]);
}

bool findData(Node* root, char key) {
    if (!root) return false;
    if (root->data == key) {
        cout << key << " was found!" << endl;
        return true;
    }
    for (auto c : root->children)
        if (findData(c, key)) return true;
    return false;
}

int main() {
    Node* root = buildTree();

    cout << "=== TREE TRAVERSALS ===" << endl;
    cout << "Pre-order: ";
    preOrder(root);
    cout << "\nPost-order: ";
    postOrder(root);
    cout << "\nIn-order: ";
    inOrder(root);

    cout << "\n\n=== FIND DATA FUNCTION ===" << endl;
    findData(root, 'O');

    return 0;
}
