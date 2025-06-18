/*
    410. Split Array Largest Sum
    Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

    Return the minimized largest sum of the split.

    A subarray is a contiguous part of the array.

    

    Example 1:

    Input: nums = [7,2,5,10,8], k = 2
    Output: 18
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
    Example 2:

    Input: nums = [1,2,3,4,5], k = 2
    Output: 9
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
    

    Constraints:

    1 <= nums.length <= 1000
    0 <= nums[i] <= 106
    1 <= k <= min(50, nums.length)
*/

#include <iostream>
#include <vector>
#include <algorithm>    
#include <numeric>      
using namespace std;

class Solution {
public:
    // Helper function to count how many subarrays are needed with max sum <= maxSum
    int countSubarrays(vector<int>& nums, int maxSum) {
        int count = 1;
        long long currentSum = 0;

        for (int num : nums) {
            if (currentSum + num > maxSum) {
                count++;
                currentSum = num;
            } else {
                currentSum += num;
            }
        }

        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end()); // At least one subarray must hold the max element
        int right = accumulate(nums.begin(), nums.end(), 0); // At most all elements in one subarray

        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int subarrays = countSubarrays(nums, mid);

            if (subarrays <= k) {
                ans = mid;         // Try for a better (smaller) max sum
                right = mid - 1;
            } else {
                left = mid + 1;    // Too many subarrays, increase the allowed sum
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {7, 2, 5, 10, 8};
    int k1 = 2;
    cout << "Minimum largest sum (Test Case 1): " << sol.splitArray(nums1, k1) << endl;

    // Test Case 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;
    cout << "Minimum largest sum (Test Case 2): " << sol.splitArray(nums2, k2) << endl;

    return 0;
}