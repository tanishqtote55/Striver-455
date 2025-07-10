/*
    Shortest path in undirected graph with unit weights

    Given a Undirected Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a edge from vertex edges[i][0] to vertex edges[i][1] of unit weight.

    Find the shortest path from the source to all other nodes in this graph. In this problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.

    Examples:
    Input: n = 9, m = 10, edges = [[0,1],[0,3],[3,4],[4,5],[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]]
    Output: 0 1 2 1 2 3 3 4 4
    Explanation:
    The above output array shows the shortest path to all 
    the nodes from the source vertex (0), Dist[0] = 0, Dist[1] = 1 , Dist[2] = 2 , …. Dist[8] = 4.Where Dist[node] is the shortest path between src and the node. For a node, if the value of Dist[node]= -1, then we conclude that the node is unreachable from the src node.

    Input: n = 8, m = 10, edges =[[1,0],[2,1],[0,3],[3,7],[3,4],[7,4],[7,6],[4,5],[4,6],[6,5]]
    Output: 0 1 2 1 2 3 3 2
    Explanation: 
    The above output list shows the shortest path to all the nodes from the source vertex (0), Dist[0] = 0, Dist[1] = 1, Dist[2] = 2,.....Dist[7] = 2.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M) {
        vector<vector<int>> adj(N);
        
        // Build adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Undirected
        }

        vector<int> dist(N, -1); // Initialize all distances as -1
        queue<int> q;

        dist[0] = 0; // Source is 0
        q.push(0);

        // BFS traversal
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return dist;
    }
};

void printVector(const vector<int>& dist) {
    for (int d : dist) cout << d << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1
    int N1 = 9, M1 = 10;
    vector<vector<int>> edges1 = {
        {0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}
    };
    cout << "Example 1 Output: ";
    vector<int> result1 = sol.shortestPath(edges1, N1, M1);
    printVector(result1); // Expected: 0 1 2 1 2 3 3 4 4

    // Example 2
    int N2 = 8, M2 = 10;
    vector<vector<int>> edges2 = {
        {1,0},{2,1},{0,3},{3,7},{3,4},{7,4},{7,6},{4,5},{4,6},{6,5}
    };
    cout << "Example 2 Output: ";
    vector<int> result2 = sol.shortestPath(edges2, N2, M2);
    printVector(result2); // Expected: 0 1 2 1 2 3 3 2

    return 0;
}

// | Graph Type             | Check `dist[v] == -1` | Check `dist[u] + w < dist[v]` |
// | ---------------------- | --------------------- | ----------------------------- |
// | **Unit-weight**        | ✅ Yes                 | ❌ Not needed                  |
// | **Weighted (DAG)**     | ❌ Not enough          | ✅ Yes                         |
// | **Weighted (general)** | ❌ Not enough          | ✅ Yes (Dijkstra needed)       |

// | Component | Complexity |
// | --------- | ---------- |
// | Time      | `O(N + M)` |
// | Space     | `O(N + M)` |
