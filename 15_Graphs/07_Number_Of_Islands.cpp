/*
    Connected Components
    Given a undirected Graph consisting of V vertices numbered from 0 to V-1 and E edges. The ith edge is represented by [ai,bi], denoting a edge between vertex ai and bi. We say two vertices u and v belong to a same component if there is a path from u to v or v to u. Find the number of connected components in the graph.

    A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

    Examples:
    Input: V=4, edges=[[0,1],[1,2]]
    Output: 2
    Explanation: Vertices {0,1,2} forms the first component and vertex 3 forms the second component.

    Input: V = 7, edges = [[0, 1], [1, 2], [2, 3], [4, 5]]
    Output: 3
    Explanation:
    The edges [0, 1], [1, 2], [2, 3] form a connected component with vertices {0, 1, 2, 3}.
    The edge [4, 5] forms another connected component with vertices {4, 5}.
    Therefore, the graph has 3 connected components: {0, 1, 2, 3}, {4, 5}, and the isolated vertices {6} (vertices 6 and any other unconnected vertices).
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);  // Adjacency list

        // Build the graph
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        int components = 0;

        // Run DFS for each unvisited node
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                components++;
            }
        }

        return components;
    }
};

// Sample usage
int main() {
    Solution sol;

    int V1 = 4;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}};
    cout << "Number of Components: " << sol.findNumberOfComponent(V1, edges1) << endl; // Output: 2

    int V2 = 7;
    vector<vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
    cout << "Number of Components: " << sol.findNumberOfComponent(V2, edges2) << endl; // Output: 3

    return 0;
}

// Time Complexity: O(V + E)
// DFS visits each vertex and edge once.

// Space Complexity: O(V + E)
// For the adjacency list and visited array.