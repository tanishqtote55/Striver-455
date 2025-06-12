/*
    189. Rotate Array
    Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

    Example 1:

    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]
    Example 2:

    Input: nums = [-1,-100,3,99], k = 2
    Output: [3,99,-1,-100]
    Explanation: 
    rotate 1 steps to the right: [99,-1,-100,3]
    rotate 2 steps to the right: [3,99,-1,-100]
    
    Constraints:

    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105

    Follow up:

    Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
    Could you do it in-place with O(1) extra space?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Left Rotation	Reverse first k, reverse last n-k, then reverse whole array
// Right Rotation	Reverse whole array, reverse first k, reverse last n-k

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k = k % n; // Handle k > n

        // Step 1: Reverse the whole array
        reverse(nums.begin(), nums.end());
        // Step 2: Reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        // Step 3: Reverse the rest
        reverse(nums.begin() + k, nums.end());
    }
    // void rotate(vector<int>& nums, int k) {
    //     if (nums.empty()) return;
    //     for(int i = 0; i < k; i++){
    //         int temp = nums[nums.size() - 1];
    //         int j = 0;
    //         for(j = nums.size() - 1; j >= 1; j--){
    //             nums[j] = nums[j - 1];
    //         }
    //         nums[j] = temp;
    //     }
    // }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Original array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    sol.rotate(nums, k);

    cout << "Array after rotating right by " << k << " steps: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}