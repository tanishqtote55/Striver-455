#include <iostream>
using namespace std;

// Function to set the i-th bit of number n
int setBit(int n, int i) {
    return n | (1 << i);
}

int main() {
    int n, i;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Enter the bit position to set (0-based): ";
    cin >> i;

    int newNumber = setBit(n, i);

    cout << "Number after setting bit " << i << ": " << newNumber << endl;
    return 0;
}
