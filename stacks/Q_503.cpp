#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * Finds the next greater element in a circular array.
     * Time Complexity: O(n) - Each element is pushed and popped at most twice.
     * Space Complexity: O(n) - To store the stack and the result vector.
     */
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s; 

        // We iterate from 2n-1 down to 0 to simulate the circular behavior
        for (int i = 2 * n - 1; i >= 0; i--) {
            // Maintain a monotonic decreasing stack
            while (!s.empty() && nums[s.top()] <= nums[i % n]) {
                s.pop();
            }
            
            // If stack is not empty, the top is the next greater element
            if (i < n) {
                ans[i] = s.empty() ? -1 : nums[s.top()];
            }
            
            s.push(i % n);
        }        
        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: [ ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << "]" << endl;

    return 0;
}