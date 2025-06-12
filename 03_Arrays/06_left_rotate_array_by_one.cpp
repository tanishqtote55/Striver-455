/*
    Left Rotate Array by One
    Given an integer array nums, rotate the array to the left by one.

    Note: There is no need to return anything, just modify the given array.

    Examples:
    Input: nums = [1, 2, 3, 4, 5]

    Output: [2, 3, 4, 5, 1]

    Explanation: Initially, nums = [1, 2, 3, 4, 5]

    Rotating once to left -> nums = [2, 3, 4, 5, 1]

    Input: nums = [-1, 0, 3, 6]

    Output: [0, 3, 6, -1]

    Explanation: Initially, nums = [-1, 0, 3, 6]

    Rotating once to left -> nums = [0, 3, 6, -1]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        if (nums.empty()) return;
        int temp = nums[0];
        int i = 0;
        for(i = 0; i < nums.size() - 1; i++){
            nums[i] = nums[i + 1];
        }
        nums[i] = temp;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    sol.rotateArrayByOne(nums);  // Perform left rotation

    cout << "Array after left rotation by one: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
