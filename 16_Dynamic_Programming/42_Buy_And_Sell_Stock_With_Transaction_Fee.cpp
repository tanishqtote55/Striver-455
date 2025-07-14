/*
    714. Best Time to Buy and Sell Stock with Transaction Fee

    You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

    Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

    Note:
    You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
    The transaction fee is only charged once for each stock purchase and sale.
    
    Example 1:
    Input: prices = [1,3,2,8,4,9], fee = 2
    Output: 8
    Explanation: The maximum profit can be achieved by:
    - Buying at prices[0] = 1
    - Selling at prices[3] = 8
    - Buying at prices[4] = 4
    - Selling at prices[5] = 9
    The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

    Example 2:
    Input: prices = [1,3,7,5,10,3], fee = 3
    Output: 6
    
    Constraints:
    1 <= prices.length <= 5 * 104
    1 <= prices[i] < 5 * 104
    0 <= fee < 5 * 104
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ----------- 1. MEMOIZATION ----------
    int memoHelper(int i, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if (i == prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + memoHelper(i + 1, 0, prices, fee, dp), 
                          memoHelper(i + 1, 1, prices, fee, dp));
        } else {
            profit = max(prices[i] - fee + memoHelper(i + 1, 1, prices, fee, dp), 
                          memoHelper(i + 1, 0, prices, fee, dp));
        }

        return dp[i][buy] = profit;
    }

    int maxProfitMemo(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return memoHelper(0, 1, prices, fee, dp);
    }

    // ----------- 2. TABULATION ----------
    int maxProfitTab(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; --i) {
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            dp[i][0] = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
        }

        return dp[0][1];
    }

    // ----------- 3. SPACE OPTIMIZED ----------
    int maxProfitSpaceOptimized(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadBuy = 0, aheadNotBuy = 0, currBuy = 0, currNotBuy = 0;

        for (int i = n - 1; i >= 0; --i) {
            currBuy = max(-prices[i] + aheadNotBuy, aheadBuy);
            currNotBuy = max(prices[i] - fee + aheadBuy, aheadNotBuy);

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        return currBuy;
    }

    // ----------- MAIN FUNCTION -----------
    int maxProfit(vector<int>& prices, int fee) {
        // Choose one implementation here
        // return maxProfitMemo(prices, fee);
        // return maxProfitTab(prices, fee);
        return maxProfitSpaceOptimized(prices, fee);
    }
};
int main() {
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << "Max Profit: " << sol.maxProfit(prices, fee) << endl;  // Output: 8
    return 0;
}

// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------- | ---------------- |
// | Memoization     | O(N × 2)        | O(N × 2 + N)     |
// | Tabulation      | O(N × 2)        | O(N × 2)         |
// | Space Optimized | O(N)            | O(1)             |