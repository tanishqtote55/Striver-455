/*
    921. Minimum Add to Make Parentheses Valid
    A parentheses string is valid if and only if:

    It is the empty string,
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.
    You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

    For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
    Return the minimum number of moves required to make s valid.

    Example 1:
    Input: s = "())"
    Output: 1

    Example 2:
    Input: s = "((("
    Output: 3
    
    Constraints:

    1 <= s.length <= 1000
    s[i] is either '(' or ')'.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, insertions = 0;

        for (char c : s) {
            if (c == '(') {
                open++;
            } else { // c == ')'
                if (open > 0) {
                    open--; // Match with an earlier '('
                } else {
                    insertions++; // Need an extra '('
                }
            }
        }

        return insertions + open;
    }
};

int main() {
    Solution solution;

    // Test cases
    string s1 = "())";
    string s2 = "(((";
    string s3 = "(()())";
    string s4 = "(()))(";

    cout << "Input: " << s1 << " -> Output: " << solution.minAddToMakeValid(s1) << endl;
    cout << "Input: " << s2 << " -> Output: " << solution.minAddToMakeValid(s2) << endl;
    cout << "Input: " << s3 << " -> Output: " << solution.minAddToMakeValid(s3) << endl;
    cout << "Input: " << s4 << " -> Output: " << solution.minAddToMakeValid(s4) << endl;

    return 0;
}

// Time Complexity:
// O(n) — one pass through the string.

// Space Complexity:
// O(1) — only a few integer variables used.