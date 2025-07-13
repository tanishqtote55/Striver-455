/*
    Frog jump with K distances

    A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.

    To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

    Examples:
    Input: heights = [10, 5, 20, 0, 15], k = 2
    Output: 15
    Explanation:
    0th step -> 2nd step, cost = abs(10 - 20) = 10
    2nd step -> 4th step, cost = abs(20 - 15) = 5
    Total cost = 10 + 5 = 15.

    Input: heights = [15, 4, 1, 14, 15], k = 3
    Output: 2
    Explanation:
    0th step -> 3rd step, cost = abs(15 - 14) = 1
    3rd step -> 4th step, cost = abs(14 - 15) = 1
    Total cost = 1 + 1 = 2.
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    // 1. Memoization TC O(N * K) SC O(2N)
    int frogJumpMemo(int i, vector<int>& heights, int k, vector<int>& dp) {
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];

        int minCost = INT_MAX;

        for (int j = 1; j <= k; ++j) {
            if (i - j >= 0) {
                int jump = frogJumpMemo(i - j, heights, k, dp) + abs(heights[i] - heights[i - j]);
                minCost = min(minCost, jump);
            }
        }

        return dp[i] = minCost;
    }

    // 2. Tabulation TC O(N * K) O(N)
    int frogJumpTab(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, 0);
        dp[0] = 0;

        for (int i = 1; i < n; ++i) {
            int minCost = INT_MAX;
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) {
                    int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                    minCost = min(minCost, jump);
                }
            }
            dp[i] = minCost;
        }

        return dp[n - 1];
    }

    // 3. Space Optimized (not fully optimized to O(1), but can be optimized to O(k) instead of O(n))
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> prev(k + 1, INT_MAX);
        prev[0] = 0;  // Represents dp[0]

        for (int i = 1; i < n; ++i) {
            int minCost = INT_MAX;
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) {
                    int cost = prev[(i - j) % (k + 1)] + abs(heights[i] - heights[i - j]);
                    minCost = min(minCost, cost);
                }
            }
            prev[i % (k + 1)] = minCost;
        }

        return prev[(n - 1) % (k + 1)];
    }
};

int main() {
    Solution sol;
    int n, k, h;
    vector<int> heights;

    cout << "Enter number of steps: ";
    cin >> n;
    cout << "Enter value of k: ";
    cin >> k;

    cout << "Enter heights:\n";
    for (int i = 0; i < n; ++i) {
        cin >> h;
        heights.push_back(h);
    }

    // Memoization
    vector<int> dp(n, -1);
    cout << "Minimum energy (Memoization): " << sol.frogJumpMemo(n - 1, heights, k, dp) << endl;

    // Tabulation
    cout << "Minimum energy (Tabulation): " << sol.frogJumpTab(heights, k) << endl;

    // Space Optimized
    cout << "Minimum energy (Space Optimized): " << sol.frogJump(heights, k) << endl;

    return 0;
}