/*
    Minimum insertions or deletions to convert string A to B

    Given two strings str1 and str2, find the minimum number of insertions and deletions in string str1 required to transform str1 into str2.
    Insertion and deletion of characters can take place at any position in the string.

    Examples:
    Input: str1 = "kitten", str2 = "sitting"
    Output: 5
    Explanation: To transform "kitten" to "sitting", delete "k" and insert "s" to get "sitten", then insert "i" to get "sittin", and insert "g" at the end to get "sitting".

    Input: str1 = "flaw", str2 = "lawn"
    Output: 2
    Explanation: To transform "flaw" to "lawn", delete "f" and insert "n" at the end. Hence minimum number of operations required is 2".
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Helper to compute LCS
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

    int minOperations(string str1, string str2) {
        int lcsLen = computeLCS(str1, str2);
        int deletions = str1.length() - lcsLen;
        int insertions = str2.length() - lcsLen;
        return deletions + insertions;
    }
};
int main() {
    Solution sol;

    cout << sol.minOperations("kitten", "sitting") << endl;  // Output: 5
    cout << sol.minOperations("flaw", "lawn") << endl;       // Output: 2

    return 0;
}

// | Operation | Complexity |
// | --------- | ---------- |
// | Time      | O(n × m)   |
// | Space     | O(n × m)   |
