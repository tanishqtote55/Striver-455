/*
    Check if the Number is Armstrong
    You are given an integer n. You need to check whether it is an armstrong number or not. Return true if it is an armstrong number, otherwise return false.

    An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.

    Examples:
    Input: n = 153

    Output: true

    Explanation: Number of digits : 3.

    1 ^ 3 + 5 ^ 3 + 3 ^ 3 = 1 + 125 + 27 = 153.

    Therefore, it is an Armstrong number.

    Input: n = 12

    Output: false

    Explanation: Number of digits : 2.

    1 ^ 2 + 2 ^ 2 = 1 + 4 = 5.

    Therefore, it is not an Armstrong number.
*/

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {
        int temp = n;
        int digits {0};
        while(temp != 0){
            temp = temp / 10;
            digits++;
        }
        int sum = 0;
        temp = n;
        while(temp != 0){
            int digit = temp % 10;
            sum +=(int)(round(pow(digit, digits)));
            temp = temp / 10;
        }
        return sum == n;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    if (sol.isArmstrong(n))
        cout << n << " is an Armstrong number." << endl;
    else
        cout << n << " is not an Armstrong number." << endl;
    return 0;
}