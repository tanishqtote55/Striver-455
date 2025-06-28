/*
    1358. Number of Substrings Containing All Three Characters
    Given a string s consisting only of characters a, b and c.
    Return the number of substrings containing at least one occurrence of all these characters a, b and c.

    Example 1:

    Input: s = "abcabc"
    Output: 10
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
    Example 2:

    Input: s = "aaacb"
    Output: 3
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
    Example 3:

    Input: s = "abc"
    Output: 1
    
    Constraints:

    3 <= s.length <= 5 x 10^4
    s only consists of a, b or c characters.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // int numberOfSubstrings(string s) {
    //     int count = 0;
    //     int n = s.size();

    //     for (int i = 0; i < n; ++i) {
    //         bool hasA = false, hasB = false, hasC = false;

    //         for (int j = i; j < n; ++j) {
    //             if (s[j] == 'a') hasA = true;
    //             if (s[j] == 'b') hasB = true;
    //             if (s[j] == 'c') hasC = true;

    //             if (hasA && hasB && hasC) count++;
    //         }
    //     }

    //     return count;
    // }

    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> freq(3, 0); // for 'a', 'b', 'c'
        int left = 0, result = 0;

        for (int right = 0; right < n; ++right) {
            freq[s[right] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // All 'a', 'b', 'c' are present
                result += n - right;
                freq[s[left] - 'a']--;
                left++;
            }
        }

        return result;
    }

    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> lastseen(3, -1); // for 'a', 'b', 'c'
        int count = 0;

        for (int i = 0; i < n; i++) {
            lastseen[s[i] - 'a'] = i;
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1)
                count += 1 + min(lastseen[0], min(lastseen[1], lastseen[2]));
        }

        return count;
    }
};

int main() {
    Solution sol;

    string s1 = "abcabc";
    cout << "Test Case 1: s = \"abcabc\"\n";
    cout << "Output: " << sol.numberOfSubstrings(s1) << "\n"; // Expected: 10

    string s2 = "aaacb";
    cout << "\nTest Case 2: s = \"aaacb\"\n";
    cout << "Output: " << sol.numberOfSubstrings(s2) << "\n"; // Expected: 3

    string s3 = "abc";
    cout << "\nTest Case 3: s = \"abc\"\n";
    cout << "Output: " << sol.numberOfSubstrings(s3) << "\n"; // Expected: 1

    return 0;
}