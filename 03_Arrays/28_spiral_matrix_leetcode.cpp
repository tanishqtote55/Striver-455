/*
    54. Spiral Matrix
    Given an m x n matrix, return all elements of the matrix in spiral order.

    Example 1:

    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,3,6,9,8,7,4,5]
    Example 2:

    Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    Output: [1,2,3,4,8,12,11,10,9,5,6,7]
    
    Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        // Define ans array to store the result.
        vector<int> ans;
        
        int n = mat.size(); // no. of nows
        int m = mat[0].size(); // no. of columns
        
        // Initialize the pointers reqd for traversal.
        int top = 0, left = 0, bottom = n - 1, right = m - 1;

        // Loop until all elements are not traversed.
        while (top <= bottom && left <= right) {
            
            // For moving left to right
            for (int i = left; i <= right; i++)
                ans.push_back(mat[top][i]);

            top++;

            // For moving top to bottom.
            for (int i = top; i <= bottom; i++)
                ans.push_back(mat[i][right]);

            right--;
            
            // For moving right to left.
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.push_back(mat[bottom][i]);

                bottom--;
            }

            // For moving bottom to top.
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(mat[i][left]);

                left++;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
  
    Solution sol;
    vector<int> result = sol.spiralOrder(mat);
  
    cout << "Spiral order: "; 
    for (int i : result) { 
        cout << i << " "; 
    }
    cout << endl;

    return 0;
}