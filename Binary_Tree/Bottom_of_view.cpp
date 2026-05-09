#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
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

void solve(Node* root, int hd, int level, map<int, pair<int, int>>& m) {
    if (root == NULL) return;

    // If HD is not in map OR current node is at a deeper/equal level
    if (m.find(hd) == m.end() || level >= m[hd].second) {
        m[hd] = {root->data, level};
    }

    // Standard DFS: Traverse left and right
    solve(root->left, hd - 1, level + 1, m);
    solve(root->right, hd + 1, level + 1, m);
}

void bottomView(Node* root) {
    // Map stores: Horizontal Distance -> {Node Data, Level}
    map<int, pair<int, int>> m;
    
    solve(root, 0, 0, m);

    // Print the map contents
    for (auto i : m) {
        cout << i.second.first << " ";
    }
    cout << endl;
}
int main(){
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root = buildTree(preorder);

    bottomView(root);

    return 0;
}