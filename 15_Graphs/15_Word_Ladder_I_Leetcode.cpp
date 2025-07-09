/*
    127. Word Ladder
    A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord
    Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

    Example 1:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    Output: 5
    Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

    Example 2:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
    Output: 0
    Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
    
    Constraints:

    1 <= beginWord.length <= 10
    endWord.length == beginWord.length
    1 <= wordList.length <= 5000
    wordList[i].length == beginWord.length
    beginWord, endWord, and wordList[i] consist of lowercase English letters.
    beginWord != endWord
    All the words in wordList are unique.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool oneLetterDiff(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                diff++;
            }
            if (diff > 1) return false;
        }
        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (int i = 0; i < wordList.size(); ++i) {
            wordSet.insert(wordList[i]);
        }

        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;  // endWord not reachable
        }

        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));

        while (!q.empty()) {
            pair<string, int> current = q.front();
            q.pop();

            string word = current.first;
            int level = current.second;

            if (word == endWord) {
                return level;
            }

            for (int i = 0; i < word.size(); ++i) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;
                    if (wordSet.find(temp) != wordSet.end()) {
                        q.push(make_pair(temp, level + 1));
                        wordSet.erase(temp);  // visited
                    }
                }
            }
        }

        return 0;  // Not found
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Minimum transformation steps: " << result << endl;

    return 0;
}


// Time Complexity:
// O(N * L^2) where:
// N = wordList.size()
// L = length of each word
// Each word generates L × 26 possible next words

// Space Complexity: O(N)