/*
    Bellman ford algorithm
    Given a weighted and directed graph of V vertices and E edges. An edge is represented as [ai, bi, wi], meaning there is a directed edge from ai to bi having weight wi. Find the shortest distance of all the vertices from the source vertex S. If a vertex can't be reached from the S then mark the distance as 109.

    If the graph contains a negative cycle then return -1 in a list.

    Examples:
    Input : V = 6, Edges = [[3, 2, 6], [5, 3, 1], [0, 1, 5], [1, 5, -3], [1, 2, -2], [3, 4, -2], [2, 4, 3]], S = 0
    Output: 0 5 3 3 1 2
    Explanation:
    For node 1, shortest path is 0->1 (distance=5).
    For node 2, shortest path is 0->1->2 (distance=3)
    For node 3, shortest path is 0->1->5->3 (distance=3)
    For node 4, shortest path is 0->1->5->3->4 (distance=1)
    For node 5, shortest path is 0->1->5 (distance=2)

    Input : V = 2, Edges = [[0,1,9]], S = 0
    Output: 0 9
    Explanation: For node 1, the shortest path is 0->1 (distance=9)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        const int INF = 1e9;
        vector<int> dist(V, INF);
        dist[S] = 0;

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; ++i) {
            for (const vector<int>& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if (dist[u] != INF && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycle
        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                return {-1};  // Negative cycle detected
            }
        }
        return dist;
    }
};

int main() {
    Solution sol;
    int V = 6;
    vector<vector<int>> edges = {
        {3, 2, 6}, {5, 3, 1}, {0, 1, 5},
        {1, 5, -3}, {1, 2, -2}, {3, 4, -2}, {2, 4, 3}
    };
    int source = 0;
    vector<int> result = sol.bellman_ford(V, edges, source);

    if (result.size() == 1 && result[0] == -1) {
        cout << "Negative cycle detected\n";
    } else {
        for (int d : result) {
            cout << d << " ";
        }
        cout << endl;
    }

    return 0;
}

// | Metric | Complexity |
// | ------ | ---------- |
// | Time   | O(V × E)   |
// | Space  | O(V)       |