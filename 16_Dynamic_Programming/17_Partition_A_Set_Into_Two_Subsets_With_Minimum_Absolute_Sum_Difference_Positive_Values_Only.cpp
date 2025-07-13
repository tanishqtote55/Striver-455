
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

    // ✅ 1. Memoization: TC = O(n * sum), SC = O(n * sum) + O(n) recursion
    bool subsetSumMemo(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind == 0) return arr[0] == target;
        if (dp[ind][target] != -1) return dp[ind][target];

        bool notTake = subsetSumMemo(ind - 1, target, arr, dp);
        bool take = false;
        if (arr[ind] <= target)
            take = subsetSumMemo(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = take || notTake;
    }

    int minSubsetSumDiffMemo(vector<int>& arr) {
        int n = arr.size();
        int totSum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

        for (int i = 0; i <= totSum; ++i) {
            subsetSumMemo(n - 1, i, arr, dp);
        }

        int mini = INT_MAX;
        for (int i = 0; i <= totSum; ++i) {
            if (dp[n - 1][i] == true) {
                int diff = abs(i - (totSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }

    // ✅ 2. Tabulation: TC = O(n * sum), SC = O(n * sum)
    int minSubsetSumDiffTab(vector<int>& arr) {
        int n = arr.size();
        int totSum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));

        for (int i = 0; i < n; ++i) dp[i][0] = true;
        if (arr[0] <= totSum) dp[0][arr[0]] = true;

        for (int ind = 1; ind < n; ++ind) {
            for (int target = 1; target <= totSum; ++target) {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (arr[ind] <= target)
                    take = dp[ind - 1][target - arr[ind]];

                dp[ind][target] = take || notTake;
            }
        }

        int mini = INT_MAX;
        for (int i = 0; i <= totSum; ++i) {
            if (dp[n - 1][i]) {
                int diff = abs(i - (totSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }

    // ✅ 3. Space Optimized: TC = O(n * sum), SC = O(sum)
    int minSubsetSumDiffSpaceOpt(vector<int>& arr) {
        int n = arr.size();
        int totSum = accumulate(arr.begin(), arr.end(), 0);

        vector<bool> prev(totSum + 1, false), cur(totSum + 1, false);
        prev[0] = true;
        if (arr[0] <= totSum) prev[arr[0]] = true;

        for (int ind = 1; ind < n; ++ind) {
            cur[0] = true;
            for (int target = 1; target <= totSum; ++target) {
                bool notTake = prev[target];
                bool take = false;
                if (arr[ind] <= target)
                    take = prev[target - arr[ind]];
                cur[target] = take || notTake;
            }
            prev = cur;
        }

        int mini = INT_MAX;
        for (int i = 0; i <= totSum; ++i) {
            if (prev[i]) {
                int diff = abs(i - (totSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 5};

    cout << "Minimum Subset Sum Difference (Memoization): " << sol.minSubsetSumDiffMemo(arr) << endl;
    cout << "Minimum Subset Sum Difference (Tabulation): " << sol.minSubsetSumDiffTab(arr) << endl;
    cout << "Minimum Subset Sum Difference (Space Optimized): " << sol.minSubsetSumDiffSpaceOpt(arr) << endl;

    return 0;
}