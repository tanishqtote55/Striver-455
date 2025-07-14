/*
    1092. Shortest Common Supersequence 

    Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

    A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

    Example 1:
    Input: str1 = "abac", str2 = "cab"
    Output: "cabac"
    Explanation: 
    str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
    str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
    The answer provided is the shortest such string that satisfies these properties.

    Example 2:
    Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
    Output: "aaaaaaaa"
    
    Constraints:

    1 <= str1.length, str2.length <= 1000
    str1 and str2 consist of lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Helper to compute the LCS table
    vector<vector<int>> computeLCS(string& s1, string& s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int i = str1.length(), j = str2.length();
        vector<vector<int>> dp = computeLCS(str1, str2);

        // Reconstruct the SCS using LCS table
        string res;
        int x = i, y = j;
        while (x > 0 && y > 0) {
            if (str1[x - 1] == str2[y - 1]) {
                res.push_back(str1[x - 1]);
                --x;
                --y;
            } else if (dp[x - 1][y] > dp[x][y - 1]) {
                res.push_back(str1[x - 1]);
                --x;
            } else {
                res.push_back(str2[y - 1]);
                --y;
            }
        }

        while (x > 0) res.push_back(str1[--x]);
        while (y > 0) res.push_back(str2[--y]);

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;

    string str1 = "abac", str2 = "cab";
    cout << "Shortest Common Supersequence: " << sol.shortestCommonSupersequence(str1, str2) << endl;

    str1 = "aaaaaaaa";
    str2 = "aaaaaaaa";
    cout << "Shortest Common Supersequence: " << sol.shortestCommonSupersequence(str1, str2) << endl;

    return 0;
}

// | Metric | Complexity |
// | ------ | ---------- |
// | Time   | O(N × M)   |
// | Space  | O(N × M)   |