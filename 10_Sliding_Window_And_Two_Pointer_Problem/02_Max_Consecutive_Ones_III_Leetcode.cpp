/*
    1004. Max Consecutive Ones III
    Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

    Example 1:

    Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
    Output: 6
    Explanation: [1,1,1,0,0,1,1,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
    Example 2:

    Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
    Output: 10
    Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

    Constraints:

    1 <= nums.length <= 105
    nums[i] is either 0 or 1.
    0 <= k <= nums.length
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // int longestOnes(vector<int>& nums, int k) {
    //     int maxLen = 0;
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++) {
    //         int zeros = 0;
    //         for (int j = i; j < n; j++) {
    //             if (nums[j] == 0) zeros++;
    //             if (zeros > k)
    //                 break;
    //             maxLen = max(maxLen, j - i + 1);
    //         }
    //     }
    //     return maxLen;
    // }

    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxLen = 0;
        int zeros = 0;

        while (right < nums.size()) {
            if (nums[right] == 0)
                zeros++;

            while (zeros > k) {
                if (nums[left] == 0)
                    zeros--;
                left++;  // shrink the window
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }

    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxLen = 0;
        int zeros = 0;

        while (right < nums.size()) {
            if (nums[right] == 0)
                zeros++;

            if(zeros > k){
                if(nums[left] == 0) zeros--;
                left++;
            }
            if(zeros <= k){
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    int k1 = 2;
    cout << "Test Case 1:\nInput: nums = {1,1,1,0,0,0,1,1,1,1,0}, k = 2\n";
    cout << "Output: " << sol.longestOnes(nums1, k1) << "\n\n"; // Expected: 6

    vector<int> nums2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k2 = 3;
    cout << "Test Case 2:\nInput: nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, k = 3\n";
    cout << "Output: " << sol.longestOnes(nums2, k2) << "\n"; // Expected: 10

    return 0;
}
