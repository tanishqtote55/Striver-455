/*

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;

        if (dict.find(endWord) == dict.end()) return ans;

        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> visited; // words visited at current level
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            visited.clear();
            
            for (int i = 0; i < size; ++i) {
                vector<string> path = q.front();
                q.pop();

                string lastWord = path.back();

                for (int j = 0; j < lastWord.size(); ++j) {
                    string temp = lastWord;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[j] = c;
                        if (dict.find(temp) != dict.end()) {
                            vector<string> newPath = path;
                            newPath.push_back(temp);
                            if (temp == endWord) {
                                found = true;
                                ans.push_back(newPath);
                            } else {
                                q.push(newPath);
                                visited.insert(temp);
                            }
                        }
                    }
                }
            }

            // Remove all visited words of this level from dict
            for (const string& word : visited) {
                dict.erase(word);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> res = sol.findLadders(beginWord, endWord, wordList);

    for (const vector<string>& path : res) {
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    return 0;
}

// | Component | Complexity     |
// | --------- | -------------- |
// | **Time**  | `O(W * L * N)` |
// | **Space** | `O(W * N)`     |
