/*
    3. Longest Substring Without Repeating Characters
    Given a string s, find the length of the longest substring without duplicate characters.

    Example 1:

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
    Example 2:

    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    Example 3:

    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
    
    Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     if (s.empty())
    //         return 0;

    //     int maxLen = 0;

    //     for (int i = 0; i < s.length(); i++) {
    //         unordered_set<char> seen;

    //         for (int j = i; j < s.length(); j++) {
    //             if (seen.find(s[j]) != seen.end()) {
    //                 // Duplicate found, break and update maxLen
    //                 maxLen = max(maxLen, j - i);
    //                 break;
    //             }
    //             seen.insert(s[j]);
    //         }

    //         // Handle case where no duplicate was found till the end
    //         maxLen = max(maxLen, static_cast<int>(seen.size()));
    //     }

    //     return maxLen;
    // }

    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int maxLen = 0;
        int start = 0;  // left pointer of window

        for (int end = 0; end < s.length(); end++) {
            char currentChar = s[end];

            // If the character is seen and is in current window
            if (lastIndex.find(currentChar) != lastIndex.end() && lastIndex[currentChar] >= start) {
                start = lastIndex[currentChar] + 1; // move start to avoid duplicate
            }

            lastIndex[currentChar] = end; // update last seen index
            maxLen = max(maxLen, end - start + 1); // update max length
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    string input1 = "abcabcbb";
    cout << "Input: " << input1 << "\n";
    cout << "Output: " << sol.lengthOfLongestSubstring(input1) << "\n"; // 3

    string input2 = "bbbbb";
    cout << "Input: " << input2 << "\n";
    cout << "Output: " << sol.lengthOfLongestSubstring(input2) << "\n"; // 1

    string input3 = "abcade";
    cout << "Input: " << input3 << "\n";
    cout << "Output: " << sol.lengthOfLongestSubstring(input3) << "\n"; // 3

    string input4 = "";
    cout << "Input: \"" << input4 << "\"\n";
    cout << "Output: " << sol.lengthOfLongestSubstring(input4) << "\n"; // 0

    return 0;
} 

// Time: O(n), where n is the length of the string.
// Space: O(min(n, m)), where m is the character set size (e.g., 128 for ASCII).