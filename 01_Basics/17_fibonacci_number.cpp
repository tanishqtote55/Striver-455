/*
    Fibonacci Number
    The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

    F(0) = 0, F(1) = 1
    F(n) = F(n - 1) + F(n - 2), for n > 1.

    Given n, calculate F(n).

    Examples:
    Input : n = 2

    Output : 1

    Explanation : F(2) = F(1) + F(0) => 1 + 0 => 1.

    Input : n = 3

    Output : 2

    Explanation : F(3) = F(2) + F(1) => 1 + 1 => 2.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int fibRecursion(int n) {
        //your code goes here
        if(n <= 1) return n;
        return fibRecursion(n - 1) + fibRecursion(n - 2);
    }
};

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci of " << n << " is: " << sol.fib(n) << endl;
    return 0;
}