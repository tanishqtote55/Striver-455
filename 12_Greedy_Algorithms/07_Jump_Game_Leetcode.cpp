/*
    55. Jump Game
    You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

    Return true if you can reach the last index, or false otherwise.

    Example 1:

    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
    Example 2:

    Input: nums = [3,2,1,0,4]
    Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

    Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 105
*/

// | Metric | Value |
// | ------ | ----- |
// | Time   | O(n)  |
// | Space  | O(1)  |

#include <iostream>
#include <vector>
#include <algorithm> // for max()
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest) return false; // can't reach this index
            farthest = max(farthest, i + nums[i]); // update farthest reachable
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Can jump (Example 1): " << boolalpha << sol.canJump(nums1) << endl; // true

    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Can jump (Example 2): " << boolalpha << sol.canJump(nums2) << endl; // false

    return 0;
}
