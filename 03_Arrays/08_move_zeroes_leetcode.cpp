/*
    283. Move Zeroes
    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Note that you must do this in-place without making a copy of the array.

    Example 1:

    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
    Example 2:

    Input: nums = [0]
    Output: [0]    

    Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1
    
    Follow up: Could you minimize the total number of operations done?
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroIndex = 0;

        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroIndex++] = nums[i];
            }
        }

        // Fill remaining positions with zero
        for (int i = lastNonZeroIndex; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Original array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    sol.moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}