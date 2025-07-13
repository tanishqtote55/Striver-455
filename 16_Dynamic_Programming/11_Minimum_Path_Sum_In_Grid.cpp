/*
    64. Minimum Path Sum

    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.

    Example 1:
    Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    Output: 7
    Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

    Example 2:
    Input: grid = [[1,2,3],[4,5,6]]
    Output: 12
    
    Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 200
    0 <= grid[i][j] <= 200
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 1. Memoization (Top-down) O(m × n)	O(m × n) + stack
    int memo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return 1e9; // out of bounds = infinity
        if (dp[i][j] != -1) return dp[i][j];

        int up = memo(i - 1, j, grid, dp);
        int left = memo(i, j - 1, grid, dp);
        return dp[i][j] = grid[i][j] + min(up, left);
    }

    // 2. Tabulation (Bottom-up) O(m × n)	O(m × n)
    int tabulation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) dp[i][j] = grid[0][0];
                else {
                    int up = (i > 0) ? dp[i - 1][j] : 1e9;
                    int left = (j > 0) ? dp[i][j - 1] : 1e9;
                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    // 3. Space Optimized O(m × n)	O(n)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; ++i) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) curr[j] = grid[0][0];
                else {
                    int up = (i > 0) ? prev[j] : 1e9;
                    int left = (j > 0) ? curr[j - 1] : 1e9;
                    curr[j] = grid[i][j] + min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    // Memoization
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Memoization: " << sol.memo(m - 1, n - 1, grid, dp) << endl;

    // Tabulation
    cout << "Tabulation: " << sol.tabulation(grid) << endl;

    // Space Optimized
    cout << "Space Optimized: " << sol.minPathSum(grid) << endl;

    return 0;
}