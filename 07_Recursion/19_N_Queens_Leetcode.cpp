/*
    51. N-Queens
    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

    Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

    Example 1:

    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
    Example 2:

    Input: n = 1
    Output: [["Q"]]

    Constraints:

    1 <= n <= 9
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // bool isSafe(int row, int col, vector<string> &board, int n){
    //     // check upper diagonal
    //     int duprow = row;
    //     int dupcol = col;
    //     while(row >= 0 && col >= 0){
    //         if(board[row][col] == 'Q') return false;
    //         row--;
    //         col--;
    //     }
    //     // check the same row
    //     col = dupcol;
    //     row = duprow;
    //     while(col >= 0){
    //         if(board[row][col] == 'Q') return false;
    //         col--;
    //     }
    //     // check lower diagonal
    //     row = duprow;
    //     col = dupcol;
    //     while(row < n && col >= 0){
    //         if(board[row][col] == 'Q') return false;
    //         row++;
    //         col--;
    //     }

    //     return true;
    // }
    // void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    //     if(col == n){
    //         ans.push_back(board);
    //         return;
    //     }
    //     for(int row = 0; row < n; row++){
    //         if(isSafe(row, col, board, n)){
    //             board[row][col] = 'Q';
    //             solve(col + 1, board, ans, n);
    //             board[row][col] = '.';
    //         }
    //     }
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>> ans;   
    //     vector<string> board(n);
    //     string s(n, '.');
    //     for(int i = 0; i < n; i++) {
    //         board[i] = s;
    //     }
    //     solve(0, board, ans, n);
    //     return ans;
    // }

    void solve(int col, int n, vector<string> &board,
               vector<vector<string>> &ans,
               vector<int> &rows, vector<int> &diag1, vector<int> &diag2) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (rows[row] || diag1[row + col] || diag2[row - col + n - 1])
                continue;

            // Place the queen
            board[row][col] = 'Q';
            rows[row] = diag1[row + col] = diag2[row - col + n - 1] = 1;

            solve(col + 1, n, board, ans, rows, diag1, diag2);

            // Backtrack
            board[row][col] = '.';
            rows[row] = diag1[row + col] = diag2[row - col + n - 1] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> rows(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);
        solve(0, n, board, ans, rows, diag1, diag2);
        return ans;
    }
};

// Main to test
int main() {
    Solution sol;
    int n = 4;
    vector<vector<string>> solutions = sol.solveNQueens(n);

    for (const auto &board : solutions) {
        for (const string &row : board) {
            cout << row << endl;
        }
        cout << "----" << endl;
    }

    return 0;
}

// Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).

// Space Complexity: O(N)