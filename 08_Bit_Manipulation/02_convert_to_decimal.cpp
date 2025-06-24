#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int convertToDecimal(string s) {
    int len = s.length();
    int ans = 0;
    int pow2 = 1;
    for(int i = len - 1; i >= 0; i--){
        // ans += (s[i] - '0') * pow(2, len - i - 1);
        if(s[i] == '1') ans += pow2;
        pow2 = 2 * pow2;
    }
    return ans;
}

int convertToDecimal(string s) {
    int ans = 0;
    for(char c : s) {
        ans = ans * 2 + (c - '0');
    }
    return ans;
}

int main() {
    string binary;
    cout << "Enter a string: ";
    cin >> binary;

    int n = convertToDecimal(binary);
    cout << "Decimal representation: " << n << endl;

    return 0;
}


// Time Complexity = O(len)
// Space Complexity = O(1)