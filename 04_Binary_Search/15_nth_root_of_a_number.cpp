/*
    Find Nth root of a number
    Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.

    Examples:
    Input: N = 3, M = 27

    Output: 3

    Explanation: The cube root of 27 is equal to 3.

    Input: N = 4, M = 69

    Output:-1

    Explanation: The 4th root of 69 does not exist. So, the answer is -1.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper function to compute base^exp safely
    // It performs exponentiation by multiplying and checks if we exceeded M
    long long power(long long base, int n, int m) {
        long long result = 1;
        for(int i = 1; i <= n; i++) {
            result *= base;
            if (result > m) return m + 1; // To avoid overflow
        }
        return result;
    }

    int NthRoot(int n, int m) {
        int low = 1, high = m;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long p = power(mid, n, m);
            
            if (p == m) return mid;
            else if (p < m) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

int main() {
    int n = 3, m = 27;
    Solution sol;
    int ans = sol.NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
