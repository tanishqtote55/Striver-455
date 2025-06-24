#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);   // odd
        n = n >> 1;         // n / 2
    }
    return count;
}

// Function to count number of set bits in n
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        n = n & (n - 1); // Removes the last set bit
        count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = countSetBits(n);
    cout << "Number of set bits in " << n << " is: " << result << endl;

    return 0;
}
