/*
    231. Power of Two
    Given an integer n, return true if it is a power of two. Otherwise, return false.
    An integer n is a power of two, if there exists an integer x such that n == 2x.

    Example 1:

    Input: n = 1
    Output: true
    Explanation: 20 = 1
    Example 2:

    Input: n = 16
    Output: true
    Explanation: 24 = 16
    Example 3:

    Input: n = 3
    Output: false

    Constraints:

    -231 <= n <= 231 - 1
    
    Follow up: Could you solve it without loops/recursion?
*/

#include <iostream>
using namespace std;

// Function to check if n is a power of 2
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfTwo(n)) {
        cout << n << " is a power of 2." << endl;
    } else {
        cout << n << " is NOT a power of 2." << endl;
    }

    return 0;
}
