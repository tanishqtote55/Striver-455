/*
    931. Minimum Falling Path Sum

    Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

    A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

    Example 1:
    Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    Output: 13
    Explanation: There are two falling paths with a minimum sum as shown.

    Example 2:
    Input: matrix = [[-19,57],[-40,-5]]
    Output: -59
    Explanation: The falling path with a minimum sum is shown.
    
    Constraints:

    n == matrix.length == matrix[i].length
    1 <= n <= 100
    -100 <= matrix[i][j] <= 100
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // 1. Memoization
    int memo(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        if (j < 0 || j >= n) return 1e9; // out of bounds
        if (i == n - 1) return matrix[i][j]; // base case
        if (dp[i][j] != -1) return dp[i][j];

        int down = memo(i + 1, j, matrix, dp);
        int leftDiag = memo(i + 1, j - 1, matrix, dp);
        int rightDiag = memo(i + 1, j + 1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({down, leftDiag, rightDiag});
    }

    // 2. Tabulation
    int tabulation(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // base case: last row
        for (int j = 0; j < n; ++j) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                int down = dp[i + 1][j];
                int leftDiag = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int rightDiag = (j < n - 1) ? dp[i + 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({down, leftDiag, rightDiag});
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }

    // 3. Space Optimized
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(matrix[n - 1]); // last row as base case

        for (int i = n - 2; i >= 0; --i) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j) {
                int down = prev[j];
                int leftDiag = (j > 0) ? prev[j - 1] : INT_MAX;
                int rightDiag = (j < n - 1) ? prev[j + 1] : INT_MAX;

                curr[j] = matrix[i][j] + min({down, leftDiag, rightDiag});
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    // Memoization
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int minPath = INT_MAX;
    for (int j = 0; j < n; ++j) {
        minPath = min(minPath, sol.memo(0, j, matrix, dp));
    }
    cout << "Memoization: " << minPath << endl;

    // Tabulation
    cout << "Tabulation: " << sol.tabulation(matrix) << endl;

    // Space Optimized
    cout << "Space Optimized: " << sol.minFallingPathSum(matrix) << endl;

    return 0;
}

// | Approach        | Time  | Space         |
// | --------------- | ----- | ------------- |
// | Memoization     | O(n²) | O(n²) + stack |
// | Tabulation      | O(n²) | O(n²)         |
// | Space Optimized | O(n²) | O(n)          |

// To convert the solution for 931. Minimum Falling Path Sum into Maximum Falling Path Sum, 
// you only need to change min to max in all relevant parts of the code.