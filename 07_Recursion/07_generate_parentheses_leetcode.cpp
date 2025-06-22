/*
    22. Generate Parentheses
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

    Example 1:

    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]
    Example 2:

    Input: n = 1
    Output: ["()"]

    Constraints:

    1 <= n <= 8
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }

    void backtrack(int n, int open, int close, string current, vector<string>& result) {
        // If the current string is of length 2*n, it's a valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Try adding '(' if we still have openings left
        if (open < n)
            backtrack(n, open + 1, close, current + '(', result);

        // Try adding ')' only if close < open
        if (close < open)
            backtrack(n, open, close + 1, current + ')', result);
    }
};

int main() {
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    Solution solution;
    vector<string> combinations = solution.generateParenthesis(n);

    cout << "All well-formed parentheses combinations:\n";
    for (const string& s : combinations) {
        cout << s << "\n";
    }

    return 0;
}