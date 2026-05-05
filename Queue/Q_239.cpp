#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    /**
     * Finds the maximum element in every sliding window of size k.
     * Time Complexity: O(N) - Each element is pushed and popped from the deque at most once.
     * Space Complexity: O(k) - The deque stores at most k indices.
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return {};
        
        deque<int> dq; // Stores indices of elements
        vector<int> res;

        // 1. Process the first window (first k elements)
        for (int i = 0; i < k; i++) {
            // Maintain monotonic property: remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // 2. Process the rest of the elements
        for (int i = k; i < n; i++) {
            // The element at the front of the deque is the max for the PREVIOUS window
            res.push_back(nums[dq.front()]);

            // Remove indices that are out of the current window's range
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain monotonic property for the current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // 3. Add the maximum for the final window
        res.push_back(nums[dq.front()]);

        return res;
    }
};

// --- Helper function to print vectors ---
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

// --- Test Harness ---
int main() {
    Solution sol;

    struct TestCase {
        vector<int> nums;
        int k;
        vector<int> expected;
    };

    vector<TestCase> testCases = {
        {{1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7}},
        {{1}, 1, {1}},
        {{7, 2, 4}, 2, {7, 4}},
        {{1, -1}, 1, {1, -1}},
        {{9, 11}, 2, {11}}
    };

    cout << "Running Sliding Window Maximum Tests..." << endl;
    cout << "---------------------------------------" << endl;

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> result = sol.maxSlidingWindow(testCases[i].nums, testCases[i].k);
        
        cout << "Test " << i + 1 << ":" << endl;
        cout << "Input:  nums = "; printVector(testCases[i].nums);
        cout << "        k = " << testCases[i].k << endl;
        cout << "Result: "; printVector(result);
        
        if (result == testCases[i].expected) {
            cout << "STATUS: [PASS]" << endl;
        } else {
            cout << "STATUS: [FAIL]" << endl;
        }
        cout << "---------------------------------------" << endl;
    }

    return 0;
}