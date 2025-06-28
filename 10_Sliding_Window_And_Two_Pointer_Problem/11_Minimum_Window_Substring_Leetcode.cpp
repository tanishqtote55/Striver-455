/*
    76. Minimum Window Substring
    Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
    The testcases will be generated such that the answer is unique.

    Example 1:
    Input: s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"
    Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

    Example 2:
    Input: s = "a", t = "a"
    Output: "a"
    Explanation: The entire string s is the minimum window.

    Example 3:
    Input: s = "a", t = "aa"
    Output: ""
    Explanation: Both 'a's from t must be included in the window.
    Since the largest window of s only has one 'a', return empty string.
    
    Constraints:

    m == s.length
    n == t.length
    1 <= m, n <= 105
    s and t consist of uppercase and lowercase English letters.
    
    Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        int have = 0, needCount = need.size();  // total distinct characters
        int minLen = INT_MAX, minStart = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c])
                have++;

            // Try to shrink window from left
            while (have == needCount) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                window[leftChar]--;
                if (need.count(leftChar) && window[leftChar] < need[leftChar])
                    have--;
                left++;
            }

            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};

int main() {
    Solution sol;

    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "Test 1 Output: " << sol.minWindow(s1, t1) << endl; // Expected: BANC

    string s2 = "a", t2 = "a";
    cout << "Test 2 Output: " << sol.minWindow(s2, t2) << endl; // Expected: a

    string s3 = "a", t3 = "aa";
    cout << "Test 3 Output: " << sol.minWindow(s3, t3) << endl; // Expected: ""

    return 0;
}

// | Metric | Value    |
// | ------ | -------- |
// | Time   | O(m + n) |
// | Space  | O(n)     |
