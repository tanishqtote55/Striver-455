#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate binary strings
void generateBinaryStrings(int n, string current) {
    if (n == 0) {
        cout << current << endl;
        return;
    }

    // Add '0' and recurse
    generateBinaryStrings(n - 1, current + '0');

    // Add '1' and recurse
    generateBinaryStrings(n - 1, current + '1');
}

// Driver code
int main() {
    int n;
    cout << "Enter the length of binary strings: ";
    cin >> n;

    cout << "All binary strings of length " << n << ":\n";
    generateBinaryStrings(n, "");

    return 0;
}
