/*
    Articulation point in graph
    Given an undirected graph with V vertices and adjacency list adj. Find all the vertices removing which (and edges through it) would increase the number of connected components in the graph. The graph may be initially disconnected.. Return the vertices in ascending order. If there are no such vertices then returns a list containing -1.

    Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

    Examples:
    Input: V = 7, adj=[[1,2,3], [0], [0,3,4,5], [2,0], [2,6], [2,6], [4,5]] 
    Output: [0, 2]
    Explanation: If we remove node 0 or node 2, the graph will be divided into 2 or more components.

    Input: V = 5, adj=[[1], [0,4], [3,4], [2,4], [1,2,3]] 
    Output: [1, 4]
    Explanation: If we remove either node 1 or node 4, the graph breaks into multiple components.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<bool>& visited, set<int>& ap, int& timer) {
        visited[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!visited[v]) {
                children++;
                dfs(v, u, adj, disc, low, visited, ap, timer);

                // Update low[u]
                low[u] = min(low[u], low[v]);

                // Check articulation point
                if (parent != -1 && low[v] >= disc[u])
                    ap.insert(u);
            } else {
                // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }

        // Special case for root
        if (parent == -1 && children > 1)
            ap.insert(u);
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false);
        set<int> ap;  // use set for uniqueness and sorted order
        int timer = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, adj, disc, low, visited, ap, timer);
            }
        }

        if (ap.empty()) return {-1};
        return vector<int>(ap.begin(), ap.end());
    }
};
int main() {
    int V = 7;
    vector<int> adj[7] = {
        {1, 2, 3},    // 0
        {0},          // 1
        {0, 3, 4, 5}, // 2
        {2, 0},       // 3
        {2, 6},       // 4
        {2, 6},       // 5
        {4, 5}        // 6
    };

    Solution sol;
    vector<int> result = sol.articulationPoints(V, adj);

    cout << "Articulation Points: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}

// Time: O(V + E) — standard DFS
// Space: O(V) — for visited, disc, low arrays