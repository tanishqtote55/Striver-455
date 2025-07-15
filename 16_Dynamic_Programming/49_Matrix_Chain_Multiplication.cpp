/*
    Matrix chain multiplication

    Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.

    Given an array nums of size n. Dimension of matrix Ai ( 0 < i < n ) is nums[i - 1] x nums[i].Find a minimum number of multiplications needed to multiply the chain.

    Examples:
    Input : nums = [10, 15, 20, 25]
    Output : 8000
    Explanation : There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
    If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
    If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
    Thus minimum number of multiplications required is 8000.

    Input : nums = [4, 2, 3]
    Output : 24
    Explanation : There is only one way to multiply the chain - A1*A2.
    Thus minimum number of multiplications required is 24.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    // ---------- 1. MEMOIZATION ----------
    int memoSolve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k = i; k < j; k++) {
            int steps = memoSolve(i, k, nums, dp) +
                        memoSolve(k + 1, j, nums, dp) +
                        nums[i - 1] * nums[k] * nums[j];
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }

    int matrixMultiplicationMemo(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return memoSolve(1, n - 1, nums, dp);
    }

    // ---------- 2. TABULATION ----------
    int matrixMultiplicationTab(vector<int>& nums) {
        int n = nums.size();
        // Create a dp table of size n x n and initialize with 0
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Loop for chain length from 2 to n (length of subproblems)
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j < n; j++) {
                int minCost = INT_MAX;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j];
                    minCost = min(minCost, cost);
                }

                dp[i][j] = minCost;
            }
        }

        return dp[1][n - 1];
    }

    // ---------- 3. SPACE OPTIMIZED (Theoretical Note) ----------
    /*
        Matrix Chain Multiplication can't be efficiently reduced below O(N^2)
        space because each dp[i][j] depends on subproblems across ranges.
        Still, for educational purposes, this can be mentioned.
    */

    // ---------- DRIVER ----------
    int matrixMultiplication(vector<int>& nums) {
        cout << "Memoization: ";
        int res1 = matrixMultiplicationMemo(nums);
        cout << res1 << endl;

        cout << "Tabulation: ";
        int res2 = matrixMultiplicationTab(nums);
        cout << res2 << endl;

        return res2; // or res1, since both are same
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {10, 15, 20, 25};
    sol.matrixMultiplication(nums1); // Output: 8000

    vector<int> nums2 = {4, 2, 3};
    sol.matrixMultiplication(nums2); // Output: 24

    return 0;
}
// | Approach        | Time Complexity | Space Complexity             |
// | --------------- | --------------- | ---------------------------- |
// | Memoization     | O(N³)           | O(N²) (dp table + recursion) |
// | Tabulation      | O(N³)           | O(N²)                        |
// | Space Optimized | Not practical   | Not practical                |