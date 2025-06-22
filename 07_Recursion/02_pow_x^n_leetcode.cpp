/*
    50. Pow(x, n)
    Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

    Example 1:

    Input: x = 2.00000, n = 10
    Output: 1024.00000
    Example 2:

    Input: x = 2.10000, n = 3
    Output: 9.26100
    Example 3:

    Input: x = 2.00000, n = -2
    Output: 0.25000
    Explanation: 2-2 = 1/22 = 1/4 = 0.25
    

    Constraints:

    -100.0 < x < 100.0
    -231 <= n <= 231-1
    n is an integer.
    Either x is not zero or n > 0.
    -104 <= xn <= 104
*/

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // use long long to handle INT_MIN safely
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return power(x, N);
    }
private:
    double power(double x, long long n) {
        if (n == 0) return 1;
        double half = power(x, n / 2);
        if (n % 2 == 0) return half * half;
        else return half * half * x;
    }
};

int main() {
    Solution sol;

    cout << "2^10 = " << sol.myPow(2.0, 10) << endl;         // 1024
    cout << "2^-2 = " << sol.myPow(2.0, -2) << endl;         // 0.25
    cout << "2^0 = " << sol.myPow(2.0, 0) << endl;           // 1
    cout << "2^-2147483648 = " << sol.myPow(2.0, INT_MIN) << endl; // very close to 0

    return 0;
}