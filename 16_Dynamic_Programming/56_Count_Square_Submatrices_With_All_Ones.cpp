/*
    1277. Count Square Submatrices with All Ones

    Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

    Example 1:
    Input: matrix =
    [
    [0,1,1,1],
    [1,1,1,1],
    [0,1,1,1]
    ]
    Output: 15
    Explanation: 
    There are 10 squares of side 1.
    There are 4 squares of side 2.
    There is  1 square of side 3.
    Total number of squares = 10 + 4 + 1 = 15.

    Example 2:
    Input: matrix = 
    [
    [1,0,1],
    [1,1,0],
    [1,1,0]
    ]
    Output: 7
    Explanation: 
    There are 6 squares of side 1.  
    There is 1 square of side 2. 
    Total number of squares = 6 + 1 = 7.
    
    Constraints:

    1 <= arr.length <= 300
    1 <= arr[0].length <= 300
    0 <= arr[i][j] <= 1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // DP In-place
    int countSquaresDP(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int count = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 1) {
                    if (i > 0 && j > 0) {
                        matrix[i][j] = 1 + min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]});
                    }
                    count += matrix[i][j];
                }
            }
        }

        return count;
    }
    // Tabulation
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = 0;

        // dp[i][j] will store the size of the largest square ending at (i,j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;  // edge cells
                    } else {
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                    total += dp[i][j];  // add count of squares ending at (i, j)
                }
            }
        }

        return total;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    int result = sol.countSquares(matrix);
    cout << "Total number of square submatrices with all ones: " << result << endl;
    return 0;
}

// | Approach      | Time Complexity | Space Complexity            |
// | ------------- | --------------- | --------------------------- |
// | DP (In-place) | O(m × n)        | O(1) (in-place in `matrix`) |
// | Tabulation    | O(m × n)        | O(m × n)                    |
