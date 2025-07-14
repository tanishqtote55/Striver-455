/*
    122. Best Time to Buy and Sell Stock II
    You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

    On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

    Find and return the maximum profit you can achieve.

    Example 1:
    Input: prices = [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
    Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
    Total profit is 4 + 3 = 7.

    Example 2:
    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Total profit is 4.

    Example 3:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
    
    Constraints:
    1 <= prices.length <= 3 * 104
    0 <= prices[i] <= 104
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    // 1. Greedy Approach (Optimal)
    int maxProfitGreedy(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }

    // Memoization
    int memo(int i, int canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size()) return 0;
        if (dp[i][canBuy] != -1) return dp[i][canBuy];

        int profit = 0;
        if (canBuy) {
            profit = max(-prices[i] + memo(i + 1, 0, prices, dp), 0 + memo(i + 1, 1, prices, dp));
        } else {
            profit = max(prices[i] + memo(i + 1, 1, prices, dp), 0 + memo(i + 1, 0, prices, dp));
        }

        return dp[i][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return memo(0, 1, prices, dp);
    }

    // 3. DP Tabulation
    int maxProfitTabulation(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // dp[day][canBuy]
        
        for (int day = n - 1; day >= 0; --day) {
            for (int canBuy = 0; canBuy <= 1; ++canBuy) {
                if (canBuy) {
                    dp[day][canBuy] = max(-prices[day] + dp[day + 1][0], 0 + dp[day + 1][1]);
                } else {
                    dp[day][canBuy] = max(prices[day] + dp[day + 1][1], 0 + dp[day + 1][0]);
                }
            }
        }
        return dp[0][1]; // Starting with day 0 and canBuy = 1
    }

    // 4. DP Space Optimized
    int maxProfitSpaceOptimized(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);

        for (int day = n - 1; day >= 0; --day) {
            for (int canBuy = 0; canBuy <= 1; ++canBuy) {
                if (canBuy) {
                    curr[canBuy] = max(-prices[day] + ahead[0], 0 + ahead[1]);
                } else {
                    curr[canBuy] = max(prices[day] + ahead[1], 0 + ahead[0]);
                }
            }
            ahead = curr;
        }
        return ahead[1];
    }
};
int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Greedy Profit: " << sol.maxProfitGreedy(prices) << endl;
    cout << "Memoization: " << sol.maxProfit(prices) << endl;
    cout << "DP Tabulation Profit: " << sol.maxProfitTabulation(prices) << endl;
    cout << "DP Space Optimized Profit: " << sol.maxProfitSpaceOptimized(prices) << endl;

    return 0;
}


// | Approach      | Time Complexity | Space Complexity  |
// | ------------- | --------------- | ----------------  |
// | Greedy        | O(n)            | O(1)              |
// | Memoization   | O(n)            | O(nx2) + O(n)Stack|
// | DP Tabulation | O(n)            | O(n×2) = O(n)     |
// | DP Space Opt. | O(n)            | O(2) = O(1)       |