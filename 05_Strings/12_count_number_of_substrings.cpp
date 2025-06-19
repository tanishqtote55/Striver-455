/*
    1. Count All Possible Substrings
    Count the number of all non-empty substrings of a string.

    Example:

    text
    Copy
    Edit
    Input: s = "abc"
    Output: 6
    Explanation: Substrings = "a", "b", "c", "ab", "bc", "abc"
*/

#include <iostream>
#include <string>
using namespace std;

int countSubstrings(string s) {
    int n = s.length();
    return n * (n + 1) / 2;
}

int main() {
    string s = "abc";
    cout << "Total substrings: " << countSubstrings(s) << endl;
    return 0;
}
