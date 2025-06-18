/*
    240. Search a 2D Matrix II
    Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.
    
    Example 1:

    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
    Output: true
    Example 2:

    Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
    Output: false
    
    Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= n, m <= 300
    -109 <= matrix[i][j] <= 109
    All the integers in each row are sorted in ascending order.
    All the integers in each column are sorted in ascending order.
    -109 <= target <= 109
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     for(int i = 0; i < m; i++){
    //         if(matrix[i][0] <= target && matrix[i][n - 1] >= target){
    //             for(int j = 0; j < n; j++){
    //                 if(matrix[i][j] == target) return true;
    //             }
    //         }else{
    //             continue;
    //         }
    //     }
    //     return false;
    // }

    // bool binarySearch(vector<int>& nums, int target) {
    //     int n = nums.size(); //size of the array
    //     int low = 0, high = n - 1;
    //     // Perform the steps:
    //     while (low <= high) {
    //         int mid = (low + high) / 2;
    //         if (nums[mid] == target) return true;
    //         else if (target > nums[mid]) low = mid + 1;
    //         else high = mid - 1;
    //     }
    //     return false;
    // }
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n = matrix.size();
    //     for (int i = 0; i < n; i++) {
    //         bool flag =  binarySearch(matrix[i], target);
    //         if (flag) return true;
    //     }
    //     return false;
    // }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        
        int row = 0, col = n - 1;  // start from top-right
        while (row < m && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;  // move left
            else
                row++;  // move down
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix1 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target1 = 5;
    int target2 = 20;

    cout << "Searching for " << target1 << ": " 
         << (sol.searchMatrix(matrix1, target1) ? "Found" : "Not Found") << endl;

    cout << "Searching for " << target2 << ": " 
         << (sol.searchMatrix(matrix1, target2) ? "Found" : "Not Found") << endl;

    return 0;
}