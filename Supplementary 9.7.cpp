#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node();
    temp->value = val;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->value)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

int main() {
    Node* root = NULL;
    int arr[] = {2, 3, 9, 18, 0, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Inserting values into the Binary Search Tree:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        root = insert(root, arr[i]);
    }

    cout << "\n\nTree Traversals:\n";
    cout << "In-order Traversal (L, Root, R): ";
    inorder(root);
    cout << "\nPre-order Traversal (Root, L, R): ";
    preorder(root);
    cout << "\nPost-order Traversal (L, R, Root): ";
    postorder(root);
    cout << "\n";

    return 0;
}
