/*
    1091. Shortest Path in Binary Matrix
    Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

    A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
    The length of a clear path is the number of visited cells of this path.

    Example 1:
    Input: grid = [[0,1],[1,0]]
    Output: 2

    Example 2:
    Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
    Output: 4

    Example 3:
    Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
    Output: -1
    
    Constraints:

    n == grid.length
    n == grid[i].length
    1 <= n <= 100
    grid[i][j] is 0 or 1
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    // | Complexity | Value                                                                                              |
    // | ---------- | -------------------------------------------------------------------------------------------------- |
    // | **Time**   | `O(n^2 * log(n^2))` = `O(n^2 log n)` since we process each of the `n²` cells with a heap operation |
    // | **Space**  | `O(n^2)` — for `dist[][]` and the priority queue                                                   |
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;

        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> pq;

        pq.push({1, {0, 0}});

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int x = top.second.first;
            int y = top.second.second;

            if (x == n - 1 && y == n - 1) return d;

            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    if (d + 1 < dist[nx][ny]) {
                        dist[nx][ny] = d + 1;
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If starting or ending cell is blocked
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        // 8 directions (dx, dy)
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // Use grid itself to store distance from (0, 0)

        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();

            int x = cell.first;
            int y = cell.second;
            int dist = grid[x][y];

            if (x == n - 1 && y == n - 1)
                return dist;

            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    q.push({nx, ny});
                    grid[nx][ny] = dist + 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };

    int result = sol.shortestPathBinaryMatrix(grid);
    cout << "Shortest path length: " << result << endl;
    return 0;
}

// Time Complexity: O(n^2)
// → At most, all n*n cells are visited once.
// Space Complexity: O(n^2)
// → Due to the queue and input matrix (which we reuse for visited status).

