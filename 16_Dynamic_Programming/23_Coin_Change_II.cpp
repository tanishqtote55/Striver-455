/*
    518. Coin Change II

    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

    Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

    You may assume that you have an infinite number of each kind of coin.

    The answer is guaranteed to fit into a signed 32-bit integer.

    Example 1:
    Input: amount = 5, coins = [1,2,5]
    Output: 4
    Explanation: there are four ways to make up the amount:
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1

    Example 2:
    Input: amount = 3, coins = [2]
    Output: 0
    Explanation: the amount of 3 cannot be made up just with coins of 2.

    Example 3:
    Input: amount = 10, coins = [10]
    Output: 1
    
    Constraints:
    1 <= coins.length <= 300
    1 <= coins[i] <= 5000
    All the values of coins are unique.
    0 <= amount <= 5000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Memoization (Top-down)
    int memoHelper(int i, int amount, vector<int>& coins, vector<vector<long long>>& dp) {
        if (amount == 0) return 1;
        if (i == coins.size()) return 0;
        if (dp[i][amount] != -1) return dp[i][amount];

        long long notTake = memoHelper(i + 1, amount, coins, dp);
        long long take = 0;
        if (coins[i] <= amount)
            take = memoHelper(i, amount - coins[i], coins, dp);

        return dp[i][amount] = take + notTake;
    }

    int changeMemo(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, -1));
        return memoHelper(0, amount, coins, dp);
    }

    // 2. Tabulation (Bottom-up)
    int changeTab(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));

        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1; // one way to make amount = 0

        for (int i = n - 1; i >= 0; --i) {
            for (int t = 0; t <= amount; ++t) {
                long long notTake = dp[i + 1][t];
                long long take = 0;
                if (coins[i] <= t)
                    take = dp[i][t - coins[i]];
                dp[i][t] = take + notTake;
            }
        }

        return static_cast<int>(dp[0][amount]);
    }

    // 3. Space Optimized
    int changeSpaceOpt(int amount, vector<int>& coins) {
        vector<long long> dp(amount + 1, 0);
        dp[0] = 1; // one way to make amount = 0

        for (int coin : coins) {
            for (int t = coin; t <= amount; ++t) {
                dp[t] += dp[t - coin];
            }
        }

        return static_cast<int>(dp[amount]);
    }
};
int main() {
    Solution sol;

    int amount1 = 5;
    vector<int> coins1 = {1, 2, 5};

    cout << "Memoization: " << sol.changeMemo(amount1, coins1) << endl;
    cout << "Tabulation: " << sol.changeTab(amount1, coins1) << endl;
    cout << "Space Optimized: " << sol.changeSpaceOpt(amount1, coins1) << endl;

    int amount2 = 3;
    vector<int> coins2 = {2};

    cout << "Memoization: " << sol.changeMemo(amount2, coins2) << endl;
    cout << "Tabulation: " << sol.changeTab(amount2, coins2) << endl;
    cout << "Space Optimized: " << sol.changeSpaceOpt(amount2, coins2) << endl;

    return 0;
}
// | Approach        | Time Complexity | Space Complexity      |
// | --------------- | --------------- | --------------------- |
// | Memoization     | O(n × amount)   | O(n × amount + stack) |
// | Tabulation      | O(n × amount)   | O(n × amount)         |
// | Space Optimized | O(n × amount)   | O(amount)             |