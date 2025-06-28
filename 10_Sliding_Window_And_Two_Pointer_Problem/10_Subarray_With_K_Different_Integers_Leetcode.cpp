/*
    992. Subarrays with K Different Integers
    Given an integer array nums and an integer k, return the number of good subarrays of nums.
    A good array is an array where the number of different integers in that array is exactly k.
    For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
    A subarray is a contiguous part of an array.
    
    Example 1:
    Input: nums = [1,2,1,2,3], k = 2
    Output: 7
    Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
    
    Example 2:
    Input: nums = [1,2,1,3,4], k = 3
    Output: 3
    Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
    
    Constraints:

    1 <= nums.length <= 2 * 104
    1 <= nums[i], k <= nums.length
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // int subarraysWithKDistinct(vector<int>& nums, int k) {
    //     int count = 0;
    //     int n = nums.size();
    //     for (int i = 0; i < n; ++i) {
    //         unordered_map<int, int> freq;
    //         for (int j = i; j < n; ++j) {
    //             freq[nums[j]]++;
    //             if (freq.size() == k)
    //                 count++;
    //             else if (freq.size() > k)
    //                 break; // No need to check further, will only increase distincts
    //         }
    //     }
    //     return count;
    // }

    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, res = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (freq[nums[right]]++ == 0) {
                k--; // New unique number
            }
            while (k < 0) {
                if (--freq[nums[left]] == 0) {
                    k++; // Remove unique number
                }
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    cout << "Input: [1,2,1,2,3], k = 2 => Output: " << sol.subarraysWithKDistinct(nums1, k1) << "\n"; // Expected: 7

    vector<int> nums2 = {1, 2, 1, 3, 4};
    int k2 = 3;
    cout << "Input: [1,2,1,3,4], k = 3 => Output: " << sol.subarraysWithKDistinct(nums2, k2) << "\n"; // Expected: 3

    return 0;
}