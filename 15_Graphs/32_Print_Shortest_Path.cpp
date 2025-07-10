#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dijkstra(int V, vector<vector<int>> adj[], int S, vector<int>& dist, vector<int>& parent) {
        dist.assign(V, 1e9);
        parent.assign(V, -1);
        dist[S] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (int i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i][0];
                int weight = adj[u][i][1];

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;  // Track the path
                    pq.push({dist[v], v});
                }
            }
        }
    }

    vector<int> reconstructPath(int target, vector<int>& parent) {
        vector<int> path;
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    Solution sol;

    int V = 5;
    vector<vector<int>> adj[5];

    // Graph: 0 -> 1 (2), 0 -> 2 (4), 1 -> 2 (1), 1 -> 3 (7), 2 -> 4 (3), 3 -> 4 (1)
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    int S = 0; // Source
    vector<int> dist, parent;

    sol.dijkstra(V, adj, S, dist, parent);

    for (int i = 0; i < V; ++i) {
        cout << "Shortest distance from " << S << " to " << i << ": " << dist[i] << endl;
        cout << "Path: ";
        vector<int> path = sol.reconstructPath(i, parent);
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl << endl;
    }

    return 0;
}
