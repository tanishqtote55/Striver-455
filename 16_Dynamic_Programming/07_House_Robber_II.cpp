/*
    213. House Robber II

    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

    Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

    Example 1:
    Input: nums = [2,3,2]
    Output: 3
    Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

    Example 2:
    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.

    Example 3:
    Input: nums = [1,2,3]
    Output: 3
    
    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 1000
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Utility for Memoization
    int robMemo(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];

        int pick = nums[i] + robMemo(i - 2, nums, dp);
        int skip = robMemo(i - 1, nums, dp);

        return dp[i] = max(pick, skip);
    }

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

    int robSpaceOptimized(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0, prev1 = 0;

        for (int i = 0; i < n; ++i) {
            int pick = nums[i] + prev2;
            int skip = prev1;
            int curr = max(pick, skip);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    // MAIN HOUSE ROBBER II WRAPPER
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Prepare two subarrays: [0...n-2] and [1...n-1]
        vector<int> first(nums.begin(), nums.end() - 1);
        vector<int> second(nums.begin() + 1, nums.end());

        // 1. Memoization
        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);
        int memoAns = max(robMemo(n - 2, first, dp1), robMemo(n - 2, second, dp2));
        cout << "Maximum money (Memoization): " << memoAns << endl;

        // 2. Tabulation
        int tabAns = max(robTab(first), robTab(second));
        cout << "Maximum money (Tabulation): " << tabAns << endl;

        // 3. Space Optimized
        int spaceAns = max(robSpaceOptimized(first), robSpaceOptimized(second));
        cout << "Maximum money (Space Optimized): " << spaceAns << endl;

        return spaceAns; // Return any one result (they're all the same)
    }
};

int main() {
    Solution sol;
    int n, val;
    vector<int> nums;

    cout << "Enter number of houses: ";
    cin >> n;
    cout << "Enter money in each house:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        nums.push_back(val);
    }

    cout << "Final answer: " << sol.rob(nums) << endl;

    return 0;
}