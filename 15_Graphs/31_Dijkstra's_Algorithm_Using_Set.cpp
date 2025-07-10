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
#include <set>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> dist(V, 1e9);  // Distance array
        dist[S] = 0;

        // Set stores {distance, node}
        set<pair<int, int>> st;
        st.insert(make_pair(0, S));

        while (!st.empty()) {
            pair<int, int> top = *(st.begin());
            st.erase(st.begin());

            int u = top.second;
            int d = top.first;

            // Traverse neighbors
            for (int i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i][0];
                int weight = adj[u][i][1];

                if (dist[u] + weight < dist[v]) {
                    // If v was already in set, remove the old entry
                    if (dist[v] != 1e9) {
                        st.erase(make_pair(dist[v], v));
                    }
                    // Update with new distance
                    dist[v] = dist[u] + weight;
                    st.insert(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution sol;

    int V = 3;
    vector<vector<int>> adj[3];
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});
    adj[1].push_back({2, 3});
    adj[1].push_back({0, 1});
    adj[2].push_back({1, 3});
    adj[2].push_back({0, 6});
    int S = 2;

    vector<int> res = sol.dijkstra(V, adj, S);

    cout << "Shortest distances from source " << S << ": ";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}

// | Approach        | Priority Queue (`pq`)   | Set (`set`)        |
// | --------------- | ----------------------- | ------------------ |
// | Update Distance | Insert duplicate        | Erase and insert ✅ |
// | Efficiency      | `O(E log V)`            | `O(E log V)`       |
// | Decrease-Key    | Not directly possible ❌ | Easy and clean ✅   |

// Time Complexity
// Let: V = number of vertices E = number of edges
// Key operations:
// In each iteration, we extract the smallest distance node from the set → O(log V)
// For each adjacent node, we may need to:
// Erase an old entry from the set → O(log V)
// Insert a new entry into the set → O(log V)
// So, in the worst case:
// We process each edge once
// Each edge update costs O(log V)
// ⏱ Final Time Complexity:
// O((V + E) * log V)
// Same as the Dijkstra with priority_queue (but with slightly better control for decrease-key).

// 📦 Space Complexity
// dist[] array → O(V)
// set → stores up to V nodes at a time → O(V)
// adj[] adjacency list → O(V + E)
// 🧮 Final Space Complexity:
// O(V + E)