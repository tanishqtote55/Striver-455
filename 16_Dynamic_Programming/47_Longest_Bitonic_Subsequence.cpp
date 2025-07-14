/*
    Longest Bitonic Subsequence

    Given an array arr of n integers, the task is to find the length of the longest bitonic sequence. A sequence is considered bitonic if it first increases, then decreases. The sequence does not have to be contiguous.

    Examples:
    Input: arr = [5, 1, 4, 2, 3, 6, 8, 7]
    Output: 6
    Explanation: The longest bitonic sequence is [1, 2, 3, 6, 8, 7] with length 6.

    Input: arr = [10, 20, 30, 40, 50, 40, 30, 20]
    Output: 8
    Explanation: The entire array is bitonic, increasing up to 50 and then decreasing.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(vector<int> arr) {
        int n = arr.size();
        vector<int> LIS(n, 1), LDS(n, 1);

        // Step 1: Longest Increasing Subsequence (LIS)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // Step 2: Longest Decreasing Subsequence (LDS)
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (arr[j] < arr[i]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        // Step 3: Combine LIS and LDS
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            maxLen = max(maxLen, LIS[i] + LDS[i] - 1);
        }

        return maxLen;
    }
};

int main() {

    Solution sol;

    vector<int> arr1 = {5, 1, 4, 2, 3, 6, 8, 7};
    cout << "Longest Bitonic Subsequence Length: " << sol.LongestBitonicSequence(arr1) << endl;

    vector<int> arr2 = {10, 20, 30, 40, 50, 40, 30, 20};
    cout << "Longest Bitonic Subsequence Length: " << sol.LongestBitonicSequence(arr2) << endl;

    return 0;
}

// | Metric           | Value |
// | ---------------- | ----- |
// | Time Complexity  | O(N²) |
// | Space Complexity | O(N)  |