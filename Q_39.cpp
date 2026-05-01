#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void getAllCombination(vector<int> &arr, int idx, int tar, vector<vector<int>> &ans, vector<int> &combin) {
        // Base Case: If target is met, we found a valid combination
        if (tar == 0) {
            ans.push_back(combin);
            return;
        }

        // Base Case: If index out of bounds or target exceeded
        if (idx == arr.size() || tar < 0) {
            return;
        }

        // --- OPTION 1: PICK the element ---
        // We stay at the same 'idx' because we are allowed to reuse the same number
        combin.push_back(arr[idx]);
        getAllCombination(arr, idx, tar - arr[idx], ans, combin);
        
        // Backtrack: Remove the element to explore the "Don't Pick" branch
        combin.pop_back();

        // --- OPTION 2: DON'T PICK the element ---
        // Move to the next index to try different numbers
        getAllCombination(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        
        // Calling the recursive helper
        getAllCombination(arr, 0, target, ans, combin);
        return ans;
    }
};

// Helper function to print the output
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << (j == result[i].size() - 1 ? "" : ",");
        }
        cout << "]" << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {2, 3, 6, 7};
    int target1 = 7;
    cout << "Input: candidates = [2,3,6,7], target = 7" << endl;
    vector<vector<int>> res1 = sol.combinationSum(arr1, target1);
    cout << "Output: ";
    printResult(res1); 
    // Expected: [[2,2,3],[7]]

    // Test Case 2
    vector<int> arr2 = {2, 3, 5};
    int target2 = 8;
    cout << "\nInput: candidates = [2,3,5], target = 8" << endl;
    vector<vector<int>> res2 = sol.combinationSum(arr2, target2);
    cout << "Output: ";
    printResult(res2);
    // Expected: [[2,2,2,2],[2,3,3],[3,5]]

    return 0;
}