/*
    Number of distinct substrings in a string

    Given a string s, determine the number of distinct substrings (including the empty substring) of the given string.

    A string B is a substring of a string A if B can be obtained by deleting several characters (possibly none) from the start of A and several characters (possibly none) from the end of A. Two strings X and Y are considered different if there is at least one index i such that the character of X at index i is different from the character of Y at index i (X[i] != Y[i]).

    Examples:
    Input : s = "aba"
    Output : 6
    Explanation : The distinct substrings are "a", "ab", "ba", "b", "aba", "".

    Input : s = "abc"
    Output : 7
    Explanation : The distinct substrings are "a", "ab", "abc", "b", "bc", "c", "".
*/
#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Solution {
public:
    int countDistinctSubstring(string s) {
        TrieNode* root = new TrieNode();
        int count = 0;  // Count of new nodes (distinct substrings)

        for (int i = 0; i < s.size(); i++) {
            TrieNode* node = root;
            for (int j = i; j < s.size(); j++) {
                int idx = s[j] - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                    count++; // New substring found
                }
                node = node->children[idx];
            }
        }

        return count + 1;  // +1 for empty string
    }
};
int main() {
    Solution sol;

    string s1 = "aba";
    cout << "Distinct substrings in \"" << s1 << "\": " << sol.countDistinctSubstring(s1) << endl;

    string s2 = "abc";
    cout << "Distinct substrings in \"" << s2 << "\": " << sol.countDistinctSubstring(s2) << endl;

    string s3 = "aaaa";
    cout << "Distinct substrings in \"" << s3 << "\": " << sol.countDistinctSubstring(s3) << endl;

    return 0;
}

// Time & Space Complexity:
// Let n be the length of the string.
// Time Complexity: O(n^2) (for inserting all suffixes)
// Space Complexity: O(n^2) (in worst case all substrings are unique)