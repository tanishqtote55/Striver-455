/*
    KMP Algorithm or LPS array

    Given two strings, one is a text string, text, and the other is a pattern string, pattern. Find and print the indices of all the occurrences of the pattern string within the text string. Use 0-based indexing for the indices, and ensure that the indices are in ascending order. If the pattern does not occur in the text, return an empty list.

    Implement this solution using the Knuth-Morris-Pratt (KMP) algorithm for efficient pattern matching.

    Examples:
    Input: text = "abracadabra", pattern = "abra"
    Output: 0 7
    Expalanation : The pattern "abra" appears at the 0st and 7th positions in the text "abracadabra".

    Input: text = "abcabcabc", pattern = "abc"
    Output: 0 3 6
    Expalanation : The pattern "abc" appears at the 0st, 3th, and 6th positions in the text "abcabcabc".
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Step 1: Build LPS array
    vector<int> buildLPS(string pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];  // Try previous longest prefix
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // Step 2: KMP Search using LPS array
    vector<int> search(string pattern, string text) {
        int m = pattern.length();
        int n = text.length();
        vector<int> result;
        if (m == 0 || n == 0 || m > n) return result;

        vector<int> lps = buildLPS(pattern);
        int i = 0; // index for text
        int j = 0; // index for pattern

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                result.push_back(i - j);  // Match found
                j = lps[j - 1];           // Try next possible match
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};
int main() {
    Solution sol;

    string text1 = "abracadabra", pattern1 = "abra";
    vector<int> res1 = sol.search(pattern1, text1);
    cout << "Pattern found at indices in text1: ";
    for (int idx : res1) cout << idx << " ";
    cout << endl;

    string text2 = "abcabcabc", pattern2 = "abc";
    vector<int> res2 = sol.search(pattern2, text2);
    cout << "Pattern found at indices in text2: ";
    for (int idx : res2) cout << idx << " ";
    cout << endl;

    return 0;
}
// Time Complexity:
// Preprocessing (LPS): O(m)
// Search: O(n)
// Total: O(n + m)