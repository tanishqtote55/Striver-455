/*
    494. Target Sum

    You are given an integer array nums and an integer target.

    You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

    For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
    Return the number of different expressions that you can build, which evaluates to target.

    Example 1:
    Input: nums = [1,1,1,1,1], target = 3
    Output: 5
    Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3

    Example 2:
    Input: nums = [1], target = 1
    Output: 1
    
    Constraints:
    1 <= nums.length <= 20
    0 <= nums[i] <= 1000
    0 <= sum(nums[i]) <= 1000
    -1000 <= target <= 1000
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Memoization
    int memoHelper(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == 0) {
            if (sum == 0 && nums[0] == 0) return 2; // +0 and -0
            if (sum == 0 || sum == nums[0]) return 1;
            return 0;
        }
        if (dp[i][sum] != -1) return dp[i][sum];

        int notTake = memoHelper(i - 1, sum, nums, dp);
        int take = 0;
        if (nums[i] <= sum)
            take = memoHelper(i - 1, sum - nums[i], nums, dp);

        return dp[i][sum] = take + notTake;
    }

    int findTargetSumWaysMemo(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if ((target + totalSum) % 2 != 0 || abs(target) > totalSum) return 0;

        int newTarget = (target + totalSum) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(newTarget + 1, -1));
        return memoHelper(n - 1, newTarget, nums, dp);
    }

    // 2. Tabulation
    int findTargetSumWaysTab(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if ((target + totalSum) % 2 != 0 || abs(target) > totalSum) return 0;

        int newTarget = (target + totalSum) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(newTarget + 1, 0));

        // base case
        if (nums[0] == 0) dp[0][0] = 2; // +0 and -0
        else dp[0][0] = 1;
        if (nums[0] != 0 && nums[0] <= newTarget)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < n; ++i) {
            for (int sum = 0; sum <= newTarget; ++sum) {
                int notTake = dp[i - 1][sum];
                int take = 0;
                if (nums[i] <= sum)
                    take = dp[i - 1][sum - nums[i]];
                dp[i][sum] = take + notTake;
            }
        }

        return dp[n - 1][newTarget];
    }

    // 3. Space Optimized
    int findTargetSumWaysSpaceOpt(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if ((target + totalSum) % 2 != 0 || abs(target) > totalSum) return 0;

        int newTarget = (target + totalSum) / 2;
        int n = nums.size();

        vector<int> prev(newTarget + 1, 0), curr(newTarget + 1, 0);

        if (nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if (nums[0] != 0 && nums[0] <= newTarget)
            prev[nums[0]] = 1;

        for (int i = 1; i < n; ++i) {
            curr = vector<int>(newTarget + 1, 0);
            for (int sum = 0; sum <= newTarget; ++sum) {
                int notTake = prev[sum];
                int take = 0;
                if (nums[i] <= sum)
                    take = prev[sum - nums[i]];
                curr[sum] = take + notTake;
            }
            prev = curr;
        }

        return prev[newTarget];
    }
};
int main() {
    Solution sol;
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;

    cout << "Memoization: " << sol.findTargetSumWaysMemo(nums1, target1) << endl;
    cout << "Tabulation: " << sol.findTargetSumWaysTab(nums1, target1) << endl;
    cout << "Space Optimized: " << sol.findTargetSumWaysSpaceOpt(nums1, target1) << endl;

    vector<int> nums2 = {1};
    int target2 = 1;

    cout << "Memoization: " << sol.findTargetSumWaysMemo(nums2, target2) << endl;
    cout << "Tabulation: " << sol.findTargetSumWaysTab(nums2, target2) << endl;
    cout << "Space Optimized: " << sol.findTargetSumWaysSpaceOpt(nums2, target2) << endl;

    return 0;
}
// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------- | ---------------- |
// | Memoization     | O(n × sum)      | O(n × sum)       |
// | Tabulation      | O(n × sum)      | O(n × sum)       |
// | Space Optimized | O(n × sum)      | O(sum)           |