/*
    17. Letter Combinations of a Phone Number
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

    A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    Example 1:

    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    Example 2:

    Input: digits = ""
    Output: []
    Example 3:

    Input: digits = "2"
    Output: ["a","b","c"]
    
    Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(int index, string &digits, string &current, vector<string> &result, vector<string> &mapping){
        if(index == digits.size()){
            result.push_back(current);
            return;
        }   
        string letters = mapping[digits[index] - '2'];
        for(char ch: letters){
            current.push_back(ch);
            backtrack(index + 1, digits, current, result, mapping);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mapping = {
            "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        string current;
        backtrack(0, digits, current, result, mapping);
        return result;
    }
};

// Main driver
int main() {
    Solution sol;
    string digits = "23";
    vector<string> combinations = sol.letterCombinations(digits);

    for (const string &s : combinations) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}