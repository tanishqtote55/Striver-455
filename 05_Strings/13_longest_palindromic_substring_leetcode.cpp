/*
    5. Longest Palindromic Substring
    Given a string s, return the longest palindromic substring in s.

    Example 1:

    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.
    Example 2:

    Input: s = "cbbd"
    Output: "bb"
    
    Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0, start = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j) && (j - i + 1 > maxLen)) {
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);
    }

    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            // Odd-length palindrome
            int l1 = i, r1 = i;
            while (l1 >= 0 && r1 < s.size() && s[l1] == s[r1]) {
                if (r1 - l1 + 1 > maxLen) {
                    start = l1;
                    maxLen = r1 - l1 + 1;
                }
                l1--; r1++;
            }

            // Even-length palindrome
            int l2 = i, r2 = i + 1;
            while (l2 >= 0 && r2 < s.size() && s[l2] == s[r2]) {
                if (r2 - l2 + 1 > maxLen) {
                    start = l2;
                    maxLen = r2 - l2 + 1;
                }
                l2--; r2++;
            }
        }

        return s.substr(start, maxLen);
    }

    // Manacher’s Algorithm
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        // Preprocess the string
        string t = "^";
        for (char c : s) {
            t += "#" + string(1, c);
        }
        t += "#$";

        int n = t.size();
        vector<int> p(n, 0);  // palindrome radius array
        int center = 0, right = 0;

        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;

            if (i < right)
                p[i] = min(right - i, p[mirror]);

            while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
                p[i]++;

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }

        // Find max length
        int maxLen = 0, centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }

        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a string: ";
    cin >> input;

    string result = sol.longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}