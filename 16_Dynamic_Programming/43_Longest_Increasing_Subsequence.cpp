/*
    300. Longest Increasing Subsequence

    Given an integer array nums, return the length of the longest strictly increasing subsequence.

    Example 1:
    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

    Example 2:
    Input: nums = [0,1,0,3,2,3]
    Output: 4

    Example 3:
    Input: nums = [7,7,7,7,7,7,7]
    Output: 1
    
    Constraints:

    1 <= nums.length <= 2500
    -104 <= nums[i] <= 104
    
    Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ---------- 1. MEMOIZATION ----------
    int memoHelper(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;
        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int notTake = memoHelper(i + 1, prev, nums, dp);
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev])
            take = 1 + memoHelper(i + 1, i, nums, dp);

        return dp[i][prev + 1] = max(take, notTake);
    }

    int lengthOfLISMemo(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return memoHelper(0, -1, nums, dp);
    }

    // ---------- 2. TABULATION ----------
    int lengthOfLISTab(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int prev = i - 1; prev >= -1; --prev) {
                int notTake = dp[i + 1][prev + 1];
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev])
                    take = 1 + dp[i + 1][i + 1];

                dp[i][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }

    // ---------- 3. SPACE OPTIMIZED ----------
    int lengthOfLISSpaceOptimized(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0), curr(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            for (int prev = i - 1; prev >= -1; --prev) {
                int notTake = next[prev + 1];
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev])
                    take = 1 + next[i + 1];

                curr[prev + 1] = max(take, notTake);
            }
            next = curr;
        }

        return next[0];
    }

    // ---------- 4. BINARY SEARCH (O(n log n)) ----------
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        for (int num : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            if (it == lis.end())
                lis.push_back(num);
            else
                *it = num;
        }
        return lis.size();
    }
};
int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}
// | Approach               | Time Complexity | Space Complexity |
// | ---------------------- | --------------- | ---------------- |
// | Memoization (Top-Down) | O(n²)           | O(n²)            |
// | Tabulation             | O(n²)           | O(n²)            |
// | Space Optimized        | O(n²)           | O(n)             |
// | Binary Search (Greedy) | **O(n log n)**  | O(n)             |