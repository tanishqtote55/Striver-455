/*
    84. Largest Rectangle in Histogram
    Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

    Example 1:
    Input: heights = [2,1,5,6,2,3]
    Output: 10
    Explanation: The above is a histogram where width of each bar is 1.
    The largest rectangle is shown in the red area, which has an area = 10 units.
    
    Example 2:
    Input: heights = [2,4]
    Output: 4

    Constraints:

    1 <= heights.length <= 105
    0 <= heights[i] <= 104
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> st;

        // Previous Smaller Element (PSE)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack for next computation
        while (!st.empty()) st.pop();

        // Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate max area
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            int h = (i == n) ? 0 : heights[i];
 
            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;  // Output: 10
    return 0;
}

// Using PSE AND NSE
// | Metric | Value  |
// | ------ | -----  |
// | Time   | O(5n)  |
// | Space  | O(4n)  |


// Time: O(n) – each index is pushed and popped at most once.
// Space: O(n) – for the stack.