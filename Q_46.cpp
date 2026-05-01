#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void getPerms(vector<int>& nums, int idx, vector<vector<int>> &ans) {
        // Base Case: If index reaches the end, we found a valid permutation
        if (idx == nums.size()) {
            ans.push_back(nums); // Note: Simplified {nums} to nums
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            // 1. Swap: Fix one element at the current index
            swap(nums[idx], nums[i]);

            // 2. Recurse: Move to the next index
            getPerms(nums, idx + 1, ans);

            // 3. Backtrack: Swap back to restore the original state for the next loop
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms(nums, 0, ans);
        return ans;
    }
};

// Helper function to print the 2D vector
void printResult(const vector<int>& input, const vector<vector<int>>& result) {
    cout << "Input: { ";
    for (int n : input) cout << n << " ";
    cout << "}\nPermutations:\n";
    
    for (const auto& row : result) {
        cout << "[ ";
        for (int val : row) cout << val << " ";
        cout << "] ";
    }
    cout << "\n\n";
}

int main() {
    Solution sol;

    // Test Case 1: Simple 3-element array
    vector<int> test1 = {1, 2, 3};
    vector<vector<int>> res1 = sol.permute(test1);
    printResult(test1, res1);

    // Test Case 2: 2-element array
    vector<int> test2 = {10, 20};
    vector<vector<int>> res2 = sol.permute(test2);
    printResult(test2, res2);

    // Test Case 3: Single element
    vector<int> test3 = {5};
    vector<vector<int>> res3 = sol.permute(test3);
    printResult(test3, res3);

    return 0;
}