/*
    1781. Sum of Beauty of All Substrings
    The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

    For example, the beauty of "abaacc" is 3 - 1 = 2.
    Given a string s, return the sum of beauty of all of its substrings.

    Example 1:

    Input: s = "aabcb"
    Output: 5
    Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
    Example 2:

    Input: s = "aabcbaa"
    Output: 17
    
    Constraints:

    1 <= s.length <= 500
    s consists of only lowercase English letters.
*/

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int beauty(string s, int l, int r){
        vector<int> freq(26, 0);
        for(int i = l; i <= r; i++){
            freq[s[i] - 'a']++;
        }
        int maxFreq = 0, minFreq = INT_MAX;
        for (int f : freq) {
            if (f > 0) {
                maxFreq = max(maxFreq, f);
                minFreq = min(minFreq, f);
            }
        }
        return maxFreq - minFreq;
    }
    int beautySum(string s) {
        int total = 0;
        for(int i = 0; i < s.length(); i++){
            for (int j = i; j < s.length(); j++) {
                total += beauty(s, i, j);
            }
        }
        return total;
    }

    int beautySum(string s) {
        int n = s.size();
        int totalBeauty = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                freq[idx]++;

                int maxFreq = 0, minFreq = INT_MAX;
                for (int f : freq) {
                    if (f > 0) {
                        maxFreq = max(maxFreq, f);
                        minFreq = min(minFreq, f);
                    }
                }

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};

int main() {
    Solution sol;
    string s = "aabcb";
    cout << "Sum of beauty of all substrings: " << sol.beautySum(s) << endl;
    return 0;
}