/*
    1312. Minimum Insertion Steps to Make a String Palindrome
    
    Given a string s. In one step you can insert any character at any index of the string.

    Return the minimum number of steps to make s palindrome.

    A Palindrome String is one that reads the same backward as well as forward.

    Example 1:
    Input: s = "zzazz"
    Output: 0
    Explanation: The string "zzazz" is already palindrome we do not need any insertions.

    Example 2:
    Input: s = "mbadm"
    Output: 2
    Explanation: String can be "mbdadbm" or "mdbabdm".

    Example 3:
    Input: s = "leetcode"
    Output: 5
    Explanation: Inserting 5 characters the string becomes "leetcodocteel".
    
    Constraints:

    1 <= s.length <= 500
    s consists of lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper to compute Longest Palindromic Subsequence
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == rev[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }

    int minInsertions(string s) {
        int n = s.size();
        int lps = longestPalindromeSubseq(s);
        return n - lps;
    }
};
int main() {
    Solution sol;
    cout << sol.minInsertions("zzazz") << endl;     // Output: 0
    cout << sol.minInsertions("mbadm") << endl;     // Output: 2
    cout << sol.minInsertions("leetcode") << endl;  // Output: 5
    return 0;
}

// | Operation                     | Complexity |
// | ----------------------------- | ---------- |
// | LPS (via LCS on reversed `s`) | O(n²)      |
// | Space                         | O(n²)      |
