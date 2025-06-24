#include <iostream>
using namespace std;

// Function to set the rightmost UNSET bit
int setRightmostUnsetBit(int n) {
    return n | (n + 1);
}

// Function to unset the rightmost SET bit
int unsetRightmostSetBit(int n) {
    return n & (n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int afterSet = setRightmostUnsetBit(n);
    int afterUnset = unsetRightmostSetBit(n);

    cout << "Original: " << n << endl;
    cout << "After setting rightmost UNSET bit: " << afterSet << endl;
    cout << "After unsetting rightmost SET bit: " << afterUnset << endl;

    return 0;
}
