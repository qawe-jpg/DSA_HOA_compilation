#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct BinaryTreeNode {
    char data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(char value) {
        data = value;
        left = right = nullptr;
    }
};

int computeHeights(BinaryTreeNode* node, vector<pair<char, int>>& heights) {
    if (!node) return -1;

    int leftHeight = computeHeights(node->left, heights);
    int rightHeight = computeHeights(node->right, heights);
    int height = max(leftHeight, rightHeight) + 1;

    heights.push_back({node->data, height});
    return height;
}

void computeDepths(BinaryTreeNode* root, vector<pair<char, int>>& depths) {
    queue<pair<BinaryTreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        BinaryTreeNode* node = q.front().first;
        int depth = q.front().second;
        q.pop();

        depths.push_back({node->data, depth});

        if (node->left) q.push({node->left, depth + 1});
        if (node->right) q.push({node->right, depth + 1});
    }
}

int main() {
    BinaryTreeNode* A = new BinaryTreeNode('A');
    A->left = new BinaryTreeNode('B');
    A->right = new BinaryTreeNode('C');

    A->left->left = new BinaryTreeNode('D');
    A->left->right = new BinaryTreeNode('E');

    A->right->left = new BinaryTreeNode('F');
    A->right->right = new BinaryTreeNode('G');

    A->left->left->left = new BinaryTreeNode('H');
    A->left->right->left = new BinaryTreeNode('I');
    A->left->right->right = new BinaryTreeNode('J');
    A->left->right->right->left = new BinaryTreeNode('P');
    A->left->right->right->right = new BinaryTreeNode('Q');

    A->right->left->left = new BinaryTreeNode('K');
    A->right->left->right = new BinaryTreeNode('L');
    A->right->right->left = new BinaryTreeNode('M');
    A->right->right->right = new BinaryTreeNode('N');

    vector<pair<char, int>> depths;
    vector<pair<char, int>> heights;

    computeDepths(A, depths);
    computeHeights(A, heights);

    sort(depths.begin(), depths.end());
    sort(heights.begin(), heights.end());

    cout << "Node\tHeight\tDepth\n";
    for (char ch = 'A'; ch <= 'Q'; ++ch) {
        if (ch == 'O') continue;

        int depth = -1, height = -1;

        for (auto& d : depths)
            if (d.first == ch) depth = d.second;

        for (auto& h : heights)
            if (h.first == ch) height = h.second;

        cout << ch << "\t" << height << "\t" << depth << "\n";
    }

    return 0;
}
