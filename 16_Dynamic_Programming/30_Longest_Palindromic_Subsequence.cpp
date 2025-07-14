/*
    516. Longest Palindromic Subsequence

    Given a string s, find the longest palindromic subsequence's length in s.

    A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

    Example 1:
    Input: s = "bbbab"
    Output: 4
    Explanation: One possible longest palindromic subsequence is "bbbb".

    Example 2:
    Input: s = "cbbd"
    Output: 2
    Explanation: One possible longest palindromic subsequence is "bb".
    
    Constraints:

    1 <= s.length <= 1000
    s consists only of lowercase English letters.
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 1. Memoization
    int lpsMemo(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = 2 + lpsMemo(i + 1, j - 1, s, dp);
        else
            return dp[i][j] = max(lpsMemo(i + 1, j, s, dp), lpsMemo(i, j - 1, s, dp));
    }

    int longestPalindromeSubseqMemo(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return lpsMemo(0, n - 1, s, dp);
    }

    // 2. Tabulation
    int longestPalindromeSubseqTab(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }

    // 3. Space Optimized (Using 2 rows)
    int longestPalindromeSubseqSpaceOpt(string s) {
        int n = s.size();
        vector<int> prev(n, 0), curr(n, 0);

        for (int i = n - 1; i >= 0; --i) {
            curr[i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j])
                    curr[j] = 2 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[n - 1];
    }

    // Caller
    int longestPalindromeSubseq(string s) {
        // return longestPalindromeSubseqMemo(s);
        // return longestPalindromeSubseqTab(s);
        return longestPalindromeSubseqSpaceOpt(s);
    }
};
int main() {
    Solution sol;

    string s1 = "bbbab";
    cout << "LPS Length: " << sol.longestPalindromeSubseq(s1) << endl;

    string s2 = "cbbd";
    cout << "LPS Length: " << sol.longestPalindromeSubseq(s2) << endl;

    return 0;
}

// | Approach            | Time Complexity| Space Complexity         | Notes                                                                   |
// | ------------------- | ---------------| -------------------------| ----------------------------------------------------------------------- |
// | **Memoization**     | O(N × N)       | O(N × N) + O(N) recursion| `dp[i][j]` stores result for `s[i...j]`; recursion stack can go up to N |
// | **Tabulation**      | O(N × N)       | O(N × N)                 | Iterative bottom-up DP table; no recursion                              |
// | **Space Optimized** | O(N × N)       | O(N)                     | Uses 2 rows (`prev`, `curr`) instead of full `N × N` DP table           |