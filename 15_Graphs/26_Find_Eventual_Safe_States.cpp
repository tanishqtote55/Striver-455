/*
    802. Find Eventual Safe States

    There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

    A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

    Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

    Example 1:
    Illustration of graph
    Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    Output: [2,4,5,6]
    Explanation: The given graph is shown above.
    Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
    Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
   
    Example 2:
    Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    Output: [4]
    Explanation:
    Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
    
    Constraints:

    n == graph.length
    1 <= n <= 104
    0 <= graph[i].length <= n
    0 <= graph[i][j] <= n - 1
    graph[i] is sorted in a strictly increasing order.
    The graph may contain self-loops.
    The number of edges in the graph will be in the range [1, 4 * 104].
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& pathVis, vector<int>& isSafe) {
        visited[node] = 1;
        pathVis[node] = 1;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, graph, visited, pathVis, isSafe) == false)
                    return false;
            } else if (pathVis[neighbor]) {
                return false; // cycle detected
            }
        }

        pathVis[node] = 0;
        isSafe[node] = 1;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0), pathVis(n, 0), isSafe(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(i, graph, visited, pathVis, isSafe);
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (isSafe[i]) result.push_back(i);
        }

        return result;
    }

    vector<int> eventualSafeNodesBFS(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> inDegree(n, 0);

        // Step 1: Reverse the graph and build in-degree
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u);
                inDegree[u]++;
            }
        }

        // Step 2: Kahn's algorithm starting from terminal nodes (in-degree 0)
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<bool> safe(n, false);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int neighbor : reverseGraph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) result.push_back(i);
        }

        return result;
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1)
            cout << ", ";
    }
    cout << "]\n";
}

int main() {
    vector<vector<int>> graph1 = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<vector<int>> graph2 = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};

    Solution sol;

    cout << "DFS Output (Graph 1): ";
    printVector(sol.eventualSafeNodes(graph1));

    cout << "BFS Output (Graph 1): ";
    printVector(sol.eventualSafeNodesBFS(graph1));

    cout << "DFS Output (Graph 2): ";
    printVector(sol.eventualSafeNodes(graph2));

    cout << "BFS Output (Graph 2): ";
    printVector(sol.eventualSafeNodesBFS(graph2));

    return 0;
}

// | Complexity | DFS Approach    | BFS Approach    |
// | ---------- | --------------- | --------------- |
// | Time       | O(V + E)        | O(V + E)        |
// | Space      | O(V + E) + O(V) | O(V + E) + O(V) |
