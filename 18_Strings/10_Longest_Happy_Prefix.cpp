/*
    1392. Longest Happy Prefix

    A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

    Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

    Example 1:
    Input: s = "level"
    Output: "l"
    Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".

    Example 2:
    Input: s = "ababab"
    Output: "abab"
    Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
    
    Constraints:

    1 <= s.length <= 105
    s contains only lowercase English letters.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n, 0);  // LPS array from KMP

        for (int i = 1; i < n; ++i) {
            int len = lps[i - 1];
            while (len > 0 && s[i] != s[len]) {
                len = lps[len - 1];
            }
            if (s[i] == s[len]) {
                len++;
            }
            lps[i] = len;
        }

        return s.substr(0, lps[n - 1]);
    }
};

int main() {
    Solution sol;

    string s1 = "level";
    cout << "Input: " << s1 << " => Longest Happy Prefix: \"" << sol.longestPrefix(s1) << "\"" << endl;

    string s2 = "ababab";
    cout << "Input: " << s2 << " => Longest Happy Prefix: \"" << sol.longestPrefix(s2) << "\"" << endl;

    string s3 = "leetcode";
    cout << "Input: " << s3 << " => Longest Happy Prefix: \"" << sol.longestPrefix(s3) << "\"" << endl;

    string s4 = "a";
    cout << "Input: " << s4 << " => Longest Happy Prefix: \"" << sol.longestPrefix(s4) << "\"" << endl;

    return 0;
}


// Time Complexity:
// O(n) time
// O(n) space