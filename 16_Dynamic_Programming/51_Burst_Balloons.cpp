/*
    312. Burst Balloons

    You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

    If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

    Return the maximum coins you can collect by bursting the balloons wisely.

    Example 1:
    Input: nums = [3,1,5,8]
    Output: 167
    Explanation:
    nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
    coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

    Example 2:
    Input: nums = [1,5]
    Output: 10
    
    Constraints:

    n == nums.length
    1 <= n <= 300
    0 <= nums[i] <= 100
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    // ---------------- MEMOIZATION ----------------
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int maxi = 0;
        for (int k = i; k <= j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1] +
                        f(i, k - 1, nums, dp) +
                        f(k + 1, j, nums, dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }

    // ---------------- TABULATION ----------------
    int tabulation(vector<int> nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = n - 2; i >= 1; i--) {
            for (int j = i; j <= n - 2; j++) {
                int maxi = 0;
                for (int k = i; k <= j; k++) {
                    int coins = nums[i - 1] * nums[k] * nums[j + 1] +
                                dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n - 2];
    }

    // ---------------- SPACE OPTIMIZATION ----------------
    // Not practical for 1D/2D interval problems like this one
    int spaceOptimized(vector<int> nums) {
        return tabulation(nums); // fallback to tabulation
    }

    // ---------------- MAIN DRIVER ----------------
    int maxCoins(vector<int>& originalNums) {
        vector<int> nums;
        nums.push_back(1); // virtual balloon on the left
        for (int x : originalNums) if (x > 0) nums.push_back(x); // skip zeroes
        nums.push_back(1); // virtual balloon on the right

        int n = nums.size();

        // 1. Memoization
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return f(1, n - 2, nums, dp);

        // 2. Tabulation
        return tabulation(nums);

        // 3. Space Optimization (same as tab here)
        // return spaceOptimized(nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 5, 8};
    cout << sol.maxCoins(nums) << endl;  // Output: 167
    return 0;
}

// | Approach        | Time Complexity  | Space Complexity |
// | --------------- | ---------------- | ---------------- |
// | Memoization     | O(n³)            | O(n²)            |
// | Tabulation      | O(n³)            | O(n²)            |
// | Space Optimized |  Not applicable  | —                |