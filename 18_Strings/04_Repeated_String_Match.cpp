/*
    686. Repeated String Match

    Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

    Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

    Example 1:
    Input: a = "abcd", b = "cdabcdab"
    Output: 3
    Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

    Example 2:
    Input: a = "a", b = "aa"
    Output: 2
    
    Constraints:

    1 <= a.length, b.length <= 104
    a and b consist of lowercase English letters.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int minRepeats = (b.length() + a.length() - 1) / a.length(); // ceil
        string repeated = "";

        for (int i = 0; i < minRepeats; ++i) {
            repeated += a;
        }

        // Try minRepeats, minRepeats + 1, minRepeats + 2
        for (int i = 0; i <= 2; ++i) {
            if (repeated.find(b) != string::npos) {
                return minRepeats + i;
            }
            repeated += a;
        }

        return -1;
    }
};

int main() {
    Solution solution;
    
     // Example 1
    string a1 = "abcd", b1 = "cdabcdab";
    cout << "a = \"" << a1 << "\", b = \"" << b1 << "\" => Output: "
         << solution.repeatedStringMatch(a1, b1) << endl;

    // Example 2
    string a2 = "a", b2 = "aa";
    cout << "a = \"" << a2 << "\", b = \"" << b2 << "\" => Output: "
         << solution.repeatedStringMatch(a2, b2) << endl;

    // Additional test
    string a3 = "abc", b3 = "cabcabca";
    cout << "a = \"" << a3 << "\", b = \"" << b3 << "\" => Output: "
         << solution.repeatedStringMatch(a3, b3) << endl;
        
    return 0;
}

// Time Complexity:
// Worst Case: O(len(a) * len(b)), because:
// We may repeat a up to len(b) / len(a) + 2 times.
// Each find() can take O(n) time.

// Space Complexity:
// O(len(a) * repeats) → for the concatenated string.