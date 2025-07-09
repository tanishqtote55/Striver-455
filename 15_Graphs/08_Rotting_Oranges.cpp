/*
    994. Rotting Oranges
    You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

    Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

    Example 1:
    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4

    Example 2:
    Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
    Output: -1
    Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
    
    Example 3:
    Input: grid = [[0,2]]
    Output: 0
    Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

    Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;  // ((row, col), time)
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int freshCount = 0;

        // Step 1: Push all rotten oranges into queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(make_pair(i, j), 0));
                    visited[i][j] = true;
                }
                if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};
        int timeElapsed = 0;
        int rottedCount = 0;

        // Step 2: BFS to rot adjacent oranges
        while (!q.empty()) {
            pair<pair<int, int>, int> current = q.front();
            q.pop();
            int row = current.first.first;
            int col = current.first.second;
            int time = current.second;

            timeElapsed = max(timeElapsed, time);

            for (int i = 0; i < 4; ++i) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    if (grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        q.push(make_pair(make_pair(newRow, newCol), time + 1));
                        rottedCount++;
                    }
                }
            }
        }

        if (rottedCount != freshCount) return -1;
        return timeElapsed;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    vector<vector<int>> grid2 = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1}
    };

    vector<vector<int>> grid3 = {
        {0, 2}
    };

    cout << "Output 1: " << sol.orangesRotting(grid1) << endl;  // Expected: 4
    cout << "Output 2: " << sol.orangesRotting(grid2) << endl;  // Expected: -1
    cout << "Output 3: " << sol.orangesRotting(grid3) << endl;  // Expected: 0

    return 0;
}


// Time Complexity: O(m × n)
// (each cell is visited once at most)

// Space Complexity: O(m × n)
// (queue + visited matrix)