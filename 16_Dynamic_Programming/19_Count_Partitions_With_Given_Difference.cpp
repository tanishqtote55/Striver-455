/*
    Count partitions with given difference

    Given an array arr of n integers and an integer diff, count the number of ways to partition the array into two subsets such that the absolute difference between their sums is equal to diff. Return the result modulo 109+7.

    Examples:
    Input: arr = [1, 1, 2, 3], diff = 1
    Output: 3
    Explanation: The subsets are [1, 2] and [1, 3], [1, 3] and [1, 2], [1, 1, 2] and [3].

    Input: arr = [1, 2, 3, 4], diff = 2
    Output: 2
    Explanation: The subsets are [1, 3] and [2, 4], [1, 2, 3] and [4].
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
#include <unordered_map>

using namespace std;

// S1 - S2 = diff
// S1 + S2 = totalSum
// ----------------------
// => 2*S1 = totalSum + diff
// => S1 = (totalSum + diff) / 2

class Solution {
public:
    const int MOD = 1e9 + 7;

    // ---------- Memoization ----------
    int f(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == 0) {
            if (target == 0 && arr[0] == 0) return 2; // pick or not pick zero
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }

        if (dp[i][target] != -1) return dp[i][target];

        int notPick = f(i - 1, target, arr, dp);
        int pick = 0;
        if (arr[i] <= target) pick = f(i - 1, target - arr[i], arr, dp);

        return dp[i][target] = (pick + notPick) % MOD;
    }

    // ---------- Tabulation ----------
    int tabulation(int n, int target, vector<int>& arr) {
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base cases
        if (arr[0] == 0)
            dp[0][0] = 2; // pick or not pick
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= target; t++) {
                int notPick = dp[i - 1][t];
                int pick = 0;
                if (arr[i] <= t) pick = dp[i - 1][t - arr[i]];
                dp[i][t] = (pick + notPick) % MOD;
            }
        }

        return dp[n - 1][target];
    }

    // ---------- Space Optimization ----------
    int spaceOptimized(int n, int target, vector<int>& arr) {
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        if (arr[0] == 0)
            prev[0] = 2;
        else {
            prev[0] = 1;
            if (arr[0] <= target)
                prev[arr[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            curr[0] = 1;
            for (int t = 0; t <= target; t++) {
                int notPick = prev[t];
                int pick = 0;
                if (arr[i] <= t) pick = prev[t - arr[i]];
                curr[t] = (pick + notPick) % MOD;
            }
            prev = curr;
        }

        return prev[target];
    }

    // ---------- Main Function ----------
    int countPartitions(int n, int diff, vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if ((totalSum + diff) % 2 != 0) return 0;
        int target = (totalSum + diff) / 2;

        // Choose one of the 3 approaches:
        
        // --- 1. Memoization ---
        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return f(n - 1, target, arr, dp);

        // --- 2. Tabulation ---
        // return tabulation(n, target, arr);

        // --- 3. Space Optimized ---
        return spaceOptimized(n, target, arr);
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {1, 1, 2, 3};
    int diff1 = 1;
    cout << "Output 1: " << sol.countPartitions(arr1.size(), diff1, arr1) << endl; // Expected: 3

    vector<int> arr2 = {1, 2, 3, 4};
    int diff2 = 2;
    cout << "Output 2: " << sol.countPartitions(arr2.size(), diff2, arr2) << endl; // Expected: 2

    vector<int> arr3 = {0, 0, 0, 0};
    int diff3 = 0;
    cout << "Output 3: " << sol.countPartitions(arr3.size(), diff3, arr3) << endl; // Expected: 16 (2^4)

    return 0;
}

// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------- | ---------------- |
// | Memoization     | O(N \* target)  | O(N \* target)   |
// | Tabulation      | O(N \* target)  | O(N \* target)   |
// | Space Optimized | O(N \* target)  | O(target)        |