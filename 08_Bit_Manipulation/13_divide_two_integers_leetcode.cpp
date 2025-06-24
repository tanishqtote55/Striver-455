/*
    29. Divide Two Integers
    Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

    The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

    Return the quotient after dividing dividend by divisor.

    Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

    Example 1:

    Input: dividend = 10, divisor = 3
    Output: 3
    Explanation: 10/3 = 3.33333.. which is truncated to 3.
    Example 2:

    Input: dividend = 7, divisor = -3
    Output: -2
    Explanation: 7/-3 = -2.33333.. which is truncated to -2.
    
    Constraints:

    -231 <= dividend, divisor <= 231 - 1
    divisor != 0
*/

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow explicitly
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        if (dividend == divisor)
            return 1;

        // Use long long to safely store absolute values
        long long a = dividend;
        long long b = divisor;

        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;

        long long result = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        // Determine sign
        if ((dividend < 0) ^ (divisor < 0))
            result = -result;

        return result;
    } 
};

int main() {
    int dividend, divisor;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;

    Solution sol;
    int quotient = sol.divide(dividend, divisor);
    cout << "Quotient: " << quotient << endl;

    return 0;
}

// Approach	                Time Complexity	            Remarks
// Naive (Subtract)	        O(N)	                    Very slow for large N
// Bit-Shift (Efficient)	O(log N)	                Optimal and scalable