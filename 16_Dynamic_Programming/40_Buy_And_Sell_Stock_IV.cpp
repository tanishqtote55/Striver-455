/*
    188. Best Time to Buy and Sell Stock IV

    You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

    Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

    Example 1:
    Input: k = 2, prices = [2,4,1]
    Output: 2
    Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

    Example 2:
    Input: k = 2, prices = [3,2,6,5,0,3]
    Output: 7
    Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
    
    Constraints:
    1 <= k <= 100
    1 <= prices.length <= 1000
    0 <= prices[i] <= 1000
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // --------- 1. Memoization ----------
    int memo(int i, int buy, int cap, vector<int>& prices, int k, vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || cap == 0) return 0;
        if (dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + memo(i + 1, 0, cap, prices, k, dp),
                         memo(i + 1, 1, cap, prices, k, dp));
        } else {
            profit = max(prices[i] + memo(i + 1, 1, cap - 1, prices, k, dp),
                         memo(i + 1, 0, cap, prices, k, dp));
        }

        return dp[i][buy][cap] = profit;
    }

    // --------- 2. Tabulation ----------
    int tabulation(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int cap = 1; cap <= k; ++cap) {
                    if (buy) {
                        dp[i][buy][cap] = max(-prices[i] + dp[i + 1][0][cap],
                                               dp[i + 1][1][cap]);
                    } else {
                        dp[i][buy][cap] = max(prices[i] + dp[i + 1][1][cap - 1],
                                               dp[i + 1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][k];
    }

    // --------- 3. Space Optimized ----------
    int spaceOptimized(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0)), curr(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int cap = 1; cap <= k; ++cap) {
                    if (buy) {
                        curr[buy][cap] = max(-prices[i] + ahead[0][cap],
                                              ahead[1][cap]);
                    } else {
                        curr[buy][cap] = max(prices[i] + ahead[1][cap - 1],
                                              ahead[0][cap]);
                    }
                }
            }
            ahead = curr;
        }

        return ahead[1][k];
    }

    // --------- Main Entry ---------
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {  // Same as unlimited transactions (greedy)
            int profit = 0;
            for (int i = 1; i < n; ++i)
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            return profit;
        }

        // 1. Memoization
        /*
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return memo(0, 1, k, prices, k, dp);
        */

        // 2. Tabulation
        return tabulation(k, prices);

        // 3. Space Optimization
        // return spaceOptimized(k, prices);
    }
    // Tabulation (dp[n+1][2k+1])
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int transNo = 0; transNo < 2 * k; ++transNo) {
                if (transNo % 2 == 0) {
                    // Buy allowed
                    dp[i][transNo] = max(-prices[i] + dp[i + 1][transNo + 1], dp[i + 1][transNo]);
                } else {
                    // Sell allowed
                    dp[i][transNo] = max(prices[i] + dp[i + 1][transNo + 1], dp[i + 1][transNo]);
                }
            }
        }

        return dp[0][0]; // Start at day 0 and transaction 0
    }
};

int main() {
    Solution sol;
    vector<int> prices1 = {2, 4, 1};
    cout << sol.maxProfit(2, prices1) << endl; // Output: 2

    vector<int> prices2 = {3,2,6,5,0,3};
    cout << sol.maxProfit(2, prices2) << endl; // Output: 7

    return 0;
}
// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------- | ---------------- |
// | Memoization     | O(n × 2 × k)    | O(n × 2 × k)     |
// | Tabulation      | O(n × 2 × k)    | O(n × 2 × k)     |
// | Space Optimized | O(n × 2 × k)    | O(2 × k)         |

// | Metric           | Value       |
// | ---------------- | ----------- |
// | Time Complexity  | `O(n * 2k)` |
// | Space Complexity | `O(n * 2k)` |