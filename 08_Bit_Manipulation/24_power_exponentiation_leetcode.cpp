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
using namespace std;

double myPow(double x, int n) {
    long long N = n;        // handle INT_MIN safely
    double ans = 1.0;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    while (N > 0) {
        if (N & 1)           // if current bit is 1
            ans *= x;
        x *= x;              // square the base
        N >>= 1;             // shift exponent right
    }
    return ans;
}

int main() {
    double x;
    int n;
    cout << "Enter x (double) and n (int): ";
    cin >> x >> n;
    double result = myPow(x, n);
    cout << x << "^" << n << " = " << result << endl;
    return 0;
}
