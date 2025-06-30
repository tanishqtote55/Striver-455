/*
    455. Assign Cookies

    Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

    Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

    Example 1:

    Input: g = [1,2,3], s = [1,1]
    Output: 1
    Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
    And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
    You need to output 1.
    Example 2:

    Input: g = [1,2], s = [1,2,3]
    Output: 2
    Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
    You have 3 cookies and their sizes are big enough to gratify all of the children, 
    You need to output 2.
    

    Constraints:

    1 <= g.length <= 3 * 104
    0 <= s.length <= 3 * 104
    1 <= g[i], s[j] <= 231 - 1
    

    Note: This question is the same as 2410: Maximum Matching of Players With Trainers.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // sort greed factors
        sort(s.begin(), s.end()); // sort cookie sizes
        
        int child = 0, cookie = 0;
        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                // cookie satisfies the child
                child++;
            }
            // move to next cookie in any case
            cookie++;
        }
        return child;
    }
};

// Time: O(n log n + m log m) — for sorting both arrays
// Space: O(1) — constant extra space

int main() {
    Solution sol;

    // Example 1
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    cout << "Example 1 Output: " << sol.findContentChildren(g1, s1) << endl;

    // Example 2
    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    cout << "Example 2 Output: " << sol.findContentChildren(g2, s2) << endl;

    return 0;
}