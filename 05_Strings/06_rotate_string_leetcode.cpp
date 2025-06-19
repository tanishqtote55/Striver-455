/*
    796. Rotate String
    Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

    A shift on s consists of moving the leftmost character of s to the rightmost position.

    For example, if s = "abcde", then it will be "bcdea" after one shift.

    Example 1:

    Input: s = "abcde", goal = "cdeab"
    Output: true
    Example 2:

    Input: s = "abcde", goal = "abced"
    Output: false

    Constraints:

    1 <= s.length, goal.length <= 100
    s and goal consist of lowercase English letters.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            s = s.substr(1) + s[0];
            if(s == goal){
                return true;
            }
        }
        return false;
    }

    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};

int main() {
    Solution sol;

    string s = "abcde";
    string goal = "cdeab";

    if (sol.rotateString(s, goal)) {
        cout << "Yes, \"" << goal << "\" is a rotation of \"" << s << "\"." << endl;
    } else {
        cout << "No, \"" << goal << "\" is not a rotation of \"" << s << "\"." << endl;
    }

    return 0;
}