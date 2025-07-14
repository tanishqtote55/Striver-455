/*
    121. Best Time to Buy and Sell Stock

    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

    Example 1:
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

    Example 2:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.
    
    Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < n; ++i) {
            int profitToday = prices[i] - minPrice;
            maxProfit = max(maxProfit, profitToday);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
int main() {
    Solution sol;

    // Example 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit (Example 1): " << sol.maxProfit(prices1) << endl; // Expected: 5

    // Example 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Max Profit (Example 2): " << sol.maxProfit(prices2) << endl; // Expected: 0

    return 0;
}

// | Metric           | Value |
// | ---------------- | ----- |
// | Time Complexity  | O(n)  |
// | Space Complexity | O(1)  |