/*
    Longest subarray with sum K
    Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

    Examples:
    Input: nums = [10, 5, 2, 7, 1, 9],  k=15

    Output: 4

    Explanation: The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

    Input: nums = [-3, 2, 1], k=6

    Output: 0

    Explanation: There is no sub-array in the array that sums to 6. Therefore, the output is 0.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    // int longestSubarray(vector<int> &nums, int k){
    //     int max_count = 0;
        
    //     for(int i = 0; i < nums.size(); i++){
    //         int sum = 0;
    //         int count = 0;
    //         for(int j = i; j < nums.size(); j++){
    //             sum += nums[j];
    //             count++;
    //             if(sum == k){
    //                 max_count = max(max_count, count);
    //                 break;
    //             }
    //         }
    //     }
    //     return max_count;
    // }

    // Using 2 Pointers
    int longestSubarray(vector<int> &nums, int k){
        int max_count = 0;
        int left = 0;
        int sum = 0;

        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];
           
            // If sum > k, move left forward to reduce sum
            while(sum > k && left <= right) {
                sum -= nums[left];
                left++;
            }
           
            if(sum == k) { // If we find exactly k, update max_count
                max_count = max(max_count, right - left + 1);
            }
        }
        
        return max_count;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    Solution sol;
    cout << sol.longestSubarray(nums, k) << '\n';

    return 0;
}