/*
    130. Surrounded Regions
    You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
    To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

    Example 1:
    Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
    Explanation:
    In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

    Example 2:
    Input: board = [["X"]]
    Output: [["X"]]

    Constraints:

    m == board.length
    n == board[i].length
    1 <= m, n <= 200
    board[i][j] is 'X' or 'O'.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, int m, int n) {
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O')
            return;

        board[row][col] = '#';  // Mark as safe

        dfs(row - 1, col, board, m, n);
        dfs(row + 1, col, board, m, n);
        dfs(row, col - 1, board, m, n);
        dfs(row, col + 1, board, m, n);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        // Step 1: DFS from all border 'O's
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, board, m, n);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, board, m, n);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(0, j, board, m, n);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, board, m, n);
        }

        // Step 2: Flip surrounded 'O' → 'X' and '#' → 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

// 🧪 Test the implementation
int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Before:\n";
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    sol.solve(board);

    cout << "\nAfter:\n";
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time: O(m × n) — Every cell is visited at most once
// Space: O(m × n) in worst case (for recursion stack or visited matrix)