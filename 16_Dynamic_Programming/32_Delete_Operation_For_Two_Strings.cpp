/*
    583. Delete Operation for Two Strings

    Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

    In one step, you can delete exactly one character in either string.

    Example 1:
    Input: word1 = "sea", word2 = "eat"
    Output: 2
    Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

    Example 2:
    Input: word1 = "leetcode", word2 = "etco"
    Output: 4
    
    Constraints:
    1 <= word1.length, word2.length <= 500
    word1 and word2 consist of only lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int computeLCS(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int lcsLen = computeLCS(word1, word2);
        return (word1.length() - lcsLen) + (word2.length() - lcsLen);
    }
};

int main() {
    Solution sol;

    string word1 = "sea", word2 = "eat";
    cout << "Minimum deletions to make strings equal: " << sol.minDistance(word1, word2) << endl;  // Output: 2

    word1 = "leetcode", word2 = "etco";
    cout << "Minimum deletions to make strings equal: " << sol.minDistance(word1, word2) << endl;  // Output: 4

    return 0;
}

// | Operation | Complexity | Explanation                                    |
// | --------- | ---------- | ---------------------------------------------- |
// | **Time**  | O(N × M)   | `N = word1.length()`, `M = word2.length()`     |
// | **Space** | O(N × M)   | 2D DP array `dp[n+1][m+1]` for LCS computation |