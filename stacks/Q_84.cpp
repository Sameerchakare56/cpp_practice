#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> s;

        // Step 1: Find Nearest Smaller to Right (NSR)
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            // If no smaller element exists to the right, boundary is n
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Clear stack for reuse
        while (!s.empty()) s.pop();

        // Step 2: Find Nearest Smaller to Left (NSL)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            // If no smaller element exists to the left, boundary is -1
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Step 3: Calculate Max Area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }
};

// Helper function to run and print test cases
void runTest(vector<int> heights, int expected) {
    Solution sol;
    int result = sol.largestRectangleArea(heights);
    cout << "Input: [";
    for(int i=0; i<heights.size(); ++i) cout << heights[i] << (i==heights.size()-1 ? "" : ",");
    cout << "] | Expected: " << expected << " | Result: " << result;
    cout << (result == expected ? " -> PASS" : " -> FAIL") << endl;
}

int main() {
    cout << "--- Largest Rectangle in Histogram Tests ---" << endl;

    // Test Case 1: Standard case
    runTest({2, 1, 5, 6, 2, 3}, 10);

    // Test Case 2: Ascending heights
    runTest({1, 2, 3, 4, 5}, 9); // Rectangle of height 3, width 3 (3,4,5)

    // Test Case 3: Descending heights
    runTest({5, 4, 3, 2, 1}, 9);

    // Test Case 4: All same heights
    runTest({2, 2, 2, 2}, 8);

    // Test Case 5: Single element
    runTest({5}, 5);

    return 0;
}