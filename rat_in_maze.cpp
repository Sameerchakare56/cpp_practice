#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(vector<vector<int>> &maze, int row, int col, string path, vector<string> &ans) {
    int n = maze.size();
    
    // Check boundaries and if cell is walkable (must be exactly 1)
    if (row < 0 || col < 0 || row >= n || col >= n || maze[row][col] != 1) {
        return;
    }

    // Goal reached
    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark current cell as visited by changing 1 to -1 (or 0)
    maze[row][col] = -1;

    // Explore: Down, Up, Left, Right
    helper(maze, row + 1, col, path + "D", ans);
    helper(maze, row - 1, col, path + "U", ans);
    helper(maze, row, col - 1, path + "L", ans);
    helper(maze, row, col + 1, path + "R", ans);

    // Backtrack: Restore the cell to 1 for other potential paths
    maze[row][col] = 1;
}

vector<string> findPath(vector<vector<int>> &maze) {
    vector<string> ans;
    int n = maze.size();
    if (n == 0 || maze[0][0] == 0) return ans;

    helper(maze, 0, 0, "", ans);
    return ans;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0}, 
        {0, 1, 1, 1}
    };

    vector<string> ans = findPath(maze);
    
    if(ans.empty()) {
        cout << "No path found!" << endl;
    } else {
        for (const string &path : ans) {
            cout << path << endl;
        }
    }

    return 0;
}