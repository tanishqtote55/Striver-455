/*
    827. Making A Large Island
    You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
    Return the size of the largest island in grid after applying this operation.
    An island is a 4-directionally connected group of 1s.

    Example 1:
    Input: grid = [[1,0],[0,1]]
    Output: 3
    Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

    Example 2:
    Input: grid = [[1,1],[1,0]]
    Output: 4
    Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

    Example 3:
    Input: grid = [[1,1],[1,1]]
    Output: 4
    Explanation: Can't change any 0 to 1, only one island with area = 4.

    Constraints:

    n == grid.length
    n == grid[i].length
    1 <= n <= 500
    grid[i][j] is either 0 or 1.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int findParent(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int getSize(int u) {
        return size[findParent(u)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        // Step 1: Union all adjacent 1s
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int currId = i * n + j;
                    for (auto& d : dir) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            int nextId = ni * n + nj;
                            ds.unionBySize(currId, nextId);
                        }
                    }
                }
            }
        }

        // Step 2: Try flipping each 0
        int maxIsland = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIslands;
                    int area = 1;

                    for (auto& d : dir) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            int id = ds.findParent(ni * n + nj);
                            if (uniqueIslands.find(id) == uniqueIslands.end()) {
                                area += ds.getSize(id);
                                uniqueIslands.insert(id);
                            }
                        }
                    }
                    maxIsland = max(maxIsland, area);
                }
            }
        }

        // Step 3: Edge case - no zero in grid
        for (int i = 0; i < n * n; ++i) {
            maxIsland = max(maxIsland, ds.getSize(i));
        }

        return maxIsland;
    }
};
int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{1, 0}, {0, 1}};
    cout << "Output 1: " << sol.largestIsland(grid1) << endl; // Expected: 3

    vector<vector<int>> grid2 = {{1, 1}, {1, 0}};
    cout << "Output 2: " << sol.largestIsland(grid2) << endl; // Expected: 4

    vector<vector<int>> grid3 = {{1, 1}, {1, 1}};
    cout << "Output 3: " << sol.largestIsland(grid3) << endl; // Expected: 4

    return 0;
}
// Time: O(N² * α(N²)) ≈ O(N²), due to DSU operations and 4-direction checks per cell.
// Space: O(N²) for DSU arrays and visited cell info.