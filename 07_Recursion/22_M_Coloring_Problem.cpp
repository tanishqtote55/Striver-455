/*
    M Coloring Problem
    Given an integer M and an undirected graph with N vertices and E edges. The goal is to determine whether the graph can be coloured with a maximum of M colors so that no two of its adjacent vertices have the same colour applied to them.

    In this context, colouring a graph refers to giving each vertex a different colour. If the colouring of vertices is possible then return true, otherwise return false.

    Examples:
    Input : N = 4 , M = 3 , E = 5 , Edges = [ (0, 1) , (1, 2) , (2, 3) , (3, 0) , (0, 2) ]
    Output : true
    Explanation : Consider the three colors to be red, green, blue.
    We can color the vertex 0 with red, vertex 1 with blue, vertex 2 with green, vertex 3 with blue.
    In this way we can color graph using 3 colors at most.

    Input : N = 3 , M = 2 , E = 3 , Edges = [ (0, 1) , (1, 2) , (0, 2) ]
    Output : false
    Explanation : Consider the three colors to be red, green.
    We can color the vertex 0 with red, vertex 1 with blue.
    As the vertex 2 is adjacent to both vertex 1 and 0 , so we cannot color with red and green.
    Hence as we could not color all vertex of graph we return false.
*/

#include <iostream>          
#include <vector>          
#include <algorithm>        
#include <unordered_map>     
#include <unordered_set>     
#include <string>            
using namespace std;

class Solution {
public:
    bool isSafe(int node, vector<int> &color, vector<vector<int>>& adj, int col) {
        for (int neighbor : adj[node]) {
            if (color[neighbor] == col) return false;
        }
        return true;
    }

    bool solve(int node, vector<int> &color, int m, int N, vector<vector<int>>& adj) {
        if (node == N) return true;

        for (int col = 1; col <= m; col++) {
            if (isSafe(node, color, adj, col)) {
                color[node] = col;
                if (solve(node + 1, color, m, N, adj)) return true;
                color[node] = 0;  // backtrack
            }
        }

        return false;
    }

    bool graphColoring(vector<vector<int>>& edges, int m, int N) {
        // Step 1: Convert edge list to adjacency list
        vector<vector<int>> adj(N);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }

        // Step 2: Coloring array
        vector<int> color(N, 0);

        // Step 3: Start backtracking
        return solve(0, color, m, N, adj);
    }
};

// ------------------ MAIN FUNCTION FOR DEMO ------------------

int main() {
    int N = 3; // Number of nodes
    int M = 2; // Number of colors
    vector<vector<int>> edges = { {0, 1}, {1, 2}, {0, 2} };

    Solution sol;
    bool result = sol.graphColoring(edges, M, N);
    cout << (result ? "true" : "false") << endl;

    return 0;
}

// Time Complexity: O( N^M) (n raised to m)

// Space Complexity: O(N)