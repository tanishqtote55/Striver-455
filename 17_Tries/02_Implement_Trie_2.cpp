/*
    Trie Implementation and Advanced Operations
    Implement "TRIE” data structure from scratch with the following functions.

    Trie(): Initialize the object of this “TRIE” data structure.
    insert(“WORD”): Insert the string “WORD” into this “TRIE” data structure.
    countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.
    countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.
    erase(“WORD”): Delete one occurrence of the string “WORD” from the “TRIE”.

    Examples:
    Input : ["Trie", "insert", "countWordsEqualTo", "insert", "countWordsStartingWith", "erase", "countWordsStartingWith"]
    [ [], ["apple"], ["apple"], ["app"], ["app"], ["apple"], ["app"] ]
    Output : [null, null, 1, null, 2, null, 1]
    Explanation :
    Trie trie = new Trie()
    trie.insert("apple")
    trie.countWordsEqualTo("apple")  // return 1
    trie.insert("app") 
    trie.countWordsStartingWith("app") // return 2
    trie.erase("apple")
    trie.countWordsStartingWith("app")   // return 1

    Input : ["Trie", "insert", "countWordsEqualTo", "insert", "erase", "countWordsStartingWith"]
    [ [], ["mango"], ["apple"], ["app"], ["app"], ["mango"] ]
    Output : [null, null, 0, null, null, 1]
    Explanation :
    Trie trie = new Trie()
    trie.insert("mango")
    trie.countWordsEqualTo("apple")  // return 0
    trie.insert("app") 
    trie.erase("app")
    trie.countWordsStartingWith("mango") // return 1
*/

#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int wordCount;       // Counts how many times a complete word ends here
    int prefixCount;     // Counts how many words pass through this node

    TrieNode() {
        wordCount = 0;
        prefixCount = 0;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
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
            node->prefixCount++;
        }
        node->wordCount++;
    }

    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                return 0;
            node = node->children[idx];
        }
        return node->wordCount;
    }

    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx])
                return 0;
            node = node->children[idx];
        }
        return node->prefixCount;
    }

    void erase(string word) {
        if (countWordsEqualTo(word) == 0)
            return;  // Word doesn't exist, nothing to erase

        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            TrieNode* child = node->children[idx];
            child->prefixCount--;
            node = child;
        }
        node->wordCount--;
    }
};
int main() {
    Trie trie;

    trie.insert("apple");
    cout << trie.countWordsEqualTo("apple") << endl;     // 1

    trie.insert("app");
    cout << trie.countWordsStartingWith("app") << endl;  // 2

    trie.erase("apple");
    cout << trie.countWordsStartingWith("app") << endl;  // 1

    trie.insert("mango");
    cout << trie.countWordsEqualTo("apple") << endl;     // 0

    trie.erase("app");
    cout << trie.countWordsStartingWith("mango") << endl; // 1

    return 0;
}



// Time Complexities:
// insert, count, erase: O(L) where L is the length of the word.
// Efficient even with large number of operations (up to 30,000 calls).