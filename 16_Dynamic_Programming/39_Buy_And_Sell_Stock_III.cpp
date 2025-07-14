/*
    123. Best Time to Buy and Sell Stock III
    
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    Find the maximum profit you can achieve. You may complete at most two transactions.
    
    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

    Example 1:
    Input: prices = [3,3,5,0,0,3,1,4]
    Output: 6
    Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
    Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

    Example 2:
    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

    Example 3:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.
    
    Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 105
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    // --------- 1. Memoization ----------
    int memo(int i, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || cap == 0) return 0;
        if (dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + memo(i + 1, 0, cap, prices, dp),
                         memo(i + 1, 1, cap, prices, dp));
        } else {
            profit = max(prices[i] + memo(i + 1, 1, cap - 1, prices, dp),
                         memo(i + 1, 0, cap, prices, dp));
        }

        return dp[i][buy][cap] = profit;
    }

    // --------- 2. Tabulation ----------
    int tabulation(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int cap = 1; cap <= 2; ++cap) {
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

        return dp[0][1][2];
    }

    // --------- 3. Space Optimized ----------
    int spaceOptimized(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int cap = 1; cap <= 2; ++cap) {
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

        return ahead[1][2];
    }

    // --------- Main function ---------
    int maxProfit(vector<int>& prices) {
        // Uncomment one of the below approaches to use

        // 1. Memoization
        /*
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return memo(0, 1, 2, prices, dp);
        */

        // 2. Tabulation
        return tabulation(prices);

        // 3. Space Optimized
        // return spaceOptimized(prices);
    }
};
int main() {
    Solution sol;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << sol.maxProfit(prices) << endl;  // Output: 6
    return 0;
}
// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------- | ---------------- |
// | Memoization     | O(n × 2 × 3)    | O(n × 2 × 3)     |
// | Tabulation      | O(n × 2 × 3)    | O(n × 2 × 3)     |
// | Space Optimized | O(n × 2 × 3)    | O(2 × 3)         |