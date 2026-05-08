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
    // Helper function to check if two trees are exactly the same
    bool isIdentical(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return q == p;
        }

        return (p->val == q->val) && 
               isIdentical(p->left, q->left) && 
               isIdentical(p->right, q->right);
    }

    // Main function to check if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // A null subRoot is technically a subtree, but per LeetCode standards:
        if (root == nullptr) return false;

        // If the current nodes match, check if the trees rooted here are identical
        if (root->val == subRoot->val && isIdentical(root, subRoot)) {
            return true;
        }

        // Otherwise, search in the left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

// --- Helper functions for Testing ---

// Builds a tree from level-order input (simple manual construction for clarity here)
int main() {
    Solution sol;

    /* 
       Test Case 1:
       Root: [3,4,5,1,2]
       SubRoot: [4,1,2]
       Expected: True
    */
    TreeNode* root1 = new TreeNode(3, 
                        new TreeNode(4, new TreeNode(1), new TreeNode(2)), 
                        new TreeNode(5));
    
    TreeNode* subRoot1 = new TreeNode(4, new TreeNode(1), new TreeNode(2));

    cout << "Test Case 1: " << (sol.isSubtree(root1, subRoot1) ? "Pass (True)" : "Fail") << endl;

    /* 
       Test Case 2:
       Root: [3,4,5,1,2,null,null,null,null,0]
       SubRoot: [4,1,2]
       Expected: False (because root has an extra node '0' under '2')
    */
    TreeNode* root2 = new TreeNode(3, 
                        new TreeNode(4, new TreeNode(1), new TreeNode(2, new TreeNode(0), nullptr)), 
                        new TreeNode(5));
    
    TreeNode* subRoot2 = new TreeNode(4, new TreeNode(1), new TreeNode(2));

    cout << "Test Case 2: " << (sol.isSubtree(root2, subRoot2) ? "Fail" : "Pass (False)") << endl;

    return 0;
}