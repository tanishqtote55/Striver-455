/*
    13. Roman to Integer
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given a roman numeral, convert it to an integer.

    Example 1:

    Input: s = "III"
    Output: 3
    Explanation: III = 3.
    Example 2:

    Input: s = "LVIII"
    Output: 58
    Explanation: L = 50, V= 5, III = 3.
    Example 3:

    Input: s = "MCMXCIV"
    Output: 1994
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
    
    Constraints:

    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == 'I') ans += 1;
            else if(s[i] == 'V'){
                if (i > 0 && s[i - 1] == 'I') {
                    ans += 4;
                    i--;
                } else {
                    ans += 5;
                }
            }
            else if(s[i] == 'X'){
                if (i > 0 && s[i - 1] == 'I') {
                    ans += 9;
                    i--;
                } else {
                    ans += 10;
                }
            }  
            else if(s[i] == 'L'){
                if (i > 0 && s[i - 1] == 'X') {
                    ans += 40;
                    i--;
                } else {
                    ans += 50;
                }
            }
            else if(s[i] == 'C'){
                if (i > 0 && s[i - 1] == 'X') {
                    ans += 90;
                    i--;
                } else {
                    ans += 100;
                }
            }
            else if(s[i] == 'D'){
                if (i > 0 && s[i - 1] == 'C') {
                    ans += 400;
                    i--;
                } else {
                    ans += 500;
                }
            }
            else if(s[i] == 'M'){
                if (i > 0 && s[i - 1] == 'C') {
                    ans += 900;
                    i--;
                } else {
                    ans += 1000;
                }
            }
        }
        return ans;
    }

    int romanToInt(string s) {
        unordered_map<char, int> value = {
            {'I', 1}, {'V', 5},   {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int curr = value[s[i]];
            int next = (i + 1 < s.length()) ? value[s[i + 1]] : 0;

            if (curr < next) {
                ans -= curr;  // subtractive case
            } else {
                ans += curr;  // normal case
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "MCMXCIV";  // 1994
    cout << "Roman to Integer: " << sol.romanToInt(s) << endl;
    return 0;
}