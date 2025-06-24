#include <iostream>
using namespace std;

// Function to check if number is odd
bool isOdd(int n) {
    return (n & 1);  // If last bit is 1, number is odd
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isOdd(n)) {
        cout << n << " is ODD." << endl;
    } else {
        cout << n << " is EVEN." << endl;
    }

    return 0;
}
