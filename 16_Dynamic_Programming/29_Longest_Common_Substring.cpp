/*
    Longest common substring

    Given two strings str1 and str2, find the length of their longest common substring.
    A substring is a contiguous sequence of characters within a string.

    Examples:
    Input: str1 = "abcde", str2 = "abfce"
    Output: 2
    Explanation: The longest common substring is "ab", which has a length of 2.

    Input: str1 = "abcdxyz", str2 = "xyzabcd"
    Output: 4
    Explanation: The longest common substring is "abcd", which has a length of 4.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 1. Tabulation (Bottom-Up)
    int longestCommonSubstrTab(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxLen = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxLen = max(maxLen, dp[i][j]);
                } else {
                    dp[i][j] = 0; // must reset on mismatch
                }
            }
        }

        return maxLen;
    }

    // 2. Space Optimized
    int longestCommonSubstrSpaceOpt(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        int maxLen = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    maxLen = max(maxLen, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }

        return maxLen;
    }

    // Caller
    int longestCommonSubstr(string str1, string str2) {
        // return longestCommonSubstrTab(str1, str2);
        return longestCommonSubstrSpaceOpt(str1, str2);
    }
};

int main() {
    Solution sol;
    string str1 = "abcdxyz";
    string str2 = "xyzabcd";

    cout << "Longest Common Substring Length: " << sol.longestCommonSubstr(str1, str2) << endl;

    return 0;
}

// | Method          | Time Complexity | Space Complexity |
// | --------------- | --------------- | ---------------- |
// | Tabulation      | O(N × M)        | O(N × M)         |
// | Space Optimized | O(N × M)        | O(M)             |