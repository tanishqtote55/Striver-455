#include <iostream>
using namespace std;

// Function to remove the last set bit
int removeLastSetBit(int n) {
    return n & (n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = removeLastSetBit(n);

    cout << "Number after removing last set bit: " << result << endl;
    return 0;
}
