#include <iostream>
using namespace std;

// Function to clear the i-th bit of number n
int clearBit(int n, int i) {
    return n & (~(1 << i));
}

int main() {
    int n, i;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Enter the bit position to clear (0-based): ";
    cin >> i;

    int newNumber = clearBit(n, i);

    cout << "Number after clearing bit " << i << ": " << newNumber << endl;
    return 0;
}
