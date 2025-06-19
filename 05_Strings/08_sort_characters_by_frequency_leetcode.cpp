/*
    451. Sort Characters By Frequency
    Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

    Return the sorted string. If there are multiple answers, return any of them.

    Example 1:

    Input: s = "tree"
    Output: "eert"
    Explanation: 'e' appears twice while 'r' and 't' both appear once.
    So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
    Example 2:

    Input: s = "cccaaa"
    Output: "aaaccc"
    Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
    Note that "cacaca" is incorrect, as the same characters must be together.
    Example 3:

    Input: s = "Aabb"
    Output: "bbAa"
    Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
    Note that 'A' and 'a' are treated as two different characters.
    
    Constraints:

    1 <= s.length <= 5 * 105
    s consists of uppercase and lowercase English letters and digits.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(char ch: s){
            freq[ch]++;
        }
        vector<pair<char, int>> charFreq(freq.begin(), freq.end());

        sort(charFreq.begin(), charFreq.end(), [](pair<char, int>& a, pair<char, int>& b){
            return a.second > b.second;
        });

        string result = "";
        for(auto& p: charFreq){
            result += string(p.second, p.first); // repeat char p.second times
        }
        return result;
    }

    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency
        for (char c : s) freq[c]++;

        // Step 2: Create buckets, max possible frequency is s.length()
        vector<string> buckets(s.length() + 1);

        for (auto& [ch, count] : freq) {
            buckets[count] += string(count, ch); // append ch 'count' times
        }

        // Step 3: Build result from highest frequency to lowest
        string result;
        for (int i = buckets.size() - 1; i > 0; --i) {
            if (!buckets[i].empty()) {
                result += buckets[i];
            }
        }

        return result;
    }
};

int main() {
    string s = "tree";
    Solution sol;
    cout << "Sorted by frequency: " << sol.frequencySort(s) << endl;
    return 0;
}