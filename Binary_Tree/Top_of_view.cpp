#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

void topView(Node* root) {
    queue<pair<Node*, int >> q;
    map<int, int> m;
    q.push({root, 0});

    while(q.size() > 0){
        Node* curr = q.front().first;
        int currHd = q.front().second;
        
        q.pop();

        if(m.find(currHd) == m.end()){
            m[currHd] = curr->data;
        }

        if(curr -> left != NULL){
            q.push({curr -> left, currHd - 1});
        }
        if(curr -> right != NULL){
            q.push({curr -> right, currHd + 1});
        }

        
    }
    for(auto i : m){
        cout << i.second << " ";
    }
    cout << endl;
}

int main(){
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    Node* root = buildTree(preorder);

    topView(root);

    return 0;
}