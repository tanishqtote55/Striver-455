/*
    Traversal Techniques
    Given an undirected connected graph with V vertices numbered from 0 to V-1, the task is to implement both Depth First Search (DFS) and Breadth First Search (BFS) traversals starting from the 0th vertex. The graph is represented using an adjacency list where adj[i] contains a list of vertices connected to vertex i. Visit nodes in the order they appear in the adjacency list.

    Examples:

    Input: V = 5, adj = [[2, 3, 1], [0], [0, 4], [0], [2]]
    Output:[0, 2, 4, 3, 1], [0, 2, 3, 1, 4]
    Explanation:

    DFS: Start from vertex 0. Visit vertex 2, then vertex 4, backtrack to vertex 0, then visit vertex 3, and finally vertex 1. The traversal is 0 → 2 → 4 → 3 → 1.

    BFS: Start from vertex 0. Visit vertices 2, 3, and 1 (in the order they appear in the adjacency list). Then, visit vertex 4 from vertex 2. The traversal is 0 → 2 → 3 → 1 → 4.

    Input: V = 4, adj = [[1, 3], [2, 0], [1], [0]]
    Output: [0, 1, 2, 3], [0, 1, 3, 2]
    Explanation:

    DFS: Start from vertex 0. Visit vertex 1, then vertex 2, backtrack to vertex 0, then visit vertex 3. The traversal is 0 → 1 → 2 → 3.

    BFS: Start from vertex 0. Visit vertices 1 and 3, then visit vertex 2 from vertex 1. The traversal is 0 → 1 → 3 → 2.
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> result;
        queue<int> q;

        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return result;
    }
};

int main() {
    int V = 5;
    vector<int> adj[5];
    adj[0] = {2, 3, 1};
    adj[1] = {0};
    adj[2] = {0, 4};
    adj[3] = {0};
    adj[4] = {2};

    Solution sol;
    vector<int> bfs = sol.bfsOfGraph(V, adj);

    cout << "BFS: ";
    for (int v : bfs) cout << v << " ";
    cout << "\n";

    return 0;
}
