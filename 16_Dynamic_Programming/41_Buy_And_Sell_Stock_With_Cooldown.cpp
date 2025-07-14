/*
    309. Best Time to Buy and Sell Stock with Cooldown

    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

    Example 1:
    Input: prices = [1,2,3,0,2]
    Output: 3
    Explanation: transactions = [buy, sell, cooldown, buy, sell]

    Example 2:
    Input: prices = [1]
    Output: 0
    
    Constraints:

    1 <= prices.length <= 5000
    0 <= prices[i] <= 1000
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    // Memoization 
    int f(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + f(i + 1, 0, prices, dp), f(i + 1, 1, prices, dp));
        } else {
            profit = max(prices[i] + f(i + 2, 1, prices, dp), f(i + 1, 0, prices, dp));
        }

        return dp[i][buy] = profit;
    }

    int maxProfitMemo(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }

    // Tabulation
    int maxProfitTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));  // +2 to handle cooldown step

        for (int i = n - 1; i >= 0; --i) {
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);       // Buy
            dp[i][0] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);        // Sell
        }

        return dp[0][1];
    }

    // Space Optimized
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int ahead1_buy = 0, ahead1_notbuy = 0;  // i+1
        int ahead2_buy = 0;                    // i+2

        for (int i = n - 1; i >= 0; --i) {
            int curr_buy = max(-prices[i] + ahead1_notbuy, ahead1_buy);
            int curr_notbuy = max(prices[i] + ahead2_buy, ahead1_notbuy);

            ahead2_buy = ahead1_buy;
            ahead1_buy = curr_buy;
            ahead1_notbuy = curr_notbuy;
        }

        return ahead1_buy;
    }
};

int main() {
    Solution sol;

    vector<int> prices = {1, 2, 3, 0, 2};
    cout << sol.maxProfit(prices) << endl; // Output: 3
    return 0;
}

// | Approach        | Time Complexity | Space Complexity            |
// | --------------- | --------------- | --------------------------- |
// | Memoization     | O(n × 2)        | O(n × 2) + O(n) (recursion) |
// | Tabulation      | O(n)            | O(n × 2)                    |
// | Space Optimized | O(n)            | O(1)                        |