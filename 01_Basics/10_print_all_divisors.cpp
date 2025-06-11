/*
    Divisors of a Number
    You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.

    A number which completely divides another number is called it's divisor.

    Examples:
    Input: n = 6

    Output = [1, 2, 3, 6]

    Explanation: The divisors of 6 are 1, 2, 3, 6.

    Input: n = 8

    Output: [1, 2, 4, 8]

    Explanation: The divisors of 8 are 1, 2, 4, 8.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> v;
        for(int i = 1; i <= n; i++){
            if(n % i == 0){
                v.push_back(i);
            }
        }
        return v;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    vector<int> result = sol.divisors(n);

    cout << "Divisors of " << n << " are: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
