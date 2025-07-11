/*
    778. Swim in Rising Water
    You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
    The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
    Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

    Example 1:
    Input: grid = [[0,2],[1,3]]
    Output: 3
    Explanation:
    At time 0, you are in grid location (0, 0).
    You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
    You cannot reach point (1, 1) until time 3.
    When the depth of water is 3, we can swim anywhere inside the grid.

    Example 2:
    Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
    Output: 16
    Explanation: The final route is shown.
    We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
    
    Constraints:
    n == grid.length
    n == grid[i].length
    1 <= n <= 50
    0 <= grid[i][j] < n2
    Each value grid[i][j] is unique.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // Min heap: stores {time, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int time = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (x == n - 1 && y == n - 1) {
                return time;
            }

            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    pq.push({max(time, grid[nx][ny]), nx, ny});
                }
            }
        }

        return -1; // should not reach here
    }
};

// ---------- Sample Main Function ----------
int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {0, 2},
        {1, 3}
    };

    vector<vector<int>> grid2 = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6}
    };

    cout << "Output for grid1: " << sol.swimInWater(grid1) << endl;
    cout << "Output for grid2: " << sol.swimInWater(grid2) << endl;

    return 0;
}

// Time Complexity: O(N^2 * log(N^2)) — each cell pushed once into the priority queue.
// Space Complexity: O(N^2) for the visited matrix and priority queue.