/*
    Count subsets with sum K

    Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K. Return the result modulo (109 + 7).

    Examples:
    Input: arr = [2, 3, 5, 16, 8, 10], K = 10
    Output: 3
    Explanation: The subsets are [2, 8], [10], and [2, 3, 5].

    Input: arr = [1, 2, 3, 4, 5], K = 5
    Output: 3
    Explanation: The subsets are [5], [2, 3], and [1, 4].
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    // Memoization
    int countSubsets(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == 0) {
            if (sum == 0 && arr[0] == 0) return 2; // {} and {0}
            if (sum == 0 || sum == arr[0]) return 1;
            return 0;
        }

        if (dp[i][sum] != -1) return dp[i][sum];

        int notTake = countSubsets(i - 1, sum, arr, dp);
        int take = 0;
        if (arr[i] <= sum) {
            take = countSubsets(i - 1, sum - arr[i], arr, dp);
        }

        return dp[i][sum] = (take + notTake) % MOD;
    }

    int perfectSumMem(vector<int>& arr, int K) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(K + 1, -1));
        return countSubsets(n - 1, K, arr, dp);
    }

    // Tabulation (Bottom-Up DP):
    int perfectSumTab(vector<int>& arr, int K) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        // Initialization
        if (arr[0] == 0)
            dp[0][0] = 2; // {} and {0}
        else {
            dp[0][0] = 1; // {}
            if (arr[0] <= K)
                dp[0][arr[0]] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int sum = 0; sum <= K; ++sum) {
                int notTake = dp[i - 1][sum];
                int take = 0;
                if (arr[i] <= sum)
                    take = dp[i - 1][sum - arr[i]];

                dp[i][sum] = (take + notTake) % MOD;
            }
        }

        return dp[n - 1][K];
    }

    // Space Optimized:
    int perfectSum(vector<int>& arr, int K) {
        int n = arr.size();
        vector<int> prev(K + 1, 0), curr(K + 1, 0);

        if (arr[0] == 0)
            prev[0] = 2; // {} and {0}
        else {
            prev[0] = 1; // {}
            if (arr[0] <= K)
                prev[arr[0]] = 1;
        }

        for (int i = 1; i < n; ++i) {
            curr[0] = 1;
            for (int sum = 0; sum <= K; ++sum) {
                int notTake = prev[sum];
                int take = 0;
                if (arr[i] <= sum)
                    take = prev[sum - arr[i]];
                curr[sum] = (take + notTake) % MOD;
            }
            prev = curr;
        }

        return prev[K];
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {2, 3, 5, 16, 8, 10};
    int k1 = 10;
    cout << "Output 1: " << sol.perfectSum(arr1, k1) << endl; // Expected: 3

    vector<int> arr2 = {1, 2, 3, 4, 5};
    int k2 = 5;
    cout << "Output 2: " << sol.perfectSum(arr2, k2) << endl; // Expected: 3

    vector<int> arr3 = {0, 0, 1};
    int k3 = 1;
    cout << "Output 3: " << sol.perfectSum(arr3, k3) << endl; // Expected: 4

    return 0;
}

// | **Approach**           | **Time Complexity** | **Space Complexity**            | **Remarks**                        |
// | ---------------------- | ------------------- | ------------------------------- | ---------------------------------- |
// | Memoization (Top-Down) | O(N × K)            | O(N × K) + O(N) recursion stack | Uses recursion + memoization table |
// | Tabulation (Bottom-Up) | O(N × K)            | O(N × K)                        | Iterative DP table                 |
// | Space Optimized        | O(N × K)            | O(K)                            | Only two 1D arrays needed          |
