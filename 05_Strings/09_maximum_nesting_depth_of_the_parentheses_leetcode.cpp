/*
    1614. Maximum Nesting Depth of the Parentheses
    Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

    Example 1:

    Input: s = "(1+(2*3)+((8)/4))+1"

    Output: 3

    Explanation:

    Digit 8 is inside of 3 nested parentheses in the string.

    Example 2:

    Input: s = "(1)+((2))+(((3)))"

    Output: 3

    Explanation:

    Digit 3 is inside of 3 nested parentheses in the string.

    Example 3:

    Input: s = "()(())((()()))"

    Output: 3

    Constraints:

    1 <= s.length <= 100
    s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
    It is guaranteed that parentheses expression s is a VPS.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                maxi++;
                ans = max(ans, maxi);
            } 
            else if(s[i] == ')') maxi--;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    string s1 = "(1+(2*3)+((8)/4))+1";
    string s2 = "(1)+((2))+(((3)))";
    string s3 = "()(())((()()))";

    cout << "Max Depth of s1: " << sol.maxDepth(s1) << endl;
    cout << "Max Depth of s2: " << sol.maxDepth(s2) << endl;
    cout << "Max Depth of s3: " << sol.maxDepth(s3) << endl;

    return 0;
}