/*
    205. Isomorphic Strings
    Given two strings s and t, determine if they are isomorphic.

    Two strings s and t are isomorphic if the characters in s can be replaced to get t.

    All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

    Example 1:

    Input: s = "egg", t = "add"

    Output: true

    Explanation:

    The strings s and t can be made identical by:

    Mapping 'e' to 'a'.
    Mapping 'g' to 'd'.
    Example 2:

    Input: s = "foo", t = "bar"

    Output: false

    Explanation:

    The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

    Example 3:

    Input: s = "paper", t = "title"

    Output: true

    Constraints:

    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for (int i = 0; i < s.length(); ++i) {
            char chS = s[i];
            char chT = t[i];

            // Check mapping from s → t
            if (mapST.count(chS)) {
                if (mapST[chS] != chT) return false;
            } else {
                mapST[chS] = chT;
            }

            // Check mapping from t → s
            if (mapTS.count(chT)) {
                if (mapTS[chT] != chS) return false;
            } else {
                mapTS[chT] = chS;
            }
        }

        return true;
    }
};

// Main function to test
int main() {
    Solution sol;
    
    string s1 = "egg", t1 = "add";
    cout << boolalpha << sol.isIsomorphic(s1, t1) << endl; // true

    string s2 = "foo", t2 = "bar";
    cout << boolalpha << sol.isIsomorphic(s2, t2) << endl; // false

    string s3 = "paper", t3 = "title";
    cout << boolalpha << sol.isIsomorphic(s3, t3) << endl; // true

    return 0;
}
