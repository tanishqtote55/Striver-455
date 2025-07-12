/*
    Rabin Karp Algorithm

    Given a string text and a string pattern, implement the Rabin-Karp algorithm to find the starting index of all occurrences of pattern in text. If pattern is not found, return an empty list.

    Examples:
    Input: text = "ababcabcababc", pattern = "abc"
    Output: [2, 5, 10]
    Expalanation : The pattern "abc" is found at indices 2, 5, and 10 in the text.

    Input: text = "hello", pattern = "ll"
    Output: [2]
    Explanation: The pattern "ll" is found at index 2 in the text.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> search(string pat, string txt) {
        vector<int> result;
        int m = pat.length();
        int n = txt.length();
        if (m > n) return result;

        const int p = 31;
        const int mod = 1e9 + 7;

        // Precompute p^i
        vector<long long> p_pow(max(m, n));
        p_pow[0] = 1;
        for (int i = 1; i < (int)p_pow.size(); ++i) {
            p_pow[i] = (p_pow[i - 1] * p) % mod;
        }

        // Compute hash of pattern
        long long pat_hash = 0;
        for (int i = 0; i < m; ++i) {
            pat_hash = (pat_hash + (pat[i] - 'a' + 1) * p_pow[i]) % mod;
        }

        // Compute prefix hashes of text
        vector<long long> prefix_hash(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix_hash[i + 1] = (prefix_hash[i] + (txt[i] - 'a' + 1) * p_pow[i]) % mod;
        }

        // Sliding window comparison
        for (int i = 0; i <= n - m; ++i) {
            long long current_hash = (prefix_hash[i + m] - prefix_hash[i] + mod) % mod;
            long long expected_hash = (pat_hash * p_pow[i]) % mod;
            if (current_hash == expected_hash) {
                result.push_back(i);
            }
        }

        return result;
    }
};
// ---------------------------
// ✅ Main to test the code
// ---------------------------

int main() {
    Solution sol;

    string text1 = "ababcabcababc";
    string pattern1 = "abc";
    vector<int> res1 = sol.search(pattern1, text1);
    cout << "Pattern found at indices in text1: ";
    for (int idx : res1) cout << idx << " ";
    cout << endl;

    string text2 = "hello";
    string pattern2 = "ll";
    vector<int> res2 = sol.search(pattern2, text2);
    cout << "Pattern found at indices in text2: ";
    for (int idx : res2) cout << idx << " ";
    cout << endl;

    return 0;
}

// Time Complexity:
// O(n + m) average (thanks to rolling hash)

// Worst-case: O(n * m) if there are many hash collisions