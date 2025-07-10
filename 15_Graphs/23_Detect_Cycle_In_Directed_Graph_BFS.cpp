/*
    Detect a cycle in a directed graph
    Given a directed graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph contains any cycles.

    Examples:
    Input: V = 6, adj= [ [1], [2, 5], [3], [4], [1], [ ] ]
    Output: True
    Explanation: The graph contains a cycle: 1 -> 2 -> 3 -> 4 -> 1.

    Input: V = 4, adj= [[1,2], [2], [], [0,2]]
    Output: False
    Explanation: The graph does not contain a cycle.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);

        // Step 1: Compute in-degrees of all vertices
        for (int i = 0; i < V; ++i) {
            for (int neighbor : adj[i]) {
                inDegree[neighbor]++;
            }
        }

        queue<int> q;

        // Step 2: Enqueue all nodes with in-degree 0
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // Step 3: BFS Process
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: If not all nodes were processed, there's a cycle
        return count != V;
    }
};

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Example: adj = [ [1], [2, 5], [3], [4], [1], [ ] ]
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(5);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(1);

    Solution obj;
    bool hasCycle = obj.isCyclic(V, adj.data());

    cout << (hasCycle ? "True" : "False") << endl;
    return 0;
}

// Time: O(V + E)
// Space: O(V) (for inDegree and queue)