/*
    45. Jump Game II
    You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

    Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n
    Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

    Example 1:

    Input: nums = [2,3,1,1,4]
    Output: 2
    Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
    Example 2:

    Input: nums = [2,3,0,1,4]
    Output: 2
    
    Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 1000
    It's guaranteed that you can reach nums[n - 1].
*/

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    // int solve(int idx, vector<int>& nums) {
    //     int n = nums.size();
    //     if (idx >= n - 1) return 0; // already at or beyond last index

    //     if (nums[idx] == 0) return 1e9; // can't move further

    //     int minJumps = 1e9;
    //     for (int j = 1; j <= nums[idx]; j++) {
    //         minJumps = min(minJumps, 1 + solve(idx + j, nums));
    //     }

    //     return minJumps;
    // }

    // int jump(vector<int>& nums) {
    //     return solve(0, nums);
    // }

    // DP O(N^2)

    // Greedy
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int farthest = 0;
        int currentEnd = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            // If we reach the end of the current jump window
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Min jumps (Example 1): " << sol.jump(nums1) << endl; // Output: 2

    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Min jumps (Example 2): " << sol.jump(nums2) << endl; // Output: 2

    return 0;
}

// | Metric        | Value                             |
// | ------------- | --------------------------------- |
// | Time          | `O(2^n)`     (brute force)        |
// | Space (stack) | `O(n)`       (depth of recursion) |


// | Metric | Value  |
// | ------ | ------ |
// | Time   | `O(n)` |
// | Space  | `O(1)` |
