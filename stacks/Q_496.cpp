#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Map to store: Key = Number, Value = Its Next Greater Element
        unordered_map<int, int> m;
        // Monotonic stack to keep track of elements to the right
        stack<int> s;

        // Step 1: Process nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            
            // While loop: Remove elements smaller than current because they 
            // can't be the "next greater" for anything to the left anymore.
            while (s.size() > 0 && s.top() <= nums2[i]) {
                s.pop();
            }

            // If stack is empty, no greater element exists to the right
            if (s.empty()) {
                m[nums2[i]] = -1;
            } else {
                // The top of the stack is the first greater element to the right
                m[nums2[i]] = s.top();
            }

            // Push current element to the stack for the next numbers to look at
            s.push(nums2[i]);
        }

        // Step 2: Build the result for nums1 using the map
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};

// --- Driver Code to Test the Solution ---
int main() {
    Solution sol;
    
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}