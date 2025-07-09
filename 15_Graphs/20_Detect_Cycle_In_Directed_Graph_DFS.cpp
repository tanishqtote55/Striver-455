/*
    Detect a cycle in a directed graph

    Given a directed graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph contains any cycles.

    Examples:
    Input: V = 6, adj= [ [1], [2, 5], [3], [4], [1], [ ] ]
    Output: True
    Explanation: The graph contains a cycle: 1 -> 2 -> 3 -> 4 -> 1.

    Input: V = 4, adj= [[1,2], [2], [], [0,2]]
    Output: False
    Explanation: The graph does not contain a cycle.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<bool>& vis, vector<bool>& pathVis) {
        vis[node] = true;
        pathVis[node] = true;

        for (int i = 0; i < adj[node].size(); ++i) {
            int neighbor = adj[node][i];

            if (!vis[neighbor]) {
                if (dfs(neighbor, adj, vis, pathVis)) return true;
            } else if (pathVis[neighbor]) {
                return true; // Cycle found (back edge)
            }
        }

        pathVis[node] = false; // Backtrack
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> pathVis(V, false);

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    int V1 = 6;
    vector<int> adj1[6] = {
        {1},      // 0
        {2, 5},   // 1
        {3},      // 2
        {4},      // 3
        {1},      // 4
        {}        // 5
    };

    cout << "Graph 1 has cycle? " << (sol.isCyclic(V1, adj1) ? "Yes" : "No") << endl;

    int V2 = 4;
    vector<int> adj2[4] = {
        {1, 2},   // 0
        {2},      // 1
        {},       // 2
        {0, 2}    // 3
    };

    cout << "Graph 2 has cycle? " << (sol.isCyclic(V2, adj2) ? "Yes" : "No") << endl;

    return 0;
}

// | Metric           | Value    |                                |
// | ---------------- | -------- | ------------------------------ |
// | Time Complexity  | O(V + E) |                                |
// | Space Complexity | O(V)     | (for `visited` and `recStack`) |
