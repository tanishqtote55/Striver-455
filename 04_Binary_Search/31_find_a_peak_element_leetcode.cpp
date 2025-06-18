/*
    1901. Find a Peak Element II
    A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

    Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

    You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

    You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

    Example 1:

    Input: mat = [[1,4],[3,2]]
    Output: [0,1]
    Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
    Example 2:

    Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
    Output: [1,1]
    Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
    
    Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 500
    1 <= mat[i][j] <= 105
    No two adjacent cells are equal.    
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int midCol = low + (high - low) / 2;
            
            // Find the row with the maximum element in this column
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }
            
            // Get the left and right neighbors
            int left = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int right = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;
            
            // Check if current element is a peak
            if (mat[maxRow][midCol] > left && mat[maxRow][midCol] > right) {
                return {maxRow, midCol};
            }
            else if (right > mat[maxRow][midCol]) {
                low = midCol + 1;  // search right half
            }
            else {
                high = midCol - 1; // search left half
            }
        }
        
        return {-1, -1}; // shouldn't reach here based on problem constraints
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    vector<int> peak = sol.findPeakGrid(mat);
    cout << "Peak found at: [" << peak[0] << ", " << peak[1] << "]" << endl;
    return 0;
}