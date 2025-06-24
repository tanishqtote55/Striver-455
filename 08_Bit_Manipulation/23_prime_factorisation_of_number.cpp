/*
    Prime factorisation of a Number
    You are given an integer array queries of length n.
    Return the prime factorization of each number in array queries in sorted order.

    Examples:
    Input : queries = [2, 3, 4, 5, 6]
    Output : [ [2], [3], [2, 2], [5], [2, 3] ]
    Explanation : The values 2, 3, 5 are itself prime numbers.
    The prime factorization of 4 will be --> 2 * 2.
    The prime factorization of 6 will be --> 2 * 3.

    Input : queries = [7, 12, 18]
    Output : [ [7], [2, 2, 3], [2, 3, 3] ]
    Explanation : The value 7 itself is a prime number.
    The prime factorization of 12 will be --> 2 * 2 * 3.
    The prime factorization of 18 will be --> 2 * 3 * 3.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // TC O(q * √n)
    vector<vector<int>> primeFactors(vector<int>& queries) {
        vector<vector<int>> result;

        for (int n : queries) {
            vector<int> factors;
            // Step 1: Remove all factors of 2
            while (n % 2 == 0) {
                factors.push_back(2);
                n /= 2;
            }
            // Step 2: Check for odd prime factors
            for (int i = 3; i * i <= n; i += 2) {
                while (n % i == 0) {
                    factors.push_back(i);
                    n /= i;
                }
            }
            // Step 3: If remaining n is a prime > 2
            if (n > 2)
                factors.push_back(n);
            result.push_back(factors);
        }
        return result;
    }
    
    // TC O(N log log N + q log N)
    vector<vector<int>> primeFactors(vector<int>& queries) {
        int maxN = *max_element(queries.begin(), queries.end());

        // Step 1: Compute Smallest Prime Factors (SPF) for all numbers up to maxN
        vector<int> spf(maxN + 1);
        for (int i = 0; i <= maxN; ++i)
            spf[i] = i;

        for (int i = 2; i * i <= maxN; ++i) {
            if (spf[i] == i) { // i is prime
                for (int j = i * i; j <= maxN; j += i) {
                    if (spf[j] == j)
                        spf[j] = i; // update SPF only the first time
                }
            }
        }

        // Step 2: Use SPF to factorize each number in queries
        vector<vector<int>> result;
        for (int num : queries) {
            vector<int> factors;
            while (num > 1) {
                factors.push_back(spf[num]);
                num /= spf[num];
            }
            result.push_back(factors);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> queries = {2, 3, 4, 5, 6, 7, 12, 18, 100};
    vector<vector<int>> result = sol.primeFactors(queries);

    for (const auto& factors : result) {
        cout << "[ ";
        for (int f : factors)
            cout << f << " ";
        cout << "]" << endl;
    }

    return 0;
}