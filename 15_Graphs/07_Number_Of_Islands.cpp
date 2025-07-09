// Problem: Number of Islands
// Given a 2D grid of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void bfs(int startRow, int startCol, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(startRow, startCol));
        visited[startRow][startCol] = true;

        // 8 directions
        int drow[] = {-1, -1, -1,  0, 0, 1, 1, 1};
        int dcol[] = {-1,  0,  1, -1, 1,-1, 0, 1};

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            int row = current.first;
            int col = current.second;

            for (int i = 0; i < 8; ++i) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    if (grid[newRow][newCol] == '1' && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        q.push(make_pair(newRow, newCol));
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    bfs(row, col, grid, visited);
                    count++;
                }
            }
        }

        return count;
    }
};

// Sample usage
int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'0', '1', '0', '0', '1'},
        {'1', '0', '0', '1', '1'},
        {'0', '0', '0', '0', '0'},
        {'1', '0', '1', '0', '1'}
    };

    cout << "Number of Islands (BFS, 8-direction): " << sol.numIslands(grid) << endl;
    return 0;
}


// | Component | Complexity |
// | --------- | ---------- |
// | **Time**  | `O(N × M)` |
// | **Space** | `O(N × M)` |
