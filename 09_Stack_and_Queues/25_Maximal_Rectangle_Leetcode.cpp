/*
    85. Maximal Rectangle
    Hard
    Topics
    premium lock icon
    Companies
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
using namespace std;

class Solution {
public:
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int maxArea = 0;
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);

        for (const auto& row : matrix) {
            for (int j = 0; j < cols; ++j) {
                // Convert char to int and build histogram
                heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
            }
            // Compute largest rectangle in histogram for this row
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

    cout << "Maximal Rectangle Area: " << sol.maximalRectangle(matrix) << endl;
    return 0;
}

// | Metric | Value                               |
// | ------ | ----------------------------------- |
// | Time   | O(rows × cols)                      |
// | Space  | O(cols) for height vector and stack |
