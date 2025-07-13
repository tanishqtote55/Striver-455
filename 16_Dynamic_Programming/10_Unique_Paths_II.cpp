/*
    63. Unique Paths II

    You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

    An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

    Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

    The testcases are generated so that the answer will be less than or equal to 2 * 109.

    Example 1:
    Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    Output: 2
    Explanation: There is one obstacle in the middle of the 3x3 grid above.
    There are two ways to reach the bottom-right corner:
    1. Right -> Right -> Down -> Down
    2. Down -> Down -> Right -> Right

    Example 2:
    Input: obstacleGrid = [[0,1],[0,0]]
    Output: 1
    
    Constraints:

    m == obstacleGrid.length
    n == obstacleGrid[i].length
    1 <= m, n <= 100
    obstacleGrid[i][j] is 0 or 1.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Memoization
    int memo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i >= 0 && j >= 0 && grid[i][j] == 1) return 0;  // obstacle
        if (i == 0 && j == 0) return grid[0][0] == 0 ? 1 : 0;
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int up = memo(i - 1, j, grid, dp);
        int left = memo(i, j - 1, grid, dp);
        return dp[i][j] = up + left;
    }

    // 2. Tabulation
    int tabulation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) dp[i][j] = 0;
                else if (i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    // 3. Space Optimized
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; ++i) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) curr[j] = 0;
                else if (i == 0 && j == 0) curr[j] = 1;
                else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j - 1] : 0;
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};
int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    // Memoization
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Memoization: " << sol.memo(m - 1, n - 1, obstacleGrid, dp) << endl;

    // Tabulation
    cout << "Tabulation: " << sol.tabulation(obstacleGrid) << endl;

    // Space Optimized
    cout << "Space Optimized: " << sol.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}