 #include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 1. Memoization (Top-down)
    string lcsMemoHelper(int i, int j, string& s1, string& s2, vector<vector<int>>& dp, vector<vector<string>>& path) {
        if (i < 0 || j < 0) return "";

        if (dp[i][j] != -1) return path[i][j];

        if (s1[i] == s2[j]) {
            path[i][j] = lcsMemoHelper(i - 1, j - 1, s1, s2, dp, path) + s1[i];
        } else {
            string left = lcsMemoHelper(i - 1, j, s1, s2, dp, path);
            string up = lcsMemoHelper(i, j - 1, s1, s2, dp, path);
            path[i][j] = (left.length() > up.length()) ? left : up;
        }

        dp[i][j] = path[i][j].length();
        return path[i][j];
    }

    string longestCommonSubsequenceMemo(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        vector<vector<string>> path(n, vector<string>(m, ""));
        return lcsMemoHelper(n - 1, m - 1, text1, text2, dp, path);
    }

    // 2. Tabulation (Bottom-up)
    string longestCommonSubsequenceTab(string text1, string text2) {
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

        // Build the string
        string lcs = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                lcs += text1[i - 1];
                --i; --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                --i;
            } else {
                --j;
            }
        }

        reverse(lcs.begin(), lcs.end());
        return lcs;
    }

    // 3. Space Optimized (Only Length + LCS Backtrack)
    string longestCommonSubsequenceSpaceOpt(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        // Reconstruct LCS (same as tabulation)
        string lcs = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                lcs += text1[i - 1];
                --i; --j;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                --i;
            } else {
                --j;
            }
        }

        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};

int main() {

    Solution sol;

    string text1 = "abcde";
    string text2 = "ace";

    cout << "Memoization LCS: " << sol.longestCommonSubsequenceMemo(text1, text2) << endl;
    cout << "Tabulation LCS: " << sol.longestCommonSubsequenceTab(text1, text2) << endl;
    cout << "Space Optimized LCS: " << sol.longestCommonSubsequenceSpaceOpt(text1, text2) << endl;

    return 0;
}
// | Approach            | Time Complexity | Space Complexity                                                   | Notes
// | ------------------- | --------------- | ------------------------------------------------------------------ | ------
// | **Memoization**     | `O(N × M)`      | `O(N × M)` + recursion stack                                       | Uses a 2D `dp` table and recursion call stack; extra `path[][]` for LCS string     |
// | **Tabulation**      | `O(N × M)`      | `O(N × M)`                                                         | Uses a 2D `dp` table and backtracking for building the LCS                         |
// | **Space Optimized** | `O(N × M)`      | `O(N × M)` (for string reconstruction)<br>or `O(M)` if only length | Though DP computation is space-optimized using 2 rows, full table is needed to reconstruct the LCS string |