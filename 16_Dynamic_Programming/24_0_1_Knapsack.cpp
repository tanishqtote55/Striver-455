/*
    0/1 Knapsack Problem – Statement
    You are given n items with:

    a weight array wt[]
    a value array val[]
    a knapsack of capacity W

    You need to maximize the total value in the knapsack, with the condition that you can either include or exclude an item (0/1) — no fractions and no repetitions.

    Constraints:
    1 <= n <= 1000
    1 <= W <= 1000
    1 <= wt[i], val[i] <= 1000
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 1. Memoization
    int knapsackMemo(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
        if (i == 0) {
            if (wt[0] <= W) return val[0];
            else return 0;
        }

        if (dp[i][W] != -1) return dp[i][W];

        int notPick = knapsackMemo(i - 1, W, wt, val, dp);
        int pick = 0;
        if (wt[i] <= W)
            pick = val[i] + knapsackMemo(i - 1, W - wt[i], wt, val, dp);

        return dp[i][W] = max(pick, notPick);
    }

    int knapsackTab(int n, int W, vector<int>& wt, vector<int>& val) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // base case
        for (int w = wt[0]; w <= W; ++w) {
            dp[0][w] = val[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int w = 0; w <= W; ++w) {
                int notPick = dp[i - 1][w];
                int pick = 0;
                if (wt[i] <= w)
                    pick = val[i] + dp[i - 1][w - wt[i]];
                dp[i][w] = max(pick, notPick);
            }
        }

        return dp[n - 1][W];
    }

    int knapsackSpaceOpt(int n, int W, vector<int>& wt, vector<int>& val) {
        vector<int> prev(W + 1, 0), curr(W + 1, 0);

        for (int w = wt[0]; w <= W; ++w)
            prev[w] = val[0];

        for (int i = 1; i < n; ++i) {
            for (int w = 0; w <= W; ++w) {
                int notPick = prev[w];
                int pick = 0;
                if (wt[i] <= w)
                    pick = val[i] + prev[w - wt[i]];
                curr[w] = max(pick, notPick);
            }
            prev = curr;
        }

        return prev[W];
    }

    // Unified call
    int solveMemo(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return knapsackMemo(n - 1, W, wt, val, dp);
    }
};

int main() {
    Solution sol;

    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    
    int W = 8;
    int n = wt.size();

    cout << "Memoization: " << sol.solveMemo(wt, val, n, W) << endl;
    cout << "Tabulation: " << sol.knapsackTab(n, W, wt, val) << endl;
    cout << "Space Optimized: " << sol.knapsackSpaceOpt(n, W, wt, val) << endl;

    return 0;
}

// | Approach        | Time Complexity | Space Complexity      |
// | --------------- | --------------- | --------------------- |
// | Memoization     | O(n × W)        | O(n × W) + O(n) stack |
// | Tabulation      | O(n × W)        | O(n × W)              |
// | Space Optimized | O(n × W)        | O(W)                  |