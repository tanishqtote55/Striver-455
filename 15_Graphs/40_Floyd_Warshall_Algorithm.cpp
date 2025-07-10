/*
    Floyd warshall algorithm

    Given a graph of V vertices numbered from 0 to V-1. Find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n x n. Matrix[i][j] denotes the weight of the edge from i to j. If matrix[i][j]=-1, it means there is no edge from i to j.

    Examples:
    Input: matrix = [[0, 2, -1, -1],[1, 0, 3, -1],[-1, -1, 0, 1],[3, 5, 4, 0]]
    Output: [[0, 2, 5, 6], [1, 0, 3, 4], [4, 6, 0, 1], [3, 5, 4, 0]] 
    Explanation: matrix[0][0] is storing the distance from vertex 0 to vertex 0, the distance from vertex 0 to vertex 1 is 2 and so on.

    Input: matrix = [[0,25],[-1,0]]
    Output: [[0, 25],[-1, 0]]
    Explanation: The matrix already contains the shortest distance.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void shortestDistance(vector<vector<int>>& matrix) {
        int n = matrix.size();
        const int INF = 1e9;

        // Step 1: Replace -1 with INF for no connection (except diagonal)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == -1 && i != j) {
                    matrix[i][j] = INF;
                }
            }
        }

        // Step 2: Apply Floyd-Warshall Algorithm
        for (int via = 0; via < n; ++via) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][via] < INF && matrix[via][j] < INF) {
                        matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                    }
                }
            }
        }

        // Step 3: Replace INF back with -1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == INF) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {0, 2, -1, -1},
        {1, 0, 3, -1},
        {-1, -1, 0, 1},
        {3, 5, 4, 0}
    };

    sol.shortestDistance(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

// | Metric | Value           |
// | ------ | --------------- |
// | Time   | O(V³)           |
// | Space  | O(1) (in-place) |