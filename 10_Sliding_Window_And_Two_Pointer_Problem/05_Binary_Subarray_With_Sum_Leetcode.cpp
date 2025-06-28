/*
    930. Binary Subarrays With Sum
    Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

    A subarray is a contiguous part of the array.

    Example 1:

    Input: nums = [1,0,1,0,1], goal = 2
    Output: 4
    Explanation: The 4 subarrays are bolded and underlined below:
    [1,0,1,0,1]
    [1,0,1,0,1]
    [1,0,1,0,1]
    [1,0,1,0,1]
    Example 2:

    Input: nums = [0,0,0,0,0], goal = 0
    Output: 15
    
    Constraints:

    1 <= nums.length <= 3 * 104
    nums[i] is either 0 or 1.
    0 <= goal <= nums.length
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // int numSubarraysWithSum(vector<int>& nums, int goal) {
    //     unordered_map<int, int> prefixCount;
    //     prefixCount[0] = 1;  // base case: sum 0 seen once

    //     int sum = 0, count = 0;
    //     for (int num : nums) {
    //         sum += num;

    //         if (prefixCount.find(sum - goal) != prefixCount.end()) {
    //             count += prefixCount[sum - goal];
    //         }

    //         prefixCount[sum]++;
    //     }

    //     return count;
    // }

    // Helper to count subarrays with sum at most S
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // no subarray can have sum < 0 in binary array

        int left = 0, sum = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
    // Main function to get subarrays with sum exactly equal to goal
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    cout << "Test Case 1:\nInput: [1,0,1,0,1], goal = 2\n";
    cout << "Output: " << sol.numSubarraysWithSum(nums1, goal1) << "\n\n"; // Expected: 4

    vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    cout << "Test Case 2:\nInput: [0,0,0,0,0], goal = 0\n";
    cout << "Output: " << sol.numSubarraysWithSum(nums2, goal2) << "\n"; // Expected: 15

    return 0;
}