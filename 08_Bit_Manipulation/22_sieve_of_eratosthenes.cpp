/*
    204. Count Primes
    Given an integer n, return the number of prime numbers that are strictly less than n.

    Example 1:
    Input: n = 10
    Output: 4
    Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
    
    Example 2:
    Input: n = 0
    Output: 0
    
    Example 3:
    Input: n = 1
    Output: 0

    Constraints:
    0 <= n <= 5 * 106
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Time Complexity: O(n log log n)
    // Space Complexity: O(n)
    // Prime Harmonic Series
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);  // assume all numbers < n are prime
        isPrime[0] = isPrime[1] = false;

        // Sieve of Eratosthenes
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;  // mark multiples of i as not prime
                }
            }
        }

        // Count the remaining true values in isPrime[]
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) ++count;
        }

        return count;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    int primeCount = sol.countPrimes(n);

    cout << "Number of primes less than " << n << " is: " << primeCount << endl;

    return 0;
}
