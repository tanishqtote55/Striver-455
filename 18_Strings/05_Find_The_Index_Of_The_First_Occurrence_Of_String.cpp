/*
    28. Find the Index of the First Occurrence in a String

    Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

    Example 1:
    Input: haystack = "sadbutsad", needle = "sad"
    Output: 0
    Explanation: "sad" occurs at index 0 and 6.
    The first occurrence is at index 0, so we return 0.

    Example 2:
    Input: haystack = "leetcode", needle = "leeto"
    Output: -1
    Explanation: "leeto" did not occur in "leetcode", so we return -1.
    
    Constraints:

    1 <= haystack.length, needle.length <= 104
    haystack and needle consist of only lowercase English characters.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0;

        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                ++j;
            }
            if (j == m) return i;  // Match found
        }

        return -1;  // No match
    }
};

int main() {
    Solution solution;

    // Test Case 1
    string haystack1 = "sadbutsad";
    string needle1 = "sad";
    cout << "haystack = \"" << haystack1 << "\", needle = \"" << needle1 << "\" => Output: "
         << solution.strStr(haystack1, needle1) << endl;

    // Test Case 2
    string haystack2 = "leetcode";
    string needle2 = "leeto";
    cout << "haystack = \"" << haystack2 << "\", needle = \"" << needle2 << "\" => Output: "
         << solution.strStr(haystack2, needle2) << endl;

    // Test Case 3
    string haystack3 = "abc";
    string needle3 = "";
    cout << "haystack = \"" << haystack3 << "\", needle = \"" << needle3 << "\" => Output: "
         << solution.strStr(haystack3, needle3) << endl;

    return 0;
}

// Time Complexity:
// O(n * m) in worst case
// n = length of haystack
// m = length of needle