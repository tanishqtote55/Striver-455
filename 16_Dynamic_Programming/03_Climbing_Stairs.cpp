/*
    70. Climbing Stairs
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Example 1:
    Input: n = 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps

    Example 2:
    Input: n = 3
    Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step
    
    Constraints:

    1 <= n <= 45
*/

// Understand DP Problem
// 1. Count the Total Number Of Ways (Try All Possible Ways) => Recursion
// 2. Min Output Or Max Output       (Best Way)

// Shortcut
// 1. Try to represent the problem in terms of Index
// 2. Do all possible stuffs on that index acc to that problem statement
// 3. Sum of all stuffs => count all ways
// 4. Min(of all stuffs) => find min
// 5. Max(of all stuffs) => find max

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Memoization (Top-Down)
    int climbStairsMemo(int n, vector<int>& dp) {
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = climbStairsMemo(n - 1, dp) + climbStairsMemo(n - 2, dp);
    }

    // 2. Tabulation (Bottom-Up)
    int climbStairsTab(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }

    // 3. Space Optimized
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int prev2 = 1; // dp[0]
        int prev1 = 1; // dp[1]
        int curr;

        for (int i = 2; i <= n; ++i) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    // Memoization call
    vector<int> dp(n + 1, -1);
    cout << "Ways (Memoization): " << sol.climbStairsMemo(n, dp) << endl;

    // Tabulation call
    cout << "Ways (Tabulation): " << sol.climbStairsTab(n) << endl;

    // Space Optimized call (default)
    cout << "Ways (Space Optimized): " << sol.climbStairs(n) << endl;

    return 0;
}
