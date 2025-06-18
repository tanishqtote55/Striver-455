/*
    1021. Remove Outermost Parentheses
    A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

    For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
    A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

    Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

    Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

    Example 1:

    Input: s = "(()())(())"
    Output: "()()()"
    Explanation: 
    The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
    After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
    Example 2:

    Input: s = "(()())(())(()(()))"
    Output: "()()()()(())"
    Explanation: 
    The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
    After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
    Example 3:

    Input: s = "()()"
    Output: ""
    Explanation: 
    The input string is "()()", with primitive decomposition "()" + "()".
    After removing outer parentheses of each part, this is "" + "" = "".
    
    Constraints:

    1 <= s.length <= 105
    s[i] is either '(' or ')'.
    s is a valid parentheses string.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (depth > 0) result += ch;
                depth++;
            } else {
                depth--;
                if (depth > 0) result += ch;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    string s1 = "(()())(())";
    string s2 = "(()())(())(()(()))";
    string s3 = "()()";

    cout << "Input: " << s1 << "\nOutput: " << sol.removeOuterParentheses(s1) << "\n\n";
    cout << "Input: " << s2 << "\nOutput: " << sol.removeOuterParentheses(s2) << "\n\n";
    cout << "Input: " << s3 << "\nOutput: " << sol.removeOuterParentheses(s3) << "\n\n";

    return 0;
}

