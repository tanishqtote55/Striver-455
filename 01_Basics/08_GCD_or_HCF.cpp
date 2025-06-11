/*
    GCD of Two Numbers
    100
    Hint
    You are given two integers n1 and n2. You need find the Greatest Common Divisor (GCD) of the two given numbers. Return the GCD of the two numbers.

    The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both of the integers.

    Examples:
    Input: n1 = 4, n2 = 6

    Output: 2

    Explanation: Divisors of n1 = 1, 2, 4, Divisors of n2 = 1, 2, 3, 6

    Greatest Common divisor = 2.

    Input: n1 = 9, n2 = 8

    Output: 1

    Explanation: Divisors of n1 = 1, 3, 9 Divisors of n2 = 1, 2, 4, 8.

    Greatest Common divisor = 1.
*/
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int GCD(int n1,int n2) {
        int minimum = min(n1, n2);
        for(int i = minimum; i >= 1; i--){
            if(n1 % i == 0 && n2 % i == 0){
                return i;
            }
        }
        return 0;
    }
};

int main() {
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    Solution sol;
    int result = sol.GCD(n1, n2);

    cout << "GCD of " << n1 << " and " << n2 << " is: " << result << endl;

    return 0;
}