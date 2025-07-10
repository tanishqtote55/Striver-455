/*
    Find the MST weight
    Given a weighted, undirected, and connected graph with V vertices numbered from 0 to V-1 and E edges.
    The ith edge is represented by [ai,bi,wi], where ai and bi denotes the endpoint of the edge and the wi denotes the weight of the edge.
    Find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. 
    A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

    Note : The input to the function in code editor is giving in form of adjacency list.

    Examples:
    Input: V = 4, edges = [[0, 1, 1], [1, 2, 2], [2, 3, 3], [0, 3, 4]]
    Output: 6
    Explanation: 
    Edges included in the MST:
    [0, 1, 1] with weight 1
    [1, 2, 2] with weight 2
    [2, 3, 3] with weight 3
    The total weight of the MST is 1 + 2 + 3 = 6. These edges form a spanning tree that connects all vertices (0, 1, 2, 3) with the minimum possible total edge weight, satisfying the MST properties.

    Input: V = 3, edges = [[0, 1, 5], [1, 2, 10], [2,0,15]]
    Output: 15
    Explanation: 
    Edges included in the MST:
    [0, 1, 5] with weight 5
    [1, 2, 10] with weight 10
    The total weight of the MST is 5+10 = 15
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Min-heap: {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> visited(V, false);
        int mstWeight = 0;

        // Start from node 0
        pq.push({0, 0});

        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();

            int weight = top.first;
            int node = top.second;

            if (visited[node]) continue;

            visited[node] = true;
            mstWeight += weight;

            for (int i = 0; i < adj[node].size(); ++i) {
                int adjNode = adj[node][i][0];
                int edgeWeight = adj[node][i][1];

                if (!visited[adjNode]) {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }

        return mstWeight;
    }
};

int main() {
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {0, 3, 4}
    };

    vector<vector<int>> adj[4]; // V = 4
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    Solution sol;
    cout << "MST Total Weight: " << sol.spanningTree(V, adj) << endl;  // Output: 6

    return 0;
}

// | Metric | Complexity   |
// | ------ | ------------ |
// | Time   | `O(E log V)` |
// | Space  | `O(V + E)`   |