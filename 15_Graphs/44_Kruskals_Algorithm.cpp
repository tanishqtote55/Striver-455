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

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<vector<int>> edges;

        // Convert adjacency list to edge list
        for (int u = 0; u < V; ++u) {
            for (auto &nei : adj[u]) {
                int v = nei[0];
                int wt = nei[1];
                if (u < v) // avoid duplicates (undirected graph)
                    edges.push_back({wt, u, v});
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        int mstWeight = 0;

        for (auto &edge : edges) {
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (ds.findParent(u) != ds.findParent(v)) {
                ds.unionByRank(u, v);
                mstWeight += wt;
            }
        }

        return mstWeight;
    }
};

int main() {
    int V = 4;
    vector<vector<int>> adj[4];

    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});
    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 3});
    adj[3].push_back({2, 3});
    adj[0].push_back({3, 4});
    adj[3].push_back({0, 4});

    Solution sol;
    int mstWeight = sol.spanningTree(V, adj);
    cout << "MST Weight: " << mstWeight << endl; // Output: 6
}

// | Operation | Complexity     |
// | --------- | -------------- |
// | Time      | O(E log E)     |
// | Space     | O(V) (for DSU) |