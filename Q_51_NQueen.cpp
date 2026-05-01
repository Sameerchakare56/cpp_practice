#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // 1. Check the column for another queen above
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // 2. Check the upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // 3. Check the upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void nQueen(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
        // Base Case: All queens are placed successfully
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in every column of the current row
        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';       // Action
                nQueen(board, row + 1, n, ans); // Recurse
                board[row][j] = '.';       // Backtrack (undo action)
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // Initialize an empty board of size n x n
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueen(board, 0, n, ans);

        return ans;
    }
};

// Helper function to print test results
void printSolutions(int n, const vector<vector<string>>& solutions) {
    cout << "Found " << solutions.size() << " solutions for n = " << n << ":" << endl;
    for (const auto& sol : solutions) {
        for (const string& row : sol) {
            cout << row << endl;
        }
        cout << "---" << endl;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1: n = 1 (Trivial case)
    printSolutions(1, sol.solveNQueens(1));

    // Test Case 2: n = 4 (Standard classic case)
    printSolutions(4, sol.solveNQueens(4));

    return 0;
}