/*
Problem Statement
Given a string s, count how many distinct palindromic subsequences it contains.

There are two variations:

Count all palindromic subsequences (including duplicates)

Count distinct palindromic subsequences

Here, I’ll start with the simpler version: counting all (non-distinct) palindromic subsequences, using DP.
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        const int MOD = 1e9 + 7;

        // Base case: single letters
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        // Build the table
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
                } else {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main() {
    Solution sol;

    string s1 = "abcb";
    cout << "Input: " << s1 << " => Palindromic Subsequences: " << sol.countPalindromicSubsequences(s1) << endl;

    string s2 = "aaa";
    cout << "Input: " << s2 << " => Palindromic Subsequences: " << sol.countPalindromicSubsequences(s2) << endl;

    string s3 = "abcd";
    cout << "Input: " << s3 << " => Palindromic Subsequences: " << sol.countPalindromicSubsequences(s3) << endl;

    return 0;
}


// Time Complexity:
// O(n²) time and space