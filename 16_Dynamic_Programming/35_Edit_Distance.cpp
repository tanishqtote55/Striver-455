/*
    72. Edit Distance

    Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

    You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character
    
    Example 1:
    Input: word1 = "horse", word2 = "ros"
    Output: 3
    Explanation: 
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')

    Example 2:
    Input: word1 = "intention", word2 = "execution"
    Output: 5
    Explanation: 
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')
    
    Constraints:

    0 <= word1.length, word2.length <= 500
    word1 and word2 consist of lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 1. Memoization
    int memoHelper(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = memoHelper(i - 1, j - 1, s, t, dp);

        int insert = 1 + memoHelper(i, j - 1, s, t, dp);
        int del = 1 + memoHelper(i - 1, j, s, t, dp);
        int replace = 1 + memoHelper(i - 1, j - 1, s, t, dp);

        return dp[i][j] = min(min(insert, del), replace);
    }

    int minDistanceMemo(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memoHelper(n - 1, m - 1, word1, word2, dp);
    }

    // 2. Tabulation
    int minDistanceTab(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= m; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
            }
        }

        return dp[n][m];
    }

    // 3. Space Optimized (2 Rows)
    int minDistanceSpaceOptimized(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; ++j)
            prev[j] = j;

        for (int i = 1; i <= n; ++i) {
            curr[0] = i;
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = 1 + min(min(curr[j - 1], prev[j]), prev[j - 1]);
            }
            prev = curr;
        }

        return prev[m];
    }
};

int main() {
    Solution sol;

    string w1 = "horse", w2 = "ros";
    cout << "Memoization: " << sol.minDistanceMemo(w1, w2) << endl;
    cout << "Tabulation: " << sol.minDistanceTab(w1, w2) << endl;
    cout << "Space Optimized: " << sol.minDistanceSpaceOptimized(w1, w2) << endl;

    w1 = "intention", w2 = "execution";
    cout << "\nMemoization: " << sol.minDistanceMemo(w1, w2) << endl;
    cout << "Tabulation: " << sol.minDistanceTab(w1, w2) << endl;
    cout << "Space Optimized: " << sol.minDistanceSpaceOptimized(w1, w2) << endl;

    return 0;
}

// | Approach        | Time Complexity | Space Complexity        |
// | --------------- | --------------- | ----------------------- |
// | Memoization     | O(n × m)        | O(n × m) + O(n+m) stack |
// | Tabulation      | O(n × m)        | O(n × m)                |
// | Space Optimized | O(n × m)        | O(m)                    |