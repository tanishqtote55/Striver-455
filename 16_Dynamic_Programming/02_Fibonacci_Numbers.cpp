#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Memoization TC O(N) SC O(2N) Recusrsion Stack + Array
    int fibMemoization(int n, vector<int> &dp){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fibMemoization(n - 1, dp) + fibMemoization(n - 2, dp);
    }
    // Tabulation TC O(N) SC (N)
    int fibTabulation(int n, vector<int> &dp) {
        if (n <= 1) return n;
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    // Space Optimized Version TC O(N) SC O(1)
    int fib(int n) {
        if (n <= 1) return n;
        int prev2 = 0; // F(0)
        int prev1 = 1; // F(1)
        int curr;
        for (int i = 2; i <= n; ++i) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<int> dp(n + 1, -1);

    cout << "Fibonacci number at position " << n << " is: " << sol.fibMemoization(n, dp) << endl;
    cout << "Fibonacci number at position " << n << " is: " << sol.fibTabulation(n, dp) << endl;
    cout << "Fibonacci number at position " << n << " is: " << sol.fib(n) << endl;
    return 0;
}
