/*
    53. Maximum Subarray
    Given an integer array nums, find the subarray with the largest sum, and return its sum.

    Example 1:

    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: The subarray [4,-1,2,1] has the largest sum 6.
    Example 2:

    Input: nums = [1]
    Output: 1
    Explanation: The subarray [1] has the largest sum 1.
    Example 3:

    Input: nums = [5,4,-1,7,8]
    Output: 23
    Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

    Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    
    Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Brute Force
    // int maxSubArray(vector<int>& nums) {
    //     int max_sum = nums[0];
    //     int n = nums.size();
    //     for(int i = 0; i < n; i++){
    //         int sum = 0;
    //         for (int j = i; j < n; j++) {
    //             sum += nums[j];
    //             max_sum = max(max_sum, sum);
    //         }
    //     }
    //     return max_sum;
    // }

    // Optimal Solution : Kadane's Algorithm
    int maxSubArray(vector<int>& nums) {
        int max_curr = nums[0];
        int max_global = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            max_curr = max(nums[i], max_curr + nums[i]);
            max_global = max(max_global, max_curr);
        }
        return max_global;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    Solution sol;
    cout << sol.maxSubArray(nums) << '\n';

    return 0;
}
