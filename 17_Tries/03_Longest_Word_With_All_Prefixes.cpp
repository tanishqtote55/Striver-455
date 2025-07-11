/*
    Longest word with all prefixes

    Given a string array nums of length n. A string is called a complete string if every prefix of this string is also present in the array nums. Find the longest complete string in the array nums.

    If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None" (without quotes).

    Examples:
    Input : nums = [ "n", "ni", "nin", "ninj" , "ninja" , "nil" ]
    Output : ninja
    Explanation : The word "ninja" is the longest word which has all its prefixes present in the array.

    Input : nums = [ "ninja" , "night" , "nil" ]
    Output : None
    Explanation : There is no string that has all its prefix present in array. So we return None.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool allPrefixesExist(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            node = node->children[idx];
            if (!node || !node->isEnd)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    string completeString(vector<string>& words) {
        Trie trie;

        // Insert all words into Trie
        for (string& word : words)
            trie.insert(word);

        string ans = "";
        for (string& word : words) {
            if (trie.allPrefixesExist(word)) {
                if (word.length() > ans.length() || (word.length() == ans.length() && word < ans))
                    ans = word;
            }
        }

        return ans == "" ? "None" : ans;
    }
};

int main() {
    Solution sol;

    vector<string> test1 = {"n", "ni", "nin", "ninj", "ninja", "nil"};
    cout << "Output: " << sol.completeString(test1) << endl;  // Output: ninja

    vector<string> test2 = {"ninja", "night", "nil"};
    cout << "Output: " << sol.completeString(test2) << endl;  // Output: None

    return 0;
}

// Overall Time Complexity:
// O(n * L) — covers insertion, prefix check, and comparison.
// Overall Space Complexity:
// O(n * L)
// n = number of words in the input vector
// L = average length of each word