/*
    Leetcode 727: Minimum Window Subsequence
    Problem:
    Given two strings s1 and s2, return the minimum window in s1 which contains s2 as a subsequence. If no such window exists, return "".
    If there are multiple minimum-length windows, return the one with the left-most starting index.

    Example:
    Input:
    s1 = "abcdebdde", s2 = "bde"
    Output:
    "bcde"
*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        int minLen = INT_MAX, start = -1;
        int i = 0;

        while (i < m) {
            int j = 0;

            // Move forward to find a match of s2 in s1
            while (i < m) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == n) break; // full match
                }
                i++;
            }

            if (j < n) break; // not found

            // Backtrack to minimize the window
            int end = i;
            j = n - 1;
            while (j >= 0) {
                if (s1[i] == s2[j]) j--;
                i--;
            }

            i++; // Now i is start index of the valid window
            if (end - i + 1 < minLen) {
                minLen = end - i + 1;
                start = i;
            }

            // Continue scanning from the next character
            i = i + 1;
        }

        return (start == -1) ? "" : s1.substr(start, minLen);
    }
};

int main() {
    Solution sol;

    string s1 = "abcdebdde", s2 = "bde";
    cout << "Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"\n";
    cout << "Output: \"" << sol.minWindow(s1, s2) << "\"\n"; // Expected: "bcde"

    return 0;
}

// Time Complexity:
// Worst-case: O(m × n)
// Where m = length of s1, n = length of s2.
