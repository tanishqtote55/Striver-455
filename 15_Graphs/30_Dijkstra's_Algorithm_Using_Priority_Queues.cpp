/*
    Dijkstra's algorithm

    Given a weighted, undirected graph of V vertices, numbered from 0 to V-1, and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that edge . 

    Given a source node S. Find the shortest distance of all the vertex from the source vertex S. Return a list of integers denoting shortest distance between each node and source vertex S. If a vertex is not reachable from source then its distance will be 109.

    Examples:

    Input: V = 2, adj [] = [[[1, 9]], [[0, 9]]], S=0
    Output: [0, 9]
    Explanation: The shortest distance from node 0(source) to node 0 is 0 and the shortest distance from node 0 to node 1 is 6.

    Input: V = 3,adj = [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]], S=2
    Output: [4, 3, 0]
    Explanation: 
    For node 0, the shortest path is 2->1->0 (distance=4)
    For node 1, the shortest path is 2->1 (distance=3)
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> dist(V, 1e9); // Distance array initialized to "infinity"
        dist[S] = 0;

        // Min-heap priority queue: stores pairs of (distance, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, S));

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Traverse all adjacent nodes of u
            for (int i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i][0];
                int weight = adj[u][i][1];

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }
};

void printVector(const vector<int>& dist) {
    for (int i = 0; i < dist.size(); ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1
    int V1 = 2;
    vector<vector<int>> adj1[2];
    adj1[0].push_back({1, 9});
    adj1[1].push_back({0, 9});
    int S1 = 0;
    vector<int> res1 = sol.dijkstra(V1, adj1, S1);
    cout << "Example 1 Output: ";
    printVector(res1);  // Expected: 0 9

    // Example 2
    int V2 = 3;
    vector<vector<int>> adj2[3];
    adj2[0].push_back({1, 1});
    adj2[0].push_back({2, 6});
    adj2[1].push_back({2, 3});
    adj2[1].push_back({0, 1});
    adj2[2].push_back({1, 3});
    adj2[2].push_back({0, 6});
    int S2 = 2;
    vector<int> res2 = sol.dijkstra(V2, adj2, S2);
    cout << "Example 2 Output: ";
    printVector(res2);  // Expected: 4 3 0

    return 0;
}

// Time: O(E log V)
// Space: O(V + E)