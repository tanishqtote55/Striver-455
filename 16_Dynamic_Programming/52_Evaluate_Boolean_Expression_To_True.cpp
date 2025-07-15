/*
    1106. Parsing A Boolean Expression

    A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

    't' that evaluates to true.
    'f' that evaluates to false.
    '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
    '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
    '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
    Given a string expression that represents a boolean expression, return the evaluation of that expression.

    It is guaranteed that the given expression is valid and follows the given rules.

    Example 1:
    Input: expression = "&(|(f))"
    Output: false
    Explanation: 
    First, evaluate |(f) --> f. The expression is now "&(f)".
    Then, evaluate &(f) --> f. The expression is now "f".
    Finally, return false.

    Example 2:
    Input: expression = "|(f,f,f,t)"
    Output: true
    Explanation: The evaluation of (false OR false OR false OR true) is true.

    Example 3:
    Input: expression = "!(&(f,t))"
    Output: true
    Explanation: 
    First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
    Then, evaluate !(f) --> NOT false --> true. We return true.
    
    Constraints:

    1 <= expression.length <= 2 * 104
    expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool evaluate(int i, int j, string &expr, vector<vector<int>> &dp) {
        if (i == j) return expr[i] == 't';

        if (dp[i][j] != -1) return dp[i][j];

        char op = expr[i];  // '!', '&', or '|'
        vector<bool> subresults;
        int bal = 0, start = i + 2;

        for (int k = i + 2; k < j; ++k) {
            if (expr[k] == '(') bal++;
            else if (expr[k] == ')') bal--;
            else if (expr[k] == ',' && bal == 0) {
                subresults.push_back(evaluate(start, k - 1, expr, dp));
                start = k + 1;
            }
        }
        subresults.push_back(evaluate(start, j - 1, expr, dp)); // Last expression

        bool res = false;
        if (op == '!') {
            res = !subresults[0];
        } else if (op == '&') {
            res = true;
            for (bool val : subresults) res &= val;
        } else if (op == '|') {
            res = false;
            for (bool val : subresults) res |= val;
        }

        return dp[i][j] = res;
    }

    bool parseBoolExpr(string expression) {
        int n = expression.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return evaluate(0, n - 1, expression, dp);
    }
};

class Solution2 {
public:
    bool parseBoolExpr(string expression) {
        return eval(expression, 0, expression.size() - 1);
    }

private:
    bool eval(const string& expr, int l, int r) {
        if (l == r) return expr[l] == 't';

        char op = expr[l];
        vector<bool> operands;
        int balance = 0, start = l + 2; // Skip operator and '('

        for (int i = l + 2; i < r; ++i) {
            if (expr[i] == '(') balance++;
            if (expr[i] == ')') balance--;
            if (balance == 0 && (expr[i] == ',' || i == r - 1)) {
                int end = (expr[i] == ',') ? i - 1 : i;
                operands.push_back(eval(expr, start, end));
                start = i + 1;
            }
        }

        if (op == '!') return !operands[0];
        if (op == '&') {
            for (bool b : operands) if (!b) return false;
            return true;
        }
        if (op == '|') {
            for (bool b : operands) if (b) return true;
            return false;
        }

        return false; // Should not reach here
    }
};


int main() {
    Solution2 sol;
    string expr = "|(&(t,f,t),!(t))";
    cout << boolalpha << sol.parseBoolExpr(expr); // Output: false
    return 0;
}
