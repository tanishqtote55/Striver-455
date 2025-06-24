#include <iostream>
using namespace std;

void primeFactors(int n) {
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // n must be odd at this point, so skip even numbers
    for (int i = 3; i*i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}

// TC O(sqrt(N) * logN)
void uniquePrimeFactors(int n) {
    // 1. Check if 2 is a prime factor
    if (n % 2 == 0) {
        cout << 2 << " ";     // Print 2 once
        while (n % 2 == 0)
            n /= 2;           // Remove all factors of 2 from n
    }

    // 2. Check for odd prime factors
    for (int i = 3; i*i <= n; i += 2) {
        if (n % i == 0) {
            cout << i << " "; // Print i once
            while (n % i == 0)
                n /= i;       // Remove all i's from n
        }
    }

    // 3. If n is still > 2, then it is a prime number
    if (n > 2)
        cout << n << " ";
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime factors: ";
    // primeFactors(n);
    uniquePrimeFactors(n);
    cout << endl;

    return 0;
}
