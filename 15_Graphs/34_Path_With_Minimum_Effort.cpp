/*
    1631. Path With Minimum Effort
    You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

    A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

    Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

    Example 1:
    Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
    Output: 2
    Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
    This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

    Example 2:
    Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
    Output: 1
    Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

    Example 3:
    Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
    Output: 0
    Explanation: This route does not require any effort.
    
    Constraints:

    rows == heights.length
    columns == heights[i].length
    1 <= rows, columns <= 100
    1 <= heights[i][j] <= 106
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;

        typedef pair<int, pair<int, int>> Node; // {effort, {x, y}}

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({0, {0, 0}});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            Node top = pq.top();
            pq.pop();

            int currEffort = top.first;
            int x = top.second.first;
            int y = top.second.second;

            if (x == n - 1 && y == m - 1) return currEffort;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int diff = abs(heights[nx][ny] - heights[x][y]);
                    int maxEffort = max(currEffort, diff);

                    if (maxEffort < effort[nx][ny]) {
                        effort[nx][ny] = maxEffort;
                        pq.push({maxEffort, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    int result = sol.minimumEffortPath(heights);
    cout << "Minimum Effort: " << result << endl;
    return 0;
}

// | Aspect | Value                 |
// | ------ | --------------------- |
// | Time   | `O(M * N * log(M*N))` |
// | Space  | `O(M * N)`            |
