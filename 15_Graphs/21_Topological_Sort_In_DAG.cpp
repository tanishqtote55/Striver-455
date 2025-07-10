/*
    Topological sort or Kahn's algorithm
    Given a Directed Acyclic Graph (DAG) with V vertices labeled from 0 to V-1.The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Find any Topological Sorting of that Graph.

    In topological sorting, node u will always appear before node v if there is a directed edge from node u towards node v(u -> v).
    The Output will be True if your topological sort is correct otherwise it will be False.

    Examples:
    Input: V = 6,adj=[ [ ], [ ], [3], [1], [0,1], [0,2] ]
    Output: [5, 4, 2, 3, 1, 0]
    Explanation: A graph may have multiple topological sortings. 
    The result is one of them. The necessary conditions 
    for the ordering are:
    According to edge 5 -> 0, node 5 must appear before node 0 in the ordering.
    According to edge 4 -> 0, node 4 must appear before node 0 in the ordering.
    According to edge 5 -> 2, node 5 must appear before node 2 in the ordering.
    According to edge 2 -> 3, node 2 must appear before node 3 in the ordering.
    According to edge 3 -> 1, node 3 must appear before node 1 in the ordering.
    According to edge 4 -> 1, node 4 must appear before node 1 in the ordering.

    The above result satisfies all the necessary conditions. 
    [4, 5, 2, 3, 1, 0] is also one such topological sorting 
    that satisfies all the conditions.

    Input: V = 4, adj=[ [ ], [0], [0], [0] ]
    Output: [3, 2, 1, 0]
    Explanation: The necessary conditions for the ordering are:
    For edge 1 -> 0 node 1 must appear before node 0.
    For edge 2 -> 0 node 1 must appear before node 0.
    For edge 3 -> 0 node 1 must appear before node 0.
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<bool> &visited, stack<int> &st, vector<int> adj[]) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, st, adj);
            }
        }

        // All neighbors processed, push to stack
        st.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        stack<int> st;

        // Call DFS for all unvisited nodes
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, visited, st, adj);
            }
        }

        // Stack now has the topological order in reverse
        vector<int> topoOrder;
        while (!st.empty()) {
            topoOrder.push_back(st.top());
            st.pop();
        }

        return topoOrder;
    }
};

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Example input: adj = [ [], [], [3], [1], [0, 1], [0, 2] ]
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[5].push_back(0);
    adj[5].push_back(2);

    Solution obj;
    vector<int> result = obj.topoSort(V, adj.data());

    cout << "Topological Sort (DFS-based): ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity: O(V + E)
// (Where V is the number of vertices and E is the number of edges)

// Space Complexity: O(V)
// (For the inDegree array, queue, and result vector)

