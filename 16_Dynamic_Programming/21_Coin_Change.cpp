/*
    322. Coin Change

    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.

    Example 1:
    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1

    Example 2:
    Input: coins = [2], amount = 3
    Output: -1

    Example 3:
    Input: coins = [1], amount = 0
    Output: 0
    
    Constraints:

    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104
*/

// Greedy Fails {9, 6, 5, 1}  t = 11
// {9, 1, 1} = 11
// {6, 5} = 11


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 1. Memoization (Top-down DP)
    int memoHelper(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 0;
        if (i == coins.size()) return 1e9;
        if (dp[i][amount] != -1) return dp[i][amount];

        int notTake = memoHelper(i + 1, amount, coins, dp);
        int take = 1e9;
        if (coins[i] <= amount)
            take = 1 + memoHelper(i, amount - coins[i], coins, dp); // unbounded

        return dp[i][amount] = min(take, notTake);
    }

    int coinChangeMemo(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = memoHelper(0, amount, coins, dp);
        return (res >= 1e9 ? -1 : res);
    }

    // 2. Tabulation (Bottom-up DP)
    int coinChangeTab(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        // Base case
        for (int t = 0; t <= amount; ++t) {
            if (t % coins[0] == 0) dp[0][t] = t / coins[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int t = 0; t <= amount; ++t) {
                int notTake = dp[i - 1][t];
                int take = 1e9;
                if (coins[i] <= t)
                    take = 1 + dp[i][t - coins[i]];

                dp[i][t] = min(take, notTake);
            }
        }

        return dp[n - 1][amount] >= 1e9 ? -1 : dp[n - 1][amount];
    }

    // 3. Space Optimized DP
    int coinChangeSpaceOpt(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 1e9), curr(amount + 1, 1e9);

        // Base case
        for (int t = 0; t <= amount; ++t) {
            if (t % coins[0] == 0) prev[t] = t / coins[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int t = 0; t <= amount; ++t) {
                int notTake = prev[t];
                int take = 1e9;
                if (coins[i] <= t)
                    take = 1 + curr[t - coins[i]];
                curr[t] = min(take, notTake);
            }
            prev = curr;
        }

        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;

    cout << "Memoization: " << sol.coinChangeMemo(coins1, amount1) << endl;
    cout << "Tabulation: " << sol.coinChangeTab(coins1, amount1) << endl;
    cout << "Space Optimized: " << sol.coinChangeSpaceOpt(coins1, amount1) << endl;

    vector<int> coins2 = {2};
    int amount2 = 3;

    cout << "Memoization: " << sol.coinChangeMemo(coins2, amount2) << endl;
    cout << "Tabulation: " << sol.coinChangeTab(coins2, amount2) << endl;
    cout << "Space Optimized: " << sol.coinChangeSpaceOpt(coins2, amount2) << endl;

    return 0;
}

// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------- | ---------------- |
// | Memoization     | O(n × amount)   | O(n × amount)    |
// | Tabulation      | O(n × amount)   | O(n × amount)    |
// | Space Optimized | O(n × amount)   | O(amount)        |