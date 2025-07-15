/*
    1043. Partition Array for Maximum Sum

    Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

    Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

    Example 1:
    Input: arr = [1,15,7,9,2,5,10], k = 3
    Output: 84
    Explanation: arr becomes [15,15,15,9,10,10,10]

    Example 2:
    Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
    Output: 83

    Example 3:
    Input: arr = [1], k = 1
    Output: 1
    
    Constraints:
    1 <= arr.length <= 500
    0 <= arr[i] <= 109
    1 <= k <= arr.length
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive
    int solveRec(int i, vector<int>& arr, int k) {
        if (i == arr.size()) return 0;

        int maxVal = 0, maxSum = 0;
        for (int j = i; j < min((int)arr.size(), i + k); ++j) {
            maxVal = max(maxVal, arr[j]);
            int sum = maxVal * (j - i + 1) + solveRec(j + 1, arr, k);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }

    // Memoization
    int solveMemo(int i, vector<int>& arr, int k, vector<int>& dp) {
        if (i == arr.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int maxVal = 0, maxSum = 0;
        for (int j = i; j < min((int)arr.size(), i + k); ++j) {
            maxVal = max(maxVal, arr[j]);
            int sum = maxVal * (j - i + 1) + solveMemo(j + 1, arr, k, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[i] = maxSum;
    }

    // Tabulation
    int solveTab(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int maxVal = 0, maxSum = 0;
            for (int j = i; j < min(n, i + k); ++j) {
                maxVal = max(maxVal, arr[j]);
                int sum = maxVal * (j - i + 1) + dp[j + 1];
                maxSum = max(maxSum, sum);
            }
            dp[i] = maxSum;
        }

        return dp[0];
    }

    // Space Optimized (Same as tabulation, already 1D)
    int solveSpaceOptimized(vector<int>& arr, int k) {
        return solveTab(arr, k); // Already optimized
    }

    // Main method
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        // --- Recursive ---
        // return solveRec(0, arr, k);

        // --- Memoization ---
        // vector<int> dp(n, -1);
        // return solveMemo(0, arr, k, dp);

        // --- Tabulation ---
        return solveTab(arr, k);

        // --- Space Optimized ---
        // return solveSpaceOptimized(arr, k);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout << sol.maxSumAfterPartitioning(arr, k) << endl; // Output: 84
    return 0;
}

// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------- | ---------------- |
// | Recursive       | O(kⁿ)           | O(1)             |
// | Memoization     | O(n·k)          | O(n)             |
// | Tabulation      | O(n·k)          | O(n)             |
// | Space Optimized | O(n·k)          | O(n)             |