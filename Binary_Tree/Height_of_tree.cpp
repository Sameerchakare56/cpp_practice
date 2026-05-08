#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// 2. Helper function to build the tree from preorder vector
// Uses a static index to track position during recursion
int idx = -1;
Node* buildTree(vector<int> preorder) {
    idx++;
    
    // Base case: if we hit -1 or end of vector, return NULL
    if (idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }

    Node* newNode = new Node(preorder[idx]);
    newNode->left = buildTree(preorder);
    newNode->right = buildTree(preorder);

    return newNode;
}

// 3. Function to calculate Height
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Height is the max depth of either subtree plus the current node
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    // -1 represents NULL nodes in the preorder traversal
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    
    Node* root = buildTree(preorder);

    cout << "The height of the tree is: " << height(root) << endl;

    return 0;
}