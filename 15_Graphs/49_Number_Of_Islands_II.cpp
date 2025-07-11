/*
    Number of islands II
    Given n, m denoting the row and column of the 2D matrix, and an array A of size k denoting the number of operations. Matrix elements are 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integers A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many islands are there in the matrix after each operation.

    The answer array will be of size k.

    Examples:
    Input: n = 4, m = 5, k = 4, A = [[1,1],[0,1],[3,3],[3,4]] 
    Output: [1, 1, 2, 2]
    Explanation: The following illustration is the representation of the operation:

    Input: n = 4, m = 5, k = 12, A = [[0,0],[0,0],[1,1],[1,0],[0,1],[0,3],[1,3],[0,4], [3,2], [2,2],[1,2], [0,2]] 
    Output: [1, 1, 2, 1, 1, 2, 2, 2, 3, 3, 1, 1] 
    Explanation: If we follow the process like in example 1, we will get the above result.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }
    
    int findParent(int u) {
        if (u == parent[u])
            return u;
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
};

class Solution {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A) {
        DisjointSet ds(n * m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> res;

        int count = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for (auto &op : A) {
            int row = op[0], col = op[1];
            if (vis[row][col] == 1) {
                res.push_back(count);
                continue;
            }

            vis[row][col] = 1;
            count++;

            int node = row * m + col;

            for (int i = 0; i < 4; ++i) {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    if (vis[newRow][newCol] == 1) {
                        int adjNode = newRow * m + newCol;
                        if (ds.findParent(node) != ds.findParent(adjNode)) {
                            ds.unionBySize(node, adjNode);
                            count--;
                        }
                    }
                }
            }
            res.push_back(count);
        }

        return res;
    }
};
int main() {
    Solution sol;
    int n = 4, m = 5;
    vector<vector<int>> A = {{0,0},{0,0},{1,1},{1,0},{0,1},{0,3},{1,3},{0,4},{3,2},{2,2},{1,2},{0,2}};
    vector<int> ans = sol.numOfIslands(n, m, A);
    for (int x : ans) cout << x << " ";
    return 0;
}



// Time: O(K * 4 * α(N)) ~ O(K), where K = number of operations, N = n × m, α is inverse Ackermann.
// Space: O(N) for DSU and visited matrix.