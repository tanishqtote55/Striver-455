/*
    20. Valid Parentheses
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
    

    Example 1:
    Input: s = "()"
    Output: true
    Example 2:
    Input: s = "()[]{}"
    Output: true
    Example 3:
    Input: s = "(]"
    Output: false
    Example 4:
    Input: s = "([])"
    Output: true

    Constraints:
    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char c : s) {
            // Push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            }
            // For closing brackets, check for matching top
            else {
                if (stk.empty()) return false;

                char top = stk.top();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
                stk.pop();
            }
        }

        return stk.empty();  // valid only if no unmatched brackets
    }
};

int main() {
    Solution sol;

    cout << boolalpha;
    cout << sol.isValid("()") << endl;       // true
    cout << sol.isValid("()[]{}") << endl;   // true
    cout << sol.isValid("(]") << endl;       // false
    cout << sol.isValid("([])") << endl;     // true
    cout << sol.isValid("([)]") << endl;     // false

    return 0;
}