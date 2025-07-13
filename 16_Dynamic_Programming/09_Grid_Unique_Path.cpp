/*
    62. Unique Paths

    There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

    Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

    The test cases are generated so that the answer will be less than or equal to 2 * 109.

    Example 1:
    Input: m = 3, n = 7
    Output: 28

    Example 2:
    Input: m = 3, n = 2
    Output: 3
    Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    1. Right -> Down -> Down
    2. Down -> Down -> Right
    3. Down -> Right -> Down
    
    Constraints:

    1 <= m, n <= 100
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Memoization
    int memo(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int up = memo(i - 1, j, dp);
        int left = memo(i, j - 1, dp);
        return dp[i][j] = up + left;
    }

    // 2. Tabulation
    int tabulation(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) dp[i][j] = 1;
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
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; ++i) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) curr[j] = 1;
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
    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;

    // Memoization
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Unique Paths (Memoization): " << sol.memo(m - 1, n - 1, dp) << endl;

    // Tabulation
    cout << "Unique Paths (Tabulation): " << sol.tabulation(m, n) << endl;

    // Space Optimized
    cout << "Unique Paths (Space Optimized): " << sol.uniquePaths(m, n) << endl;

    return 0;
}