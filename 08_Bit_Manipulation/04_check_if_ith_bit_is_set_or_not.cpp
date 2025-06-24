#include <iostream>
using namespace std;

// Function to check if the i-th bit is set in number n
bool isBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
    // return (1 & (n >> i)) == 0;
}

int main() {
    int n, i;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Enter the bit position to check (0-based): ";
    cin >> i;

    if (isBitSet(n, i)) {
        cout << "Bit " << i << " is SET in number " << n << "." << endl;
    } else {
        cout << "Bit " << i << " is NOT set in number " << n << "." << endl;
    }

    return 0;
}