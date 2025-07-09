/*
    785. Is Graph Bipartite?
    There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

    There are no self-edges (graph[u] does not contain u).
    There are no parallel edges (graph[u] does not contain duplicate values).
    If v is in graph[u], then u is in graph[v] (the graph is undirected).
    The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
    A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

    Return true if and only if it is bipartite.

    Example 1:
    Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
    Output: false
    Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

    Example 2:
    Input: graph = [[1,3],[0,2],[1,3],[0,2]]
    Output: true
    Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
    
    Constraints:

    graph.length == n
    1 <= n <= 100
    0 <= graph[u].length < n
    0 <= graph[u][i] <= n - 1
    graph[u] does not contain u.
    All the values of graph[u] are unique.
    If graph[u] contains v, then graph[v] contains u.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, int currColor, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = currColor;

        for (int i = 0; i < graph[node].size(); ++i) {
            int neighbor = graph[node][i];
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - currColor, color, graph))
                    return false;
            } else if (color[neighbor] == currColor) {
                return false; // adjacent node has same color
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = unvisited

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph))
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Example 1: Not bipartite
    vector<vector<int>> graph1 = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    cout << "Graph 1 is bipartite? " << (sol.isBipartite(graph1) ? "Yes" : "No") << endl;

    // Example 2: Bipartite
    vector<vector<int>> graph2 = {{1,3}, {0,2}, {1,3}, {0,2}};
    cout << "Graph 2 is bipartite? " << (sol.isBipartite(graph2) ? "Yes" : "No") << endl;

    // Example 3: Disconnected graph (bipartite)
    vector<vector<int>> graph3 = {{1}, {0}, {3}, {2}};
    cout << "Graph 3 is bipartite? " << (sol.isBipartite(graph3) ? "Yes" : "No") << endl;

    return 0;
}

// | Metric           | Value                                |
// | ---------------- | ------------------------------------ |
// | Time Complexity  | O(V + E)                             |
// | Space Complexity | O(V) for `color` and recursion stack |