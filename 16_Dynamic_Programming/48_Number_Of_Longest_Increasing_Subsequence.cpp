/*
    673. Number of Longest Increasing Subsequence

    Given an integer array nums, return the number of longest increasing subsequences.

    Notice that the sequence has to be strictly increasing.

    Example 1:
    Input: nums = [1,3,5,4,7]
    Output: 2
    Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

    Example 2:
    Input: nums = [2,2,2,2,2]
    Output: 5
    Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
    
    Constraints:

    1 <= nums.length <= 2000
    -106 <= nums[i] <= 106
    The answer is guaranteed to fit inside a 32-bit integer.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> length(n, 1);  // Length of LIS ending at i
        vector<int> count(n, 1);   // Number of LIS ending at i

        int maxLen = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = count[j];
                    } else if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen, length[i]);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (length[i] == maxLen) {
                result += count[i];
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3, 5, 4, 7};
    cout << "Number of LIS: " << sol.findNumberOfLIS(nums1) << endl;  // Output: 2

    vector<int> nums2 = {2, 2, 2, 2, 2};
    cout << "Number of LIS: " << sol.findNumberOfLIS(nums2) << endl;  // Output: 5

    return 0;
}

// | Metric           | Value |
// | ---------------- | ----- |
// | Time Complexity  | O(N²) |
// | Space Complexity | O(N)  |