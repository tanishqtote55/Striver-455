/*
    118. Pascal's Triangle
    Given an integer numRows, return the first numRows of Pascal's triangle.

    In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

    Example 1:

    Input: numRows = 5
    Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
    Example 2:

    Input: numRows = 1
    Output: [[1]]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // vector<vector<int>> generate(int numRows) {
    //     vector<vector<int>> result(numRows);
        
    //     for(int i = 0; i < numRows; i++) {
    //         result[i].resize(i + 1);
    //         result[i][0] = 1;
    //         result[i][i] = 1;
    //         for(int j = 1; j < i; j++) {
    //             result[i][j] = result[i-1][j-1] + result[i-1][j];
    //         }
    //     }
        
    //     return result;
    // }


    int nCr(int n, int r) {
        long long res = 1;

        // calculating nCr:
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return (int)(res);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        //Store the entire pascal's triangle:
        for (int row = 1; row <= numRows; row++) {
            vector<int> tempLst; // temporary list
            for (int col = 1; col <= row; col++) {
                tempLst.push_back(nCr(row - 1, col - 1));
            }
            ans.push_back(tempLst);
        }
        return ans;
    }
};

int main() {
    int numRows;
    cout << "Enter number of rows: "; 
    cin >> numRows;

    Solution sol;
    vector<vector<int>> pascal = sol.generate(numRows);

    cout << "Pascal's Triangle:" << endl;
    for (auto row : pascal) {
        for (auto val : row) {
            cout << val << " "; 
        }
        cout << endl;
    }
}