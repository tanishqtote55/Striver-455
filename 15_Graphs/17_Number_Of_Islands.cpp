/*
    Number of distinct islands
    Given a boolean 2D matrix grid of size N x M. Find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be same if and only if one island is equal to another (not rotated or reflected).

    Examples:
    Input: grid = [[1, 1, 0, 0, 0], [1, 1, 0, 0, 0], [0, 0, 0, 1, 1],[0, 0, 0, 1, 1]]
    Output: 1
    Explanation:
    Same colored islands are equal. We have 2 equal islands, so we have only 1 distinct island.

    Input: grid = [[1, 1, 0, 1, 1], [1, 0, 0, 0, 0], [0, 0, 0, 0, 1],[1, 1, 0, 1, 1]]
    Output: 3
    Explanation:
    Same colored islands are equal. We have 4 islands, but 2 of them are equal, So we have 3 distinct islands..
*/
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited,
             int baseRow, int baseCol, vector<pair<int, int>> &shape, int m, int n)
    {
        if (row < 0 || row >= m || col < 0 || col >= n ||
            grid[row][col] == 0 || visited[row][col])
            return;

        visited[row][col] = true;
        shape.push_back(make_pair(row - baseRow, col - baseCol));  // relative position

        dfs(row - 1, col, grid, visited, baseRow, baseCol, shape, m, n); // up
        dfs(row + 1, col, grid, visited, baseRow, baseCol, shape, m, n); // down
        dfs(row, col - 1, grid, visited, baseRow, baseCol, shape, m, n); // left
        dfs(row, col + 1, grid, visited, baseRow, baseCol, shape, m, n); // right
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        set<vector<pair<int, int>>> uniqueShapes;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    vector<pair<int, int>> shape;
                    dfs(i, j, grid, visited, i, j, shape, m, n);
                    uniqueShapes.insert(shape);  // insert normalized shape
                }
            }
        }

        return uniqueShapes.size();
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    vector<vector<int>> grid2 = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };

    cout << "Distinct Islands in grid1: " << sol.countDistinctIslands(grid1) << endl;
    cout << "Distinct Islands in grid2: " << sol.countDistinctIslands(grid2) << endl;

    return 0;
}

// | Component | Complexity                                       |
// | --------- | ------------------------------------------------ |
// | **Time**  | `O(m * n * logK)` where `K` is number of islands |
// | **Space** | `O(m * n)` for visited + shape set               |
