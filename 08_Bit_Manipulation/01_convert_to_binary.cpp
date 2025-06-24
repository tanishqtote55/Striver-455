#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string convertToBinary(int n) {
    if (n == 0) return "0";

    string res = "";
    while (n > 0) {
        res += (n % 2) + '0';  // Convert int to char ('0' or '1')
        n = n / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    string binary = convertToBinary(n);
    cout << "Binary representation: " << binary << endl;

    return 0;
}


// Time Complexity = Log2(N)
// Space Complexity = Log2(N)