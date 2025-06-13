/*
    48. Rotate Image
    You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

    You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

    Example 1:

    Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [[7,4,1],[8,5,2],[9,6,3]]
    Example 2:

    Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
    
    Constraints:

    n == matrix.length == matrix[i].length
    1 <= n <= 20
    -1000 <= matrix[i][j] <= 1000
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // void rotateMatrix(vector<vector<int>>& matrix) {
    //     int n = matrix.size();

    //     // Initialize a new n x n matrix filled with zeros
    //     vector<vector<int>> result(n, vector<int>(n, 0));

    //     // Perform the 90 degree rotation
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < n; j++) {
    //             result[j][n - 1 - i] = matrix[i][j];
    //         }
    //     }
        
    //     // Update the original matrix with the result
    //     matrix = result;
    // }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transposing the matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reversing each row of the matrix
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main(){
    int n;
    cout << "Enter size of the square matrix: "; 
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter elements of the matrix:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
  
    Solution sol;
    sol.rotate(matrix);

    cout << "Matrix after 90 degree rotation:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " "; 
        }
        cout << endl;
    }
}
