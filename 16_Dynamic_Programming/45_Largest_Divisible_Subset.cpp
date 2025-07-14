/*
    368. Largest Divisible Subset

    Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0
    If there are multiple solutions, return any of them.

    Example 1:
    Input: nums = [1,2,3]
    Output: [1,2]
    Explanation: [1,3] is also accepted.

    Example 2:
    Input: nums = [1,2,4,8]
    Output: [1,2,4,8]
    
    Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i] <= 2 * 109
    All the integers in nums are unique.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Tabulation + Path Reconstruction
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), prev(n, -1);

        int maxLen = 1;
        int lastIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        vector<int> result;
        while (lastIndex != -1) {
            result.push_back(nums[lastIndex]);
            lastIndex = prev[lastIndex];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 2, 3};
    vector<int> res1 = sol.largestDivisibleSubset(nums1);
    cout << "Subset for [1, 2, 3]: ";
    for (int num : res1) cout << num << " ";
    cout << endl;

    vector<int> nums2 = {1, 2, 4, 8};
    vector<int> res2 = sol.largestDivisibleSubset(nums2);
    cout << "Subset for [1, 2, 4, 8]: ";
    for (int num : res2) cout << num << " ";
    cout << endl;

    return 0;
}

// | Metric           | Value                           |
// | ---------------- | ------------------------------- |
// | Time Complexity  | O(n²)                           |
// | Space Complexity | O(n) for `dp`, `prev`, `result` |