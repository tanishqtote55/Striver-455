/*
    Check for Prime Number
    You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.

    A prime number is a number which has no divisors except 1 and itself.

    Examples:
    Input: n = 5

    Output: true

    Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.

    Input: n = 8

    Output: false

    Explanation: The divisors of 8 are 1, 2, 4, 8, thus it is not a prime number.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        //your code goes here
        if (n <= 1) return false; 
        if (n == 2) return true;
        for(int i = 2; i < n; i++){
            if(n % i == 0){
                return false;
                break;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    if (sol.isPrime(n))
        cout << n << " is a prime number." << endl;
    else
        cout << n << " is not a prime number." << endl;

    return 0;
}