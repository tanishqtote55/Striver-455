/*
    Minimum coins
    Given an integer array of coins representing coins of different denominations and an integer amount representing a total amount of money. Return the fewest number of coins that are needed to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. There are infinite numbers of coins of each type


    Examples:
    Input: coins = [1, 2, 5], amount = 11

    Output: 3

    Explanation: 11 = 5 + 5 + 1. We need 3 coins to make up the amount 11.

    Input: coins = [2, 5], amount = 3

    Output: -1

    Explanation: It's not possible to make amount 3 with coins 2 and 5. Since we can't combine the coin 2 and 5 to make the amount 3, the output is -1.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
	int MinimumCoins(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend()); // sort descending
        int count = 0;

        for (int coin : coins) {
            if (amount >= coin) {
                int take = amount / coin;
                amount -= take * coin;
                count += take;
            }
        }

        return amount == 0 ? count : -1; // if any amount is left, it's not possible        
    }
    // DP Solution Time: O(N × amount), where N = number of coins. Space: O(amount)
    int MinimumCoins(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // Initialize with amount+1 (infinity)
        dp[0] = 0;

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Output 1: " << sol.MinimumCoins(coins1, amount1) << endl;  // Output: 3 (works)

    vector<int> coins2 = {2, 5};
    int amount2 = 3;
    cout << "Output 2: " << sol.MinimumCoins(coins2, amount2) << endl;  // Output: -1 (works)

    vector<int> coins3 = {1, 3, 4};
    int amount3 = 6;
    cout << "Output 3 (Greedy fails): " << sol.MinimumCoins(coins3, amount3) << endl;  // Output: 3 (wrong, optimal is 2)

    return 0;
}

// | Complexity | Value        |
// | ---------- | ------------ |
// | **Time**   | `O(N log N)` |
// | **Space**  | `O(1)`       |
