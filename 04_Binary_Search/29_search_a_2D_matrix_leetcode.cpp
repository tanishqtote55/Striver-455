/*
    74. Search a 2D Matrix
    You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.

    Example 1:

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true
    Example 2:

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false

    Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104
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
    //         if(matrix[i][n - 1] >= target){
    //             for(int j = 0; j < n; j++){
    //                 if(matrix[i][j] == target){
    //                     return true;
    //                 }
    //             }
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
    //     int m = matrix[0].size();

    //     for (int i = 0; i < n; i++) {
    //         if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
    //             return binarySearch(matrix[i], target);
    //         }
    //     }
    //     return false;
    // }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    
    int target = 3;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " NOT found in the matrix." << endl;
    }

    return 0;
}
