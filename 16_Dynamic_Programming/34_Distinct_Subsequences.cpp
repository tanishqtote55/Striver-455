/*
    115. Distinct Subsequences

    Given two strings s and t, return the number of distinct subsequences of s which equals t.
    The test cases are generated so that the answer fits on a 32-bit signed integer.

    Example 1:
    Input: s = "rabbbit", t = "rabbit"
    Output: 3
    Explanation:
    As shown below, there are 3 ways you can generate "rabbit" from s.
    rabbbit
    rabbbit
    rabbbit

    Example 2:
    Input: s = "babgbag", t = "bag"
    Output: 5
    Explanation:
    As shown below, there are 5 ways you can generate "bag" from s.
    babgbag
    babgbag
    babgbag
    babgbag
    babgbag
    
    Constraints:
    1 <= s.length, t.length <= 1000
    s and t consist of English letters.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int f(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        // Base cases
        if (j < 0) return 1;        // We matched all of t
        if (i < 0) return 0;        // s is exhausted before t

        if (dp[i][j] != -1) return dp[i][j];

        int take = 0;
        if (s[i] == t[j]) {
            take = f(i - 1, j - 1, s, t, dp); // match both characters
        }

        int notTake = f(i - 1, j, s, t, dp);   // skip s[i]

        return dp[i][j] = take + notTake;
    }

    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, t, dp);
    }

    // Tabulation 
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        // Empty t is a subsequence of any prefix of s
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return (int)dp[n][m];
    }
    
    // Space Optimized
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double> prev(m + 1, 0);
        prev[0] = 1; // Empty t is subsequence of any prefix of s

        for (int i = 1; i <= n; ++i) {
            vector<double> curr(m + 1, 0);
            curr[0] = 1;
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1])
                    curr[j] = prev[j - 1] + prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }

        return (int)prev[m];
    }
};

int main() {
    Solution sol;

    string s1 = "rabbbit", t1 = "rabbit";
    cout << sol.numDistinct(s1, t1) << endl;  // Output: 3

    string s2 = "babgbag", t2 = "bag";
    cout << sol.numDistinct(s2, t2) << endl;  // Output: 5

    return 0;
}