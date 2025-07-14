/*
    Print Longest Increasing Subsequence

    Given an array of n integers arr, return the Longest Increasing Subsequence (LIS) that is Index-wise Lexicographically Smallest.

    The Longest Increasing Subsequence (LIS) is the longest subsequence where all elements are in strictly increasing order.

    A subsequence A1 is Index-wise Lexicographically Smaller than another subsequence A2 if, at the first position where A1 and A2 differ, the element in A1 appears earlier in the array arr than corresponding element in S2.

    Your task is to return the LIS that is Index-wise Lexicographically Smallest from the given array.

    Examples:
    Input: arr = [10, 22, 9, 33, 21, 50, 41, 60, 80]
    Output: [10, 22, 33, 50, 60, 80]
    Explanation: The LIS is [10, 22, 33, 50, 60, 80] and it is the lexicographically smallest.

    Input: arr = [1, 3, 2, 4, 6, 5]
    Output: [1, 3, 4, 6]
    Explanation: Possible LIS sequences are [1, 3, 4, 6] and [1, 2, 4, 6]. Since [1, 3, 4, 6] is Index-wise Lexicographically Smaller, it is the result.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Tabulation + Reconstruction
    vector<int> longestIncreasingSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), prevIndex(n, -1);

        int maxLen = 1, lastIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prevIndex[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the LIS path
        vector<int> lis;
        while (lastIndex != -1) {
            lis.push_back(nums[lastIndex]);
            lastIndex = prevIndex[lastIndex];
        }
        reverse(lis.begin(), lis.end());
        return lis;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> result = sol.longestIncreasingSubsequence(arr);

    cout << "Longest Increasing Subsequence: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}

// | Measure          | Value |
// | ---------------- | ----- |
// | Time Complexity  | O(n²) |
// | Space Complexity | O(n)  |