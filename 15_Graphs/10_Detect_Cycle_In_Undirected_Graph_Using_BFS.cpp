/*
    Detect a cycle in an undirected graph
    Given an undirected graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph contains any cycles.
    Note: The graph does not contain any self-edges (edges where a vertex is connected to itself).

    Examples:
    Input: V = 6, adj= [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]
    Output: True
    Explanation: The graph contains a cycle: 0 ->1 -> 2 -> 5 -> 4 -> 1.

    Input: V = 4, adj= [[1, 2], [0], [0, 3], [2]]
    Output: False
    Explanation: The graph does not contain any cycles.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool bfs(int start, vector<int> adj[], vector<bool> &visited) {
        queue<pair<int, int>> q;
        visited[start] = true;
        q.push(make_pair(start, -1));  // (node, parent)

        while (!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();

            int node = front.first;
            int parent = front.second;

            for (int i = 0; i < adj[node].size(); ++i) {
                int neighbor = adj[node][i];

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(make_pair(neighbor, node));
                }
                else if (neighbor != parent) {
                    return true;  // Found a back-edge — cycle detected
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (bfs(i, adj, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    int V = 6;
    vector<int> adj[6];

    // Edges: [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]
    adj[0].push_back(1); adj[0].push_back(3);
    adj[1].push_back(0); adj[1].push_back(2); adj[1].push_back(4);
    adj[2].push_back(1); adj[2].push_back(5);
    adj[3].push_back(0); adj[3].push_back(4);
    adj[4].push_back(1); adj[4].push_back(3); adj[4].push_back(5);
    adj[5].push_back(2); adj[5].push_back(4);

    bool hasCycle = sol.isCycle(V, adj);
    cout << "Graph contains cycle? " << (hasCycle ? "Yes" : "No") << endl;

    return 0;
}


// Time: O(V + E)
// Each node and edge is visited once in BFS.

// Space: O(V)
// For visited array and queue.