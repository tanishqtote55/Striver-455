/*
    Kosaraju's algorithm

    Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. An edge is represented [ai,bi] denoting a directed edge from vertex ai to bi. Find the number of strongly connected components in the graph.

    Examples:
    Input: V=5, E=[[0,2], [1,0], [2,1], [0,3], [3,4]]
    Output: 3
    Explanation: Three strongly connected components are marked below:

    Input: V=8, E=[[0,1], [1,2], [2,0], [2,3], [3,4], [4,5], [4,7], [5,6], [6,4], [6,7]]
    Output: 4
    Explanation: Four strongly connected components are marked below:
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (int nei : adj[node]) {
            if (!visited[nei])
                dfs(nei, adj, visited, st);
        }
        st.push(node);  // push after exploring all neighbors
    }

    void revDfs(int node, vector<vector<int>>& adjRev, vector<bool>& visited) {
        visited[node] = true;
        for (int nei : adjRev[node]) {
            if (!visited[nei])
                revDfs(nei, adjRev, visited);
        }
    }

    int kosaraju(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        stack<int> st;

        // Step 1: Topological sort (fill stack with finish times)
        for (int i = 0; i < V; ++i) {
            if (!visited[i])
                dfs(i, adj, visited, st);
        }

        // Step 2: Reverse the graph
        vector<vector<int>> adjRev(V);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                adjRev[v].push_back(u);
            }
        }

        // Step 3: Process stack nodes in reversed graph
        fill(visited.begin(), visited.end(), false);
        int sccCount = 0;

        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (!visited[node]) {
                sccCount++;
                revDfs(node, adjRev, visited);
            }
        }

        return sccCount;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> adj = {
        {2, 3},  // 0 → 2, 3
        {0},     // 1 → 0
        {1},     // 2 → 1
        {},      // 3 → no out edges
        {}       // 4 → no out edges
    };

    Solution sol;
    cout << "Number of Strongly Connected Components: " << sol.kosaraju(V, adj) << endl;

    return 0;
}

// Time Complexity: O(V + E)
// DFS twice and one graph transpose

// Space Complexity: O(V + E)
// For stack, visited, and reverse adjacency list