/*
    XOR of numbers in a given range
    Given two integers L and R. Find the XOR of the elements in the range [L , R].

    Examples:
    Input : L = 3 , R = 5
    Output : 2
    Explanation : answer = (3 ^ 4 ^ 5) = 2.

    Input : L = 1, R = 3
    Output : 0
    Explanation : answer = (1 ^ 2 ^ 3) = 0.
*/

#include <iostream>
using namespace std;

class Solution{	
public:
    // Time Complexity O(n) Space Complexity O(1)
    int findRangeXOR(int l,int r){
        //your code goes here
        int xr = 0; 
        for (int i = l; i <= r; i++) {
            xr = xr ^ i;
        }
        return xr;
    }

    // TC O(1) SC O(1) 
    int xorUpto(int n) {
        if (n % 4 == 0) return n;
        else if (n % 4 == 1) return 1;
        else if (n % 4 == 2) return n + 1;
        else return 0;
    }

    int findRangeXOR(int l, int r) {
        return xorUpto(r) ^ xorUpto(l - 1);
    }
};

int main() {
    int l, r;
    cout << "Enter l and r: ";
    cin >> l >> r;

    Solution sol;
    cout << "XOR from " << l << " to " << r << " = " << sol.findRangeXOR(l, r) << endl;
    return 0;
}