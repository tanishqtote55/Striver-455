/*
    424. Longest Repeating Character Replacement
    You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

    Return the length of the longest substring containing the same letter you can get after performing the above operations.

    Example 1:

    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.
    Example 2:

    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.
    There may exists other ways to achieve this answer too.

    Constraints:

    1 <= s.length <= 105
    s consists of only uppercase English letters.
    0 <= k <= s.length
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // int characterReplacement(string s, int k) {
    //     int maxLen = 0;
    //     int n = s.length();
    //     for (int i = 0; i < n; i++) {
    //         vector<int> freq(26, 0);
    //         int maxFreq = 0;

    //         for (int j = i; j < n; j++) {
    //             freq[s[j] - 'A']++;
    //             maxFreq = max(maxFreq, freq[s[j] - 'A']);

    //             int replacementsNeeded = (j - i + 1) - maxFreq;
    //             if (replacementsNeeded <= k) {
    //                 maxLen = max(maxLen, j - i + 1);
    //             } else {
    //                 break;
    //             }
    //         }
    //     }
    //     return maxLen;
    // }

    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxFreq = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If more than k replacements needed, shrink window
            if ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    string s1 = "ABAB";
    int k1 = 2;
    cout << "Test Case 1:\nInput: \"" << s1 << "\", k = " << k1 << "\n";
    cout << "Output: " << sol.characterReplacement(s1, k1) << "\n\n"; // Expected: 4

    string s2 = "AABABBA";
    int k2 = 1;
    cout << "Test Case 2:\nInput: \"" << s2 << "\", k = " << k2 << "\n";
    cout << "Output: " << sol.characterReplacement(s2, k2) << "\n\n"; // Expected: 4

    string s3 = "AAAA";
    int k3 = 2;
    cout << "Test Case 3:\nInput: \"" << s3 << "\", k = " << k3 << "\n";
    cout << "Output: " << sol.characterReplacement(s3, k3) << "\n\n"; // Expected: 4

    string s4 = "ABCDE";
    int k4 = 1;
    cout << "Test Case 4:\nInput: \"" << s4 << "\", k = " << k4 << "\n";
    cout << "Output: " << sol.characterReplacement(s4, k4) << "\n"; // Expected: 2

    return 0;
}