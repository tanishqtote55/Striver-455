/*
    416. Partition Equal Subset Sum

    Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

    Example 1:
    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].

    Example 2:
    Input: nums = [1,2,3,5]
    Output: false
    Explanation: The array cannot be partitioned into equal sum subsets.
    
    Constraints:

    1 <= nums.length <= 200
    1 <= nums[i] <= 100
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Memoization
    bool f(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i == 0) return nums[0] == target;
        if (dp[i][target] != -1) return dp[i][target];

        bool notTake = f(i - 1, target, nums, dp);
        bool take = false;
        if (nums[i] <= target)
            take = f(i - 1, target - nums[i], nums, dp);

        return dp[i][target] = take || notTake;
    }

    // 2. Tabulation
    bool tabulation(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (nums[0] <= target) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = dp[i - 1][t];
                bool take = false;
                if (nums[i] <= t)
                    take = dp[i - 1][t - nums[i]];
                dp[i][t] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }

    // 3. Space Optimized
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        int target = sum / 2;

        int n = nums.size();
        vector<bool> prev(target + 1, false), curr(target + 1, false);
        prev[0] = curr[0] = true;
        if (nums[0] <= target) prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = prev[t];
                bool take = false;
                if (nums[i] <= t)
                    take = prev[t - nums[i]];
                curr[t] = take || notTake;
            }
            prev = curr;
        }

        return prev[target];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 5, 11, 5}; // Expected: true
    vector<int> nums2 = {1, 2, 3, 5};  // Expected: false

    cout << "Can partition nums1? " << (sol.canPartition(nums1) ? "Yes" : "No") << endl;
    cout << "Can partition nums2? " << (sol.canPartition(nums2) ? "Yes" : "No") << endl;

    return 0;
}

// | Approach        | Time       | Space                   |
// | --------------- | ---------- | ----------------------- |
// | Memoization     | O(N × S/2) | O(N × S/2) + Rec. stack |
// | Tabulation      | O(N × S/2) | O(N × S/2)              |
// | Space Optimized | O(N × S/2) | O(S/2)                  |
