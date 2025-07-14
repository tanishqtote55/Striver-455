/*
    44. Wildcard Matching

    Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
    The matching should cover the entire input string (not partial).

    Example 1:
    Input: s = "aa", p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".

    Example 2:
    Input: s = "aa", p = "*"
    Output: true
    Explanation: '*' matches any sequence.

    Example 3:
    Input: s = "cb", p = "?a"
    Output: false
    Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
    
    Constraints:

    0 <= s.length, p.length <= 2000
    s contains only lowercase English letters.
    p contains only lowercase English letters, '?' or '*'.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 1. Memoization
    bool f(int i, int j, string &s, string &p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) return true;
        if (j < 0 && i >= 0) return false;
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; ++k) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        else if (p[j] == '*')
            return dp[i][j] = f(i - 1, j, s, p, dp) || f(i, j - 1, s, p, dp);

        return dp[i][j] = false;
    }

    bool isMatchMemo(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, p, dp);
    }

    // 2. Tabulation
    bool isMatchTab(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int j = 1; j <= m; ++j)
            dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';

        for (int i = 1; i <= n; ++i)
            dp[i][0] = false;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }

    // 3. Space Optimized
    bool isMatchSpaceOptimized(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);

        prev[0] = true;
        for (int j = 1; j <= m; ++j)
            prev[j] = prev[j - 1] && p[j - 1] == '*';

        for (int i = 1; i <= n; ++i) {
            curr[0] = false;
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else if (p[j - 1] == '*')
                    curr[j] = prev[j] || curr[j - 1];
                else
                    curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
};
int main() {
    Solution sol;

    string s1 = "aa", p1 = "a";
    cout << "Memo: " << sol.isMatchMemo(s1, p1) << endl;
    cout << "Tabulation: " << sol.isMatchTab(s1, p1) << endl;
    cout << "Space Optimized: " << sol.isMatchSpaceOptimized(s1, p1) << endl;

    string s2 = "aa", p2 = "*";
    cout << "\nMemo: " << sol.isMatchMemo(s2, p2) << endl;
    cout << "Tabulation: " << sol.isMatchTab(s2, p2) << endl;
    cout << "Space Optimized: " << sol.isMatchSpaceOptimized(s2, p2) << endl;

    return 0;
}
// | Approach        | Time Complexity | Space Complexity           |
// | --------------- | --------------- | -------------------------- |
// | Memoization     | O(n × m)        | O(n × m) + recursion stack |
// | Tabulation      | O(n × m)        | O(n × m)                   |
// | Space Optimized | O(n × m)        | O(m)                       |