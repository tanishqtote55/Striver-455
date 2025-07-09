/*
    1020. Number of Enclaves
    You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
    A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
    Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

    Example 1:
    Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    Output: 3
    Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

    Example 2:
    Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
    Output: 0
    Explanation: All 1s are either on the boundary or can reach the boundary.
    
    Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 500
    grid[i][j] is either 0 or 1.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, int m, int n) {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != 1)
            return;

        grid[row][col] = 0;  // Mark as visited (flood it)

        dfs(row - 1, col, grid, m, n);
        dfs(row + 1, col, grid, m, n);
        dfs(row, col - 1, grid, m, n);
        dfs(row, col + 1, grid, m, n);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Flood all land cells connected to the boundary
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) dfs(i, 0, grid, m, n);
            if (grid[i][n - 1] == 1) dfs(i, n - 1, grid, m, n);
        }

        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1) dfs(0, j, grid, m, n);
            if (grid[m - 1][j] == 1) dfs(m - 1, j, grid, m, n);
        }

        // Step 2: Count remaining 1s
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    int result = sol.numEnclaves(grid);

    cout << "Number of enclave land cells: " << result << endl;

    return 0;
}

// Time: O(m × n)
// Space: O(m × n) in worst case (due to DFS recursion stack)