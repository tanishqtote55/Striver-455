#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
const int p = 31;               // Prime base for lowercase letters
const int mod = 1e9 + 9;        // Large prime modulus

// Precomputes prefix hashes and powers of p
void compute_hashes(const string &s, vector<ll> &hash, vector<ll> &p_pow) {
    int n = s.length();
    hash.resize(n + 1, 0);     // 1-indexed
    p_pow.resize(n + 1, 1);    // p^0 = 1

    for (int i = 1; i <= n; ++i) {
        p_pow[i] = (p_pow[i - 1] * p) % mod;
        hash[i] = (hash[i - 1] + (s[i - 1] - 'a' + 1) * p_pow[i - 1]) % mod;
    }
}

// Get hash of substring s[l...r] (0-indexed, inclusive)
ll get_substring_hash(int l, int r, const vector<ll> &hash, const vector<ll> &p_pow) {
    ll result = (hash[r + 1] - hash[l] + mod) % mod;
    result = (result * p_pow[p_pow.size() - l - 1]) % mod; // Normalize
    return result;
}

int main() {
    string s;
    cout << "Enter a lowercase string: ";
    cin >> s;

    vector<ll> hash, p_pow;
    compute_hashes(s, hash, p_pow);

    int l1, r1, l2, r2;
    cout << "Enter indices of two substrings to compare (0-indexed, inclusive):\n";
    cout << "First substring: l1 r1 = ";
    cin >> l1 >> r1;
    cout << "Second substring: l2 r2 = ";
    cin >> l2 >> r2;

    // Check lengths first
    if (r1 - l1 != r2 - l2) {
        cout << "Substrings are of different lengths, so NOT equal.\n";
    } else {
        ll hash1 = get_substring_hash(l1, r1, hash, p_pow);
        ll hash2 = get_substring_hash(l2, r2, hash, p_pow);
        if (hash1 == hash2)
            cout << "The substrings are EQUAL.\n";
        else
            cout << "The substrings are NOT equal.\n";
    }

    return 0;
}
