/*
    132. Palindrome Partitioning II

    Given a string s, partition s such that every substring of the partition is a palindrome.

    Return the minimum cuts needed for a palindrome partitioning of s.

    Example 1:
    Input: s = "aab"
    Output: 1
    Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

    Example 2:
    Input: s = "a"
    Output: 0

    Example 3:
    Input: s = "ab"
    Output: 1
    
    Constraints:

    1 <= s.length <= 2000
    s consists of lowercase English letters only.
*/
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<bool>> isPal;

    void computePalindromeTable(const string& s) {
        isPal.assign(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i)
            isPal[i][i] = true;

        for (int i = 0; i < n - 1; ++i)
            isPal[i][i + 1] = (s[i] == s[i + 1]);

        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                isPal[i][j] = (s[i] == s[j]) && isPal[i + 1][j - 1];
            }
        }
    }

public:
    // Memoization
    int solveMemo(int i, const string& s, vector<int>& dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int minCuts = INT_MAX;
        for (int j = i; j < n; ++j) {
            if (isPal[i][j]) {
                int cuts = 1 + solveMemo(j + 1, s, dp);
                minCuts = min(minCuts, cuts);
            }
        }
        return dp[i] = minCuts;
    }

    // Tabulation
    int solveTab(const string& s) {
        vector<int> dp(n + 1, 0); // dp[i] = min cuts for s[i:]
        dp[n] = 0;

        for (int i = n - 1; i >= 0; --i) {
            int minCuts = INT_MAX;
            for (int j = i; j < n; ++j) {
                if (isPal[i][j]) {
                    int cuts = 1 + dp[j + 1];
                    minCuts = min(minCuts, cuts);
                }
            }
            dp[i] = minCuts;
        }

        return dp[0] - 1; // one less cut because no cut needed at end
    }

    int minCut(string s) {
        n = s.size();
        computePalindromeTable(s);

        // --- Uncomment either of the two approaches: ---

        // // 1. Memoization
        // vector<int> dp(n, -1);
        // return solveMemo(0, s, dp) - 1;

        // 2. Tabulation
        return solveTab(s);
    }
};

int main() {
    Solution sol;

    string s1 = "aab";
    cout << "Minimum cuts for \"" << s1 << "\": " << sol.minCut(s1) << endl;

    string s2 = "a";
    cout << "Minimum cuts for \"" << s2 << "\": " << sol.minCut(s2) << endl;

    string s3 = "ab";
    cout << "Minimum cuts for \"" << s3 << "\": " << sol.minCut(s3) << endl;

    string s4 = "banana";
    cout << "Minimum cuts for \"" << s4 << "\": " << sol.minCut(s4) << endl;

    return 0;
}

// | Approach    | Time Complexity | Space Complexity |
// | ----------- | --------------- | ---------------- |
// | Memoization | O(N²)           | O(N²)            |
// | Tabulation  | O(N²)           | O(N²)            |