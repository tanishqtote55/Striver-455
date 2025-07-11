/*
    131. Palindrome Partitioning
    Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

    Example 1:

    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]
    Example 2:

    Input: s = "a"
    Output: [["a"]]

    Constraints:

    1 <= s.length <= 16
    s contains only lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void backtrack(int index, string s, vector<string> &path, vector<vector<string>> &res){
        if(index == s.size()){
            res.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                backtrack(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(0, s, path, res);
        return res;
    }
};
// Main function to test
int main() {
    Solution sol;
    string s = "aab";
    vector<vector<string>> result = sol.partition(s);

    cout << "All Palindromic Partitions of \"" << s << "\":" << endl;
    for(const auto& partition : result){
        cout << "[ ";
        for(const auto& str : partition){
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}