/*
    542. 01 Matrix
    Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

    The distance between two cells sharing a common edge is 1.

    Example 1:
    Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
    Output: [[0,0,0],[0,1,0],[0,0,0]]

    Example 2:
    Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
    Output: [[0,0,0],[0,1,0],[1,2,1]]
    
    Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.
    
    Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Step 1: Add all 0s to the queue and set distance = 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        // Step 2: BFS
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            int row = current.first;
            int col = current.second;

            for (int i = 0; i < 4; ++i) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    if (dist[newRow][newCol] > dist[row][col] + 1) {
                        dist[newRow][newCol] = dist[row][col] + 1;
                        q.push(make_pair(newRow, newCol));
                    }
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> result = sol.updateMatrix(mat);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(m × n)
// Every cell is processed once.

// Space Complexity: O(m × n)
// For distance matrix and queue.