/*
    85. Maximal Rectangle

    Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

    Example 1:
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 6
    Explanation: The maximal rectangle is shown in the above picture.

    Example 2:
    Input: matrix = [["0"]]
    Output: 0

    Example 3:
    Input: matrix = [["1"]]
    Output: 1
    
    Constraints:
    rows == matrix.length
    cols == matrix[i].length
    1 <= row, cols <= 200
    matrix[i][j] is '0' or '1'.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    // Function to compute the largest rectangle area in histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left(n), right(n);
        
        // Nearest smaller to left
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }

        // Clear stack for reuse
        while (!st.empty()) st.pop();

        // Nearest smaller to right
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }

        // Compute max area
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] + 1));
        }

        return maxArea;
    }

    // DP-based main function
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            // Build the histogram for current row
            for (int j = 0; j < cols; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            // Calculate max area in this histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
int main() {
    Solution sol;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    int result = sol.maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << result << endl;  // Output: 6

    return 0;
}

// | Approach       | Time Complexity | Space Complexity |
// | -------------- | --------------- | ---------------- |
// | DP + Histogram | O(rows × cols)  | O(cols)          |