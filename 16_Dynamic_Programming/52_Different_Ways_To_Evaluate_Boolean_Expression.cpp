/*
    Different Ways to Evaluate a Boolean Expression
    You are given a string expr consisting of the characters

    'T' — represents true
    'F' — represents false
    '&' — the logical AND operator
    '|' — the logical OR operator
    '^' — the logical XOR (exclusive-or) operator

    expr is guaranteed to follow the pattern operand operator operand operator … operand (i.e. it always starts and ends with an operand and no two operators are adjacent).
    Return the number of distinct ways to fully parenthesize expr such that the whole expression evaluates to true.
    Because the answer can be very large, return it modulo 1e9+7.

    Examples:
    Input: expr = "T|T&F^T"
    Output: 4
    Explanation:
    The expression can be parenthesized as follows (✓ marks variants that evaluate to true):
    1. ((T|T)&(F^T)) ✓
    2. (T|(T&(F^T))) ✓
    3. (((T|T)&F)^T) ✓
    4. (T|((T&F)^T)) ✓
    5. ((T|(T&F))^T)   → false
    6. (T|T)&F^T     → false
    Therefore 4 distinct parenthesizations evaluate to true.

    Input: expr = "T^F|F"
    Output: 2
    Explanation:
    Two parenthesizations evaluate to true:
    • ((T ^ F) | F)
    • (T ^ (F | F))
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
    const int mod = 1000000007;

    long long f(int i, int j, int isTrue, std::string &exp, std::vector<std::vector<std::vector<long long>>> &dp) {
        if (i > j) return 0;

        if (i == j) {
            if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
            else return exp[i] == 'F' ? 1 : 0;
        }

        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        long long ways = 0;

        for (int ind = i + 1; ind <= j - 1; ind += 2) {
            long long lT = f(i, ind - 1, 1, exp, dp);
            long long lF = f(i, ind - 1, 0, exp, dp);
            long long rT = f(ind + 1, j, 1, exp, dp);
            long long rF = f(ind + 1, j, 0, exp, dp);

            char op = exp[ind];

            if (op == '&') {
                if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
            } else if (op == '|') {
                if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                else ways = (ways + (lF * rF) % mod) % mod;
            } else { // XOR
                if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
            }
        }

        return dp[i][j][isTrue] = ways;
    }

public:
    int countTrue(std::string s) {
        int n = s.size();
        std::vector<std::vector<std::vector<long long>>> dp(n, std::vector<std::vector<long long>>(n, std::vector<long long>(2, -1)));
        return (int)f(0, n - 1, 1, s, dp);
    }
};

class SolutionTab {
    const int mod = 1000000007;

public:
    int countTrue(string exp) {
        int n = exp.size();
        // dp[i][j][isTrue] → number of ways to evaluate exp[i..j] to isTrue (0 or 1)
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));

        // Base case: single characters
        for (int i = 0; i < n; i += 2) {
            dp[i][i][1] = (exp[i] == 'T') ? 1 : 0;
            dp[i][i][0] = (exp[i] == 'F') ? 1 : 0;
        }

        // Fill dp table for all lengths of subexpressions (gap = j - i)
        for (int length = 3; length <= n; length += 2) {
            for (int i = 0; i <= n - length; i += 2) {
                int j = i + length - 1;

                for (int k = i + 1; k < j; k += 2) { // k is the operator position
                    char op = exp[k];

                    long long lT = dp[i][k - 1][1];
                    long long lF = dp[i][k - 1][0];
                    long long rT = dp[k + 1][j][1];
                    long long rF = dp[k + 1][j][0];

                    if (op == '&') {
                        dp[i][j][1] = (dp[i][j][1] + (lT * rT) % mod) % mod;
                        dp[i][j][0] = (dp[i][j][0] + (lF * rT + lT * rF + lF * rF) % mod) % mod;
                    } else if (op == '|') {
                        dp[i][j][1] = (dp[i][j][1] + (lT * rT + lT * rF + lF * rT) % mod) % mod;
                        dp[i][j][0] = (dp[i][j][0] + (lF * rF) % mod) % mod;
                    } else if (op == '^') {
                        dp[i][j][1] = (dp[i][j][1] + (lT * rF + lF * rT) % mod) % mod;
                        dp[i][j][0] = (dp[i][j][0] + (lT * rT + lF * rF) % mod) % mod;
                    }
                }
            }
        }

        return (int)dp[0][n - 1][1]; // Final answer: ways to evaluate whole expression to True
    }
};


int main() {
    SolutionTab sol;
    std::string exp = "F|T^F";
    int result = sol.countTrue(exp);
    std::cout << "Total number of ways: " << result << std::endl;
    return 0;
}
