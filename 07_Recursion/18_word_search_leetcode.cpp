/*
    79. Word Search
    Given an m x n grid of characters board and a string word, return true if word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

    Example 1:

    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true
    Example 2:

    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    Output: true
    Example 3:

    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
    Output: false
    
    Constraints:

    m == board.length
    n = board[i].length
    1 <= m, n <= 6
    1 <= word.length <= 15
    board and word consists of only lowercase and uppercase English letters.
    
    Follow up: Could you use search pruning to make your solution faster with a larger board?
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, int index, string& word) {
        // Base case: if full word is matched
        if(index == word.length()) return true;

        // Boundary & character check
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
            return false;

        // Mark as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        bool found = dfs(board, i+1, j, index+1, word) ||
                     dfs(board, i-1, j, index+1, word) ||
                     dfs(board, i, j+1, index+1, word) ||
                     dfs(board, i, j-1, index+1, word);

        // Backtrack
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == word[0]){
                    if(dfs(board, i, j, 0, word)) return true;
                }
            }
        }
        return false;
    }
};

// Main for testing
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    
    string word1 = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";

    cout << "Word: " << word1 << " -> " << (sol.exist(board, word1) ? "true" : "false") << endl;
    cout << "Word: " << word2 << " -> " << (sol.exist(board, word2) ? "true" : "false") << endl;
    cout << "Word: " << word3 << " -> " << (sol.exist(board, word3) ? "true" : "false") << endl;

    return 0;
}
