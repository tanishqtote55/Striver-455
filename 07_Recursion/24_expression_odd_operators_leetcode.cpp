/*
    282. Expression Add Operators
    Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.

    Note that operands in the returned expressions should not contain leading zeros.

    Example 1:

    Input: num = "123", target = 6
    Output: ["1*2*3","1+2+3"]
    Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
    Example 2:

    Input: num = "232", target = 8
    Output: ["2*3+2","2+3*2"]
    Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
    Example 3:

    Input: num = "3456237490", target = 9191
    Output: []
    Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.    

    Constraints:

    1 <= num.length <= 10
    num consists of only digits.
    -231 <= target <= 231 - 1
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void dfs(string& num, int target, int pos, long eval, long prev, string expr, vector<string>& res) {
        if (pos == num.size()) {
            if (eval == target) {
                res.push_back(expr);
            }
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            // Skip numbers with leading zero
            if (i != pos && num[pos] == '0') break;

            string currStr = num.substr(pos, i - pos + 1);
            long currNum = stol(currStr);

            if (pos == 0) {
                // First number (no operator before it)
                dfs(num, target, i + 1, currNum, currNum, currStr, res);
            } else {
                // Add '+'
                dfs(num, target, i + 1, eval + currNum, currNum, expr + "+" + currStr, res);

                // Add '-'
                dfs(num, target, i + 1, eval - currNum, -currNum, expr + "-" + currStr, res);

                // Add '*'
                dfs(num, target, i + 1, eval - prev + prev * currNum, prev * currNum, expr + "*" + currStr, res);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0, 0, 0, "", res);
        return res;
    }
};

int main() {
    Solution sol;

    string num;
    int target;

    cout << "Enter the number string: ";
    cin >> num;

    cout << "Enter the target value: ";
    cin >> target;

    vector<string> expressions = sol.addOperators(num, target);

    cout << "Expressions that evaluate to " << target << ":\n";
    if (expressions.empty()) {
        cout << "No valid expressions found.\n";
    } else {
        for (const string& exp : expressions) {
            cout << exp << endl;
        }
    }

    return 0;
}