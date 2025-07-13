/*
    120. Triangle

    Given a triangle array, return the minimum path sum from top to bottom.

    For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

    Example 1:
    Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    Output: 11
    Explanation: The triangle looks like:
    2
    3 4
    6 5 7
    4 1 8 3
    The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

    Example 2:
    Input: triangle = [[-10]]
    Output: -10
    
    Constraints:

    1 <= triangle.length <= 200
    triangle[0].length == 1
    triangle[i].length == triangle[i - 1].length + 1
    -104 <= triangle[i][j] <= 104
    
    Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 1. Memoization
    int memo(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        int n = triangle.size();
        if (i == n - 1) return triangle[i][j];  // Base case: last row
        if (dp[i][j] != -1) return dp[i][j];

        int down = memo(i + 1, j, triangle, dp);
        int diag = memo(i + 1, j + 1, triangle, dp);
        return dp[i][j] = triangle[i][j] + min(down, diag);
    }

    // 2. Tabulation
    int tabulation(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: last row
        for (int j = 0; j < n; ++j) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Bottom-up filling
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                int down = dp[i + 1][j];
                int diag = dp[i + 1][j + 1];
                dp[i][j] = triangle[i][j] + min(down, diag);
            }
        }

        return dp[0][0];  // Top cell
    }

    // 3. Space Optimized
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n, 0);

        // Base case: last row
        for (int j = 0; j < n; ++j) {
            front[j] = triangle[n - 1][j];
        }

        // Bottom-up
        for (int i = n - 2; i >= 0; --i) {
            vector<int> curr(n, 0);
            for (int j = 0; j <= i; ++j) {
                int down = front[j];
                int diag = front[j + 1];
                curr[j] = triangle[i][j] + min(down, diag);
            }
            front = curr;
        }

        return front[0];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    // Memoization
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Memoization: " << sol.memo(0, 0, triangle, dp) << endl;

    // Tabulation
    cout << "Tabulation: " << sol.tabulation(triangle) << endl;

    // Space Optimized
    cout << "Space Optimized: " << sol.minimumTotal(triangle) << endl;

    return 0;
}


// | Approach        | Time  | Space         |
// | --------------- | ----- | ------------- |
// | Memoization     | O(n²) | O(n²) + stack |
// | Tabulation      | O(n²) | O(n²)         |
// | Space Optimized | O(n²) | O(n)          |