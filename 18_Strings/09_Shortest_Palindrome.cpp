/*
    214. Shortest Palindrome

    You are given a string s. You can convert s to a palindrome by adding characters in front of it.
    Return the shortest palindrome you can find by performing this transformation.

    Example 1:
    Input: s = "aacecaaa"
    Output: "aaacecaaa"

    Example 2:
    Input: s = "abcd"
    Output: "dcbabcd"
    
    Constraints:

    0 <= s.length <= 5 * 104
    s consists of lowercase English letters only.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + "#" + rev;

        // Build LPS array
        int n = combined.length();
        vector<int> lps(n, 0);

        for (int i = 1; i < n; ++i) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) {
                ++len;
            }
            lps[i] = len;
        }

        int longest_pal_prefix = lps[n - 1];
        string suffix = s.substr(longest_pal_prefix);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};

int main() {
    Solution sol;

    string s1 = "aacecaaa";
    cout << "Input: " << s1 << " => Output: " << sol.shortestPalindrome(s1) << endl;

    string s2 = "abcd";
    cout << "Input: " << s2 << " => Output: " << sol.shortestPalindrome(s2) << endl;

    string s3 = "aabba";
    cout << "Input: " << s3 << " => Output: " << sol.shortestPalindrome(s3) << endl;

    string s4 = "";
    cout << "Input: \"" << s4 << "\" => Output: \"" << sol.shortestPalindrome(s4) << "\"" << endl;

    return 0;
}

// Time Complexity:
// O(n) time for LPS computation
// O(n) space for the LPS array and reversed string