#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are NULL, they are the same. If only one is NULL, they aren't.
        if (p == nullptr || q == nullptr) {
            return p == q;
        }

        // Recursive check for subtrees and current node value
        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        return (p->val == q->val) && isLeftSame && isRightSame;
    }
};

// Helper function to print results
void printTestResult(int testNum, bool result, bool expected) {
    cout << "Test Case " << testNum << ": " 
         << (result == expected ? "PASSED ✅" : "FAILED ❌") 
         << " (Expected: " << (expected ? "true" : "false") 
         << ", Got: " << (result ? "true" : "false") << ")" << endl;
}

int main() {
    Solution sol;

    // --- TEST CASE 1: Identical Trees ---
    // p: [1,2,3], q: [1,2,3]
    TreeNode* p1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    printTestResult(1, sol.isSameTree(p1, q1), true);

    // --- TEST CASE 2: Different Values ---
    // p: [1,2], q: [1,null,2]
    TreeNode* p2 = new TreeNode(1, new TreeNode(2), nullptr);
    TreeNode* q2 = new TreeNode(1, nullptr, new TreeNode(2));
    printTestResult(2, sol.isSameTree(p2, q2), false);

    // --- TEST CASE 3: Different Structure ---
    // p: [1,2,1], q: [1,1,2]
    TreeNode* p3 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    TreeNode* q3 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    printTestResult(3, sol.isSameTree(p3, q3), false);

    // --- TEST CASE 4: Both Empty Trees ---
    // p: [], q: []
    printTestResult(4, sol.isSameTree(nullptr, nullptr), true);

    // --- TEST CASE 5: One Empty, One Not ---
    // p: [1], q: []
    TreeNode* p5 = new TreeNode(1);
    printTestResult(5, sol.isSameTree(p5, nullptr), false);

    // --- TEST CASE 6: Complex Deep Tree ---
    // p: [1,2,null,4], q: [1,2,null,4]
    TreeNode* p6 = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), nullptr);
    TreeNode* q6 = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), nullptr);
    printTestResult(6, sol.isSameTree(p6, q6), true);

    return 0;
}