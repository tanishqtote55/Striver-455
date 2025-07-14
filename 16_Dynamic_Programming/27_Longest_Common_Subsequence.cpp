/*
    1143. Longest Common Subsequence

    Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".
    A common subsequence of two strings is a subsequence that is common to both strings.

    Example 1:
    Input: text1 = "abcde", text2 = "ace" 
    Output: 3  
    Explanation: The longest common subsequence is "ace" and its length is 3.

    Example 2:
    Input: text1 = "abc", text2 = "abc"
    Output: 3
    Explanation: The longest common subsequence is "abc" and its length is 3.

    Example 3:
    Input: text1 = "abc", text2 = "def"
    Output: 0
    Explanation: There is no such common subsequence, so the result is 0.
    
    Constraints:

    1 <= text1.length, text2.length <= 1000
    text1 and text2 consist of only lowercase English characters.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 1. Memoization (Top-down)
    int lcsMemo(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + lcsMemo(i - 1, j - 1, s1, s2, dp);
        else
            return dp[i][j] = max(lcsMemo(i - 1, j, s1, s2, dp), lcsMemo(i, j - 1, s1, s2, dp));
    }

    int longestCommonSubsequenceMemo(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return lcsMemo(n - 1, m - 1, text1, text2, dp);
    }

    // 2. Tabulation (Bottom-up)
    int longestCommonSubsequenceTab(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }

    // 3. Space Optimized (2-row)
    int longestCommonSubsequenceSpaceOpt(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[m];
    }

    // Unified caller
    int longestCommonSubsequence(string text1, string text2) {
        // return longestCommonSubsequenceMemo(text1, text2);
        // return longestCommonSubsequenceTab(text1, text2);
        return longestCommonSubsequenceSpaceOpt(text1, text2);
    }
};

int main() {
    
    Solution sol;

    string text1 = "abcde";
    string text2 = "ace";

    cout << "LCS Length: " << sol.longestCommonSubsequence(text1, text2) << endl;

    return 0;
}

// | Method          | Time     | Space            |
// | --------------- | -------- | ---------------- |
// | Memoization     | O(n × m) | O(n × m) + stack |
// | Tabulation      | O(n × m) | O(n × m)         |
// | Space Optimized | O(n × m) | O(m)             |