/*
    Longest Substring With At Most K Distinct Characters
    Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters.

    Examples:
    Input : s = "aababbcaacc" , k = 2
    Output : 6
    Explanation : The longest substring with at most two distinct characters is "aababb".
    The length of the string 6.

    Input : s = "abcddefg" , k = 3
    Output : 4
    Explanation : The longest substring with at most three distinct characters is "bcdd".
    The length of the string 4.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int left = 0, maxLen = 0;
        unordered_map<char, int> freq;
        for (int right = 0; right < s.size(); ++right) {
            freq[s[right]]++;
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++; // shrink the window
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    int kDistinctChar(string& s, int k) {
        //your code goes here
        int left = 0, maxLen = 0;
        unordered_map<char, int> freq;
        for (int right = 0; right < s.length(); ++right) {
            freq[s[right]]++;
            if (freq.size() > k) {
                // shrink the window by 1
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }
            if (freq.size() <= k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;

    string s1 = "aababbcaacc";
    int k1 = 2;
    cout << "Input: \"" << s1 << "\", k = " << k1 << "\n";
    cout << "Output: " << sol.kDistinctChar(s1, k1) << "\n"; // Expected: 6

    string s2 = "abcddefg";
    int k2 = 3;
    cout << "\nInput: \"" << s2 << "\", k = " << k2 << "\n";
    cout << "Output: " << sol.kDistinctChar(s2, k2) << "\n"; // Expected: 4

    string s3 = "aaaaa";
    int k3 = 1;
    cout << "\nInput: \"" << s3 << "\", k = " << k3 << "\n";
    cout << "Output: " << sol.kDistinctChar(s3, k3) << "\n"; // Expected: 5

    return 0;
}