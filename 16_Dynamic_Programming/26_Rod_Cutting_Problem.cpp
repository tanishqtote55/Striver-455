/*
    Rod cutting problem

    Given a rod of length N inches and an array price[] where price[i] denotes the value of a piece of rod of length i inches (1-based indexing). Determine the maximum value obtainable by cutting up the rod and selling the pieces. Make any number of cuts, or none at all, and sell the resulting pieces.

    Examples:
    Input: price = [1, 6, 8, 9, 10, 19, 7, 20], N = 8
    Output: 25
    Explanation: Cut the rod into lengths of 2 and 6 for a total price of 6 + 19= 25.

    Input: price = [1, 5, 8, 9], N = 4
    Output: 10
    Explanation: Cut the rod into lengths of 2 and 2 for a total price of 5 + 5 = 10.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Memoization (Top-down)
    int memoHelper(int i, int length, vector<int>& price, vector<vector<int>>& dp) {
        if (i == 0) {
            return length * price[0];  // use as many pieces of length 1 as possible
        }
        if (dp[i][length] != -1) return dp[i][length];

        int notTake = memoHelper(i - 1, length, price, dp);
        int take = 0;
        int rodLength = i + 1;
        if (rodLength <= length) {
            take = price[i] + memoHelper(i, length - rodLength, price, dp);
        }

        return dp[i][length] = max(take, notTake);
    }

    int rodCuttingMemo(vector<int> price, int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return memoHelper(n - 1, n, price, dp);
    }

    // 2. Tabulation (Bottom-up)
    int rodCuttingTab(vector<int> price, int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // base case: i == 0
        for (int len = 0; len <= n; ++len) {
            dp[0][len] = len * price[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int len = 0; len <= n; ++len) {
                int notTake = dp[i - 1][len];
                int take = 0;
                int rodLength = i + 1;
                if (rodLength <= len)
                    take = price[i] + dp[i][len - rodLength];
                dp[i][len] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }

    // 3. Space Optimized (1D DP)
    int rodCuttingSpaceOpt(vector<int> price, int n) {
        vector<int> dp(n + 1, 0);

        // base case: i == 0
        for (int len = 0; len <= n; ++len)
            dp[len] = len * price[0];

        for (int i = 1; i < n; ++i) {
            for (int len = 0; len <= n; ++len) {
                int notTake = dp[len];
                int take = 0;
                int rodLength = i + 1;
                if (rodLength <= len)
                    take = price[i] + dp[len - rodLength];
                dp[len] = max(take, notTake);
            }
        }

        return dp[n];
    }
};
int main() {
    Solution sol;

    vector<int> price = {1, 6, 8, 9, 10, 19, 7, 20};
    int n = 8;

    cout << "Memoization: " << sol.rodCuttingMemo(price, n) << endl;
    cout << "Tabulation: " << sol.rodCuttingTab(price, n) << endl;
    cout << "Space Optimized: " << sol.rodCuttingSpaceOpt(price, n) << endl;

    return 0;
}

// | Method          | Time  | Space         |
// | --------------- | ----- | ------------- |
// | Memoization     | O(n²) | O(n² + stack) |
// | Tabulation      | O(n²) | O(n²)         |
// | Space Optimized | O(n²) | O(n)          |
