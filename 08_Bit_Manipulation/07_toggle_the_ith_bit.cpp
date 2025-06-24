#include <iostream>
using namespace std;

// Function to toggle the i-th bit of number n
int toggleBit(int n, int i) {
    return n ^ (1 << i);
}

int main() {
    int n, i;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Enter the bit position to toggle (0-based): ";
    cin >> i;

    int newNumber = toggleBit(n, i);

    cout << "Number after toggling bit " << i << ": " << newNumber << endl;
    return 0;
}
