#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        // Initialize answer vector with zeros
        vector<int> answer(n, 0);

        for (int i = 0; i < n; i++) {
            int count = 0;
            // Only look at indices to the right of i
            for (int j = i + 1; j < n; j++) {
                // Check if one is odd and the other is even
                if (nums[i] % 2 == 1 && nums[j] % 2 == 0) {
                    count += 1;
                } else if (nums[i] % 2 == 0 && nums[j] % 2 == 1) {
                    count += 1;
                }
            }
            answer[i] = count;
        }
        return answer;
    }
};

/**
 * Main function for testing the logic
 */
int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = sol.countOppositeParity(nums1);
    
    cout << "Example 1 Output: ";
    for (int x : result1) cout << x << " "; 
    cout << endl; // Expected: 2 1 1 0

    // Example 2
    vector<int> nums2 = {1};
    vector<int> result2 = sol.countOppositeParity(nums2);
    
    cout << "Example 2 Output: ";
    for (int x : result2) cout << x << " ";
    cout << endl; // Expected: 0

    return 0;
}