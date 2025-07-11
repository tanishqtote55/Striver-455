/*
    1192. Critical Connections in a Network
    There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
    A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
    Return all critical connections in the network in any order.

    Example 1:
    Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
    Output: [[1,3]]
    Explanation: [[3,1]] is also accepted.

    Example 2:
    Input: n = 2, connections = [[0,1]]
    Output: [[0,1]]
 
    Constraints:

    2 <= n <= 105
    n - 1 <= connections.length <= 105
    0 <= ai, bi <= n - 1
    ai != bi
    There are no repeated connections.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> disc, low;
    vector<vector<int>> adj;
    int time = 0;

    void dfs(int u, int parent) {
        disc[u] = low[u] = time++;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (disc[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    result.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        disc.assign(n, -1);
        low.assign(n, -1);

        for (const auto& edge : connections) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1);
        return result;
    }
};
int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    vector<vector<int>> res = sol.criticalConnections(n, connections);

    cout << "Critical Connections:\n";
    for (const auto& edge : res) {
        cout << "[" << edge[0] << ", " << edge[1] << "]\n";
    }

    return 0;
}

// Time: O(N + E) — DFS traversal over the graph.
// Space: O(N + E) — Adjacency list and recursion stack.