#include <iostream>
#include <algorithm>
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
    int ans = 0;

    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftHt = height(root->left);
        int rightHt = height(root->right);
        
        // Update the maximum diameter found so far
        // Diameter at this node = left height + right height
        ans = max(ans, leftHt + rightHt);
        
        // Return height of current node to the parent
        return max(leftHt, rightHt) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0; // Reset ans for multiple test cases
        height(root);
        return ans;
    }
};

// --- Test Helper Functions ---

void runTest(int testNum, TreeNode* root, int expected) {
    Solution sol;
    int result = sol.diameterOfBinaryTree(root);
    cout << "Test Case " << testNum << ": " 
         << (result == expected ? "PASSED ✅" : "FAILED ❌") 
         << " | Expected: " << expected << ", Got: " << result << endl;
}

int main() {
    // Test Case 1: Standard Balanced Tree
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    // Path: [4,2,1,3] or [5,2,1,3], Length: 3
    TreeNode* root1 = new TreeNode(1, 
                        new TreeNode(2, new TreeNode(4), new TreeNode(5)), 
                        new TreeNode(3));
    runTest(1, root1, 3);

    // Test Case 2: Linear Tree (Skewed)
    // 1-2-3-4
    TreeNode* root2 = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), nullptr), nullptr), nullptr);
    runTest(2, root2, 3);

    // Test Case 3: Only Two Nodes
    // 1-2
    TreeNode* root3 = new TreeNode(1, new TreeNode(2), nullptr);
    runTest(3, root3, 1);

    // Test Case 4: Single Node
    // 1
    TreeNode* root4 = new TreeNode(1);
    runTest(4, root4, 0);

    // Test Case 5: Empty Tree
    runTest(5, nullptr, 0);

    // Test Case 6: Diameter does NOT pass through the root
    //        1
    //       /
    //      2
    //     / \
    //    3   4
    //   /     \
    //  5       6
    // Path: [5,3,2,4,6], Length: 4
    TreeNode* root6 = new TreeNode(1);
    root6->left = new TreeNode(2);
    root6->left->left = new TreeNode(3, new TreeNode(5), nullptr);
    root6->left->right = new TreeNode(4, nullptr, new TreeNode(6));
    runTest(6, root6, 4);

    return 0;
}
