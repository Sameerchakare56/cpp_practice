#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Recursively checks if the knight can complete the tour.
     * Uses short-circuiting (||) to ensure O(N^2) time complexity.
     */
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal) {
        // Boundary check and value check
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal) {
            return false;
        }

        // Base case: If we reached the last number, the tour is valid
        if (expVal == n * n - 1) {
            return true;
        }

        // Check all 8 possible L-shaped moves
        // Short-circuiting ensures we stop exploring once the correct next move is found
        return isValid(grid, r - 2, c + 1, n, expVal + 1) ||
               isValid(grid, r - 1, c + 2, n, expVal + 1) ||
               isValid(grid, r + 1, c + 2, n, expVal + 1) ||
               isValid(grid, r + 2, c + 1, n, expVal + 1) ||
               isValid(grid, r + 2, c - 1, n, expVal + 1) ||
               isValid(grid, r + 1, c - 2, n, expVal + 1) ||
               isValid(grid, r - 1, c - 2, n, expVal + 1) ||
               isValid(grid, r - 2, c - 1, n, expVal + 1);
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        // Knight must start at (0,0) with value 0
        if (grid.empty() || grid[0][0] != 0) {
            return false;
        }
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};

int main() {
    Solution sol;

    // Test Case 1: Valid Knight's Tour (5x5)
    vector<vector<int>> validGrid = {
        {0, 11, 16, 5, 20},
        {17, 4, 19, 10, 15},
        {12, 1, 8, 21, 6},
        {3, 18, 23, 14, 9},
        {24, 13, 2, 7, 22}
    };

    // Test Case 2: Invalid Knight's Tour (Move from 0 to 1 is illegal)
    vector<vector<int>> invalidGrid = {
        {0, 3, 6},
        {5, 8, 1},
        {2, 4, 7}
    };

    cout << "--- Knight's Tour Validator ---" << endl;

    if (sol.checkValidGrid(validGrid)) {
        cout << "Test Case 1: Valid Grid -> PASSED" << endl;
    } else {
        cout << "Test Case 1: Valid Grid -> FAILED" << endl;
    }

    if (!sol.checkValidGrid(invalidGrid)) {
        cout << "Test Case 2: Invalid Grid -> PASSED (Detected invalid)" << endl;
    } else {
        cout << "Test Case 2: Invalid Grid -> FAILED" << endl;
    }

    return 0;
}