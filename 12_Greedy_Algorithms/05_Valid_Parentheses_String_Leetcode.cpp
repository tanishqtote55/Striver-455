/*
    678. Valid Parenthesis String
    Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

    The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

    Example 1:

    Input: s = "()"
    Output: true
    Example 2:

    Input: s = "(*)"
    Output: true
    Example 3:

    Input: s = "(*))"
    Output: true
    
    Constraints:

    1 <= s.length <= 100
    s[i] is '(', ')' or '*'.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    // bool isValid(string& s, int index, int open) {
    //     // Base case: reached end of string
    //     if (index == s.size()) {
    //         return open == 0;
    //     }

    //     // If open becomes negative, there are more ')' than '(' so far → invalid
    //     if (open < 0) return false;

    //     char ch = s[index];

    //     if (ch == '(') {
    //         return isValid(s, index + 1, open + 1);
    //     }
    //     else if (ch == ')') {
    //         return isValid(s, index + 1, open - 1);
    //     }
    //     else { // ch == '*'
    //         // Try all 3 possibilities: '', '(', ')'
    //         return isValid(s, index + 1, open)       // treat '*' as empty
    //             || isValid(s, index + 1, open + 1)   // treat '*' as '('
    //             || isValid(s, index + 1, open - 1);  // treat '*' as ')'
    //     }
    // }

    // bool checkValidString(string s) {
    //     return isValid(s, 0, 0);
    // }

    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char ch : s) {
            if (ch == '(') {
                low++;
                high++;
            } else if (ch == ')') {
                low--;
                high--;
            } else { // '*'
                low--;     // treat * as )
                high++;    // treat * as (
            }

            if (high < 0) return false; // too many closing brackets
            if (low < 0) low = 0;       // minimum open cannot be negative
        }

        return low == 0; // if all '(' can be matched
    }
};


int main() {
    Solution sol;

    cout << boolalpha;
    cout << sol.checkValidString("()") << endl;     // true
    cout << sol.checkValidString("(*)") << endl;    // true
    cout << sol.checkValidString("(*))") << endl;   // true
    cout << sol.checkValidString("(((*)") << endl;  // false

    return 0;
}

// | Metric               | Value                           |
// | -------------------- | ------------------------------- |
// | **Time Complexity**  | `O(3^k)` (worst case: `O(3^n)`) |
// | **Space Complexity** | `O(n)` (recursion depth)        |

// Time: O(n)
// Space: O(1)