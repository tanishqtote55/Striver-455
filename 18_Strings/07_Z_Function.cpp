/*
    Z function

    Given two strings, one is a text string, text, and the other is a pattern string, pattern. Print the indexes of all occurrences of the pattern string in the text string using the Z function algorithm. Use 0-based indexing while returning the indices.

    Examples:
    Input: text = "xyzabxyzabxyz", pattern = "xyz"
    Output: 0 5 10
    Expalanation : The pattern "xyz" occurs three times in text, starting at indices 0, 5, and 10.

    Input: text = "cabcdab", pattern = "abc"
    Output: 1
    Expalanation : The pattern "abc" occurs one time in text, starting at index 1.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> search(string text, string pattern) {
        string combined = pattern + "$" + text;
        int n = combined.size();
        int m = pattern.size();
        vector<int> z(n, 0);
        vector<int> result;

        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && combined[z[i]] == combined[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        // Collect positions where pattern matches
        for (int i = m + 1; i < n; ++i) {
            if (z[i] == m) {
                result.push_back(i - m - 1);  // Convert to index in text
            }
        }

        return result;
    }
};
int main() {
    Solution sol;

    string text1 = "xyzabxyzabxyz";
    string pattern1 = "xyz";
    vector<int> res1 = sol.search(text1, pattern1);
    cout << "Pattern found at indices in text1: ";
    for (int idx : res1) cout << idx << " ";
    cout << endl;

    string text2 = "cabcdab";
    string pattern2 = "abc";
    vector<int> res2 = sol.search(text2, pattern2);
    cout << "Pattern found at indices in text2: ";
    for (int idx : res2) cout << idx << " ";
    cout << endl;

    return 0;
}

// Time Complexity:
// O(n + m) where n = text.length() and m = pattern.length()
// Super efficient for long strings.