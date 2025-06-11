/*
    Reverse a number
    You are given an integer n. Return the integer formed by placing the digits of n in reverse order.

    Examples:
    Input: n = 25

    Output: 52

    Explanation: Reverse of 25 is 52.

    Input: n = 123

    Output: 321

    Explanation: Reverse of 123 is 321.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int reverseNumber(int n) {
        int reverse {0};
        while(n != 0){
            int digit = n % 10;
            reverse = reverse * 10 + digit;
            n = n / 10;
        }
        return reverse;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Solution sol;
    int result = sol.reverseNumber(n);
    cout << "Reversed Number is: " << result << endl;
}