/*
    Shortest path in DAG

    Given a Directed Acyclic Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a directed edge from vertex edge[i][0] to vertex edge[i][1] with a distance of edge[i][2] for all i.

    Find the shortest path from source vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex. The source vertex is assumed to be 0.

    Examples:
    Input: N = 4, M = 2 edge = [[0,1,2],[0,2,1]]
    Output: 0 2 1 -1
    Explanation:
    Shortest path from 0 to 1 is 0->1 with edge weight 2. 
    Shortest path from 0 to 2 is 0->2 with edge weight 1.
    There is no way we can reach 3, so it's -1 for 3.

    Input: N = 6, M = 7 edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
    Output: 0 2 3 6 1 5
    Explanation:
    Shortest path from 0 to 1 is 0->1 with edge weight 2. 
    Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
    Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
    Shortest path from 0 to 4 is 0->4 with edge weight 1.
    Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
using namespace std;

class Solution {
public:
    void topoSort(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto& it : adj[node]) {
            int v = it.first;
            if (!vis[v])
                topoSort(v, adj, vis, st);
        }
        st.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // Step 1: Create adjacency list
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Topological sort
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!vis[i])
                topoSort(i, adj, vis, st);
        }

        // Step 3: Initialize distance array
        vector<int> dist(N, 1e9);
        dist[0] = 0;

        // Step 4: Relax edges in topological order
        while (!st.empty()) {
            int u = st.top(); st.pop();
            if (dist[u] != 1e9) {
                for (auto& it : adj[u]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // Step 5: Convert unreachable (INF) distances to -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};

void printVector(const vector<int>& v) {
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1
    int N1 = 4, M1 = 2;
    vector<vector<int>> edges1 = {{0, 1, 2}, {0, 2, 1}};
    vector<int> result1 = sol.shortestPath(N1, M1, edges1);
    cout << "Example 1 Output: ";
    printVector(result1); // Expected: 0 2 1 -1

    // Example 2
    int N2 = 6, M2 = 7;
    vector<vector<int>> edges2 = {
        {0, 1, 2}, {0, 4, 1}, {4, 5, 4},
        {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}
    };
    vector<int> result2 = sol.shortestPath(N2, M2, edges2);
    cout << "Example 2 Output: ";
    printVector(result2); // Expected: 0 2 3 6 1 5

    return 0;
}

// Time: O(N + M) – topological sort + relaxation

// Space: O(N + M) – for adjacency list and stack