#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Checks if placing 'dig' at board[row][col] is valid
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig) return false; // Row check
            if (board[j][col] == dig) return false; // Column check
        }

        // 3x3 Subgrid check
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == dig) return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {
        // Base case: If we reach row 9, the board is filled
        if (row == 9) return true;

        // Determine next cell coordinates
        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // If the current cell is already filled, move to the next
        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        // Try placing digits '1' through '9'
        for (char dig = '1'; dig <= '9'; dig++) {
            if (isSafe(board, row, col, dig)) {
                board[row][col] = dig; // Choose
                if (helper(board, nextRow, nextCol)) { // Explore
                    return true;
                }
                board[row][col] = '.'; // Backtrack (Un-choose)
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }

    // Helper function to print the board
    void printBoard(const vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (i % 3 == 0 && i != 0) cout << "---------------------\n";
            for (int j = 0; j < 9; j++) {
                if (j % 3 == 0 && j != 0) cout << "| ";
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution sol;
    
    // Standard Sudoku test case ('.' represents empty cells)
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << "Original Board:" << endl;
    sol.printBoard(board);
    
    sol.solveSudoku(board);

    cout << "\nSolved Board:" << endl;
    sol.printBoard(board);

    return 0;
}