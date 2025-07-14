/*
    Unbounded knapsack

    Given two integer arrays, val and wt, each of size N, representing the values and weights of N items respectively, and an integer W, representing the maximum capacity of a knapsack, determine the maximum value achievable by selecting a subset of the items such that the total weight of the selected items does not exceed the knapsack capacity W. The goal is to maximize the sum of the values of the selected items while keeping the total weight within the knapsack's capacity.

    An infinite supply of each item can be assumed.

    Examples:
    Input: val = [5, 11, 13], wt = [2, 4, 6], W = 10
    Output: 27
    Explanation: Select 2 items with weights 4 and 1 item with weight 2 for a total value of 11+11+5 = 27.

    Input: val = [10, 40, 50, 70], wt = [1, 3, 4, 5], W = 8
    Output: 110
    Explanation: Select items with weights 3 and 5 for a total value of 40 + 70 = 110.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Memoization (Top-down)
    int memoHelper(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
        if (i == 0) {
            return (W / wt[0]) * val[0]; // take as many as possible
        }
        if (dp[i][W] != -1) return dp[i][W];

        int notTake = memoHelper(i - 1, W, wt, val, dp);
        int take = 0;
        if (wt[i] <= W)
            take = val[i] + memoHelper(i, W - wt[i], wt, val, dp); // stay at i

        return dp[i][W] = max(take, notTake);
    }

    int unboundedKnapsackMemo(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return memoHelper(n - 1, W, wt, val, dp);
    }

    // 2. Tabulation (Bottom-up)
    int unboundedKnapsackTab(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base case
        for (int w = 0; w <= W; ++w) {
            dp[0][w] = (w / wt[0]) * val[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int w = 0; w <= W; ++w) {
                int notTake = dp[i - 1][w];
                int take = 0;
                if (wt[i] <= w)
                    take = val[i] + dp[i][w - wt[i]];
                dp[i][w] = max(take, notTake);
            }
        }

        return dp[n - 1][W];
    }

    // 3. Space Optimized (1D array)
    int unboundedKnapsackSpaceOpt(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<int> dp(W + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int w = 0; w <= W; ++w) {
                int notTake = dp[w];
                int take = 0;
                if (wt[i] <= w) {
                    take = val[i] + dp[w - wt[i]];
                }
                dp[w] = max(take, notTake);
            }
        }

        return dp[W];
    }
};

int main() {
    Solution sol;

    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;

    cout << "Memoization: " << sol.unboundedKnapsackMemo(wt, val, wt.size(), W) << endl;
    cout << "Tabulation: " << sol.unboundedKnapsackTab(wt, val, wt.size(), W) << endl;
    cout << "Space Optimized: " << sol.unboundedKnapsackSpaceOpt(wt, val, wt.size(), W) << endl;

    return 0;
}

// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------- | ---------------- |
// | Memoization     | O(n × W)        | O(n × W) + stack |
// | Tabulation      | O(n × W)        | O(n × W)         |
// | Space Optimized | O(n × W)        | O(W)             |