/*
    1319. Number of Operations to Make Network Connected
    There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

    You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

    Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

    Example 1:
    Input: n = 4, connections = [[0,1],[0,2],[1,2]]
    Output: 1
    Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

    Example 2:
    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
    Output: 2

    Example 3:
    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
    Output: -1
    Explanation: There are not enough cables.
    
    Constraints:

    1 <= n <= 105
    1 <= connections.length <= min(n * (n - 1) / 2, 105)
    connections[i].length == 2
    0 <= ai, bi < n
    ai != bi
    There are no repeated connections.
    No two computers are connected by more than one cable.
*/


#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);  // Path compression
    }

    bool unionSet(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;  // Already connected, extra edge
        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;  // Not enough cables

        DisjointSet ds(n);
        int components = n;

        for (const auto& conn : connections) {
            if (ds.unionSet(conn[0], conn[1])) {
                components--;  // Union successful
            }
        }

        return components - 1;
    }
};

int main() {
    Solution sol;

    // Test case 1
    int n1 = 4;
    vector<vector<int>> connections1 = {{0,1},{0,2},{1,2}};
    cout << "Test 1 Output: " << sol.makeConnected(n1, connections1) << endl; // Expected: 1

    // Test case 2
    int n2 = 6;
    vector<vector<int>> connections2 = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    cout << "Test 2 Output: " << sol.makeConnected(n2, connections2) << endl; // Expected: 2

    // Test case 3
    int n3 = 6;
    vector<vector<int>> connections3 = {{0,1},{0,2},{0,3},{1,2}};
    cout << "Test 3 Output: " << sol.makeConnected(n3, connections3) << endl; // Expected: -1

    return 0;
}
// Time: O(E * α(N)) where E = connections.size() and α is inverse Ackermann function
// Space: O(N)