/*
    Check if String is Palindrome or Not
    Given a string s, return true if the string is palindrome, otherwise false.

    A string is called palindrome if it reads the same forward and backward.

    Examples:
    Input : s = "hannah"

    Output : true

    Explanation : The string when reversed is --> "hannah", which is same as original string , so we return true.

    Input : s = "aabbaaa"

    Output : false

    Explanation : The string when reversed is --> "aaabbaa", which is not same as original string, So we return false.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int i = 0;

    bool palindromeCheck(string& s) {
        int n = s.length();
        if (i >= n / 2) return true;             // Base case: checked all pairs
        if (s[i] != s[n - i - 1]) return false;  // Mismatch found
        i++;                                     // Move inward
        return palindromeCheck(s);              // Recursive check
    }
};

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    Solution sol;
    if (sol.palindromeCheck(str))
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;

    return 0;
}
