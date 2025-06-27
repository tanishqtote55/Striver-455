/*
    402. Remove K Digits
    Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

    Example 1:

    Input: num = "1432219", k = 3
    Output: "1219"
    Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
    Example 2:

    Input: num = "10200", k = 1
    Output: "200"
    Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
    Example 3:

    Input: num = "10", k = 2
    Output: "0"
    Explanation: Remove all the digits from the number and it is left with nothing which is 0.
    

    Constraints:

    1 <= k <= num.length <= 105
    num consists of only digits.
    num does not have any leading zeros except for the zero itself.
*/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (char digit : num) {
            // Pop from stack while the current digit is smaller than top and we still have k > 0
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        // If still k > 0, pop remaining digits from top
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        // Build the result from stack (reverse it)
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        result = result.substr(start);
        return result.empty() ? "0" : result;
    }
};

int main() {
    Solution sol;
    cout << sol.removeKdigits("1432219", 3) << endl; // Output: "1219"
    cout << sol.removeKdigits("10200", 1) << endl;   // Output: "200"
    cout << sol.removeKdigits("10", 2) << endl;      // Output: "0"
    return 0;
}

// | Metric | Value |
// | ------ | ----- |
// | Time   | O(n)  |
// | Space  | O(n)  |
