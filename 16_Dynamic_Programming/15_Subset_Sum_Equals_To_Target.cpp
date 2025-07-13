/*
    Subset sum equals to target

    Given an array arr of n integers and an integer target, determine if there is a subset of the given array with a sum equal to the given target.

    Examples:
    Input: arr = [1, 2, 7, 3], target = 6
    Output: True
    Explanation: There is a subset (1, 2, 3) with sum 6.

    Input: arr = [2, 3, 5], target = 6
    Output: False
    Explanation: There is no subset with sum 6.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Memoization
    bool f(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i == 0) return arr[0] == target;
        if (dp[i][target] != -1) return dp[i][target];

        bool notTake = f(i - 1, target, arr, dp);
        bool take = false;
        if (arr[i] <= target) take = f(i - 1, target - arr[i], arr, dp);

        return dp[i][target] = take || notTake;
    }

    // 2. Tabulation
    bool tabulation(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true; // sum 0 is always possible
        if (arr[0] <= target) dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = dp[i - 1][t];
                bool take = false;
                if (arr[i] <= t) take = dp[i - 1][t - arr[i]];

                dp[i][t] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }

    // 3. Space Optimized
    bool isSubsetSum(vector<int> arr, int target) {
        int n = arr.size();
        vector<bool> prev(target + 1, false), curr(target + 1, false);

        prev[0] = curr[0] = true;
        if (arr[0] <= target) prev[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = prev[t];
                bool take = false;
                if (arr[i] <= t) take = prev[t - arr[i]];
                curr[t] = take || notTake;
            }
            prev = curr;
        }

        return prev[target];
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1, 2, 7, 3};
    int target1 = 6;
    cout << boolalpha << sol.isSubsetSum(arr1, target1) << endl; // True

    vector<int> arr2 = {2, 3, 5};
    int target2 = 6;
    cout << boolalpha << sol.isSubsetSum(arr2, target2) << endl; // False

    return 0;
}

// | Approach        | Time          | Space                           |
// | --------------- | ------------- | ------------------------------- |
// | Memoization     | O(n × target) | O(n × target) + recursion stack |
// | Tabulation      | O(n × target) | O(n × target)                   |
// | Space Optimized | O(n × target) | O(target)                       |