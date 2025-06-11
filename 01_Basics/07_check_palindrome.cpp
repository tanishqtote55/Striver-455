/*
    Palindrome Number
    You are given an integer n. You need to check whether the number is a palindrome number or not. Return true if it's a palindrome number, otherwise return false.

    A palindrome number is a number which reads the same both left to right and right to left.

    Examples:
    Input: n = 121

    Output: true

    Explanation: When read from left to right : 121.

    When read from right to left : 121.

    Input: n = 123

    Output: false

    Explanation: When read from left to right : 123.

    When read from right to left : 321.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int n) {
        int original = n;
        int reverse {0};
        while(n != 0){
            int digit = n % 10;
            reverse = reverse * 10 + digit;
            n = n / 10;
        }
        return reverse == original;
    }
};

int main() {
    int n {0};
    cout << "Enter a number: ";
    cin >> n;
    Solution sol;
    if (sol.isPalindrome(n))
        cout << "Palindrome number" << endl;
    else
        cout << "Not a palindrome number" << endl;
    return 0;
}