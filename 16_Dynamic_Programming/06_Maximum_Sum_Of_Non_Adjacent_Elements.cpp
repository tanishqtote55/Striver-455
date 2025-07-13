/*
    198. House Robber

    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

    Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

    Example 1:
    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.

    Example 2:
    Input: nums = [2,7,9,3,1]
    Output: 12
    Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
    Total amount you can rob = 2 + 9 + 1 = 12.
    
    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 400
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Memoization
    int robMemo(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];

        int pick = nums[i] + robMemo(i - 2, nums, dp);
        int skip = robMemo(i - 1, nums, dp);

        return dp[i] = max(pick, skip);
    }

    // 2. Tabulation
    int robTab(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n);
        dp[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            int pick = nums[i] + (i > 1 ? dp[i - 2] : 0);
            int skip = dp[i - 1];
            dp[i] = max(pick, skip);
        }

        return dp[n - 1];
    }

    // 3. Space Optimized
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int prev2 = 0, prev1 = nums[0];

        for (int i = 1; i < n; ++i) {
            int pick = nums[i] + prev2;
            int skip = prev1;
            int curr = max(pick, skip);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, val;

    cout << "Enter number of houses: ";
    cin >> n;
    cout << "Enter money in each house:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        nums.push_back(val);
    }

    // Memoization
    vector<int> dp(n, -1);
    cout << "Maximum money (Memoization): " << sol.robMemo(n - 1, nums, dp) << endl;

    // Tabulation
    cout << "Maximum money (Tabulation): " << sol.robTab(nums) << endl;

    // Space Optimized
    cout << "Maximum money (Space Optimized): " << sol.rob(nums) << endl;

    return 0;
}