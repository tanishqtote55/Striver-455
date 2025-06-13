/*
    136. Single Number
    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

    You must implement a solution with a linear runtime complexity and use only constant extra space.

    Example 1:

    Input: nums = [2,2,1]

    Output: 1

    Example 2:

    Input: nums = [4,1,2,1,2]

    Output: 4

    Example 3:

    Input: nums = [1]

    Output: 1
    
    Constraints:

    1 <= nums.length <= 3 * 104
    -3 * 104 <= nums[i] <= 3 * 104
    Each element in the array appears twice except for one element which appears only once.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int singleNumber(vector<int>& nums) {
    //     for(int i = 0; i < nums.size(); i++){
    //         int find = 0;
    //         for(int j = 0; j < nums.size(); j++){
    //             if(i != j && nums[i] == nums[j]){
    //                 find = 1;
    //                 break;
    //             }
    //         }
    //         if(find == 0){
    //             return nums[i];
    //         }
    //     }
    //     return -1;
    // }

    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    Solution sol;
    cout << sol.singleNumber(nums) << '\n';

    return 0;
}
