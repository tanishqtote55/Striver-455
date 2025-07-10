// Problem Statement (Leetcode 547 / GFG)
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 means the i-th and j-th cities are directly connected, and 0 otherwise.
// A province is a group of directly or indirectly connected cities. Your task is to return the total number of provinces.

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);  // all initially have rank 0
        for (int i = 0; i < n; i++)
            parent[i] = i;  // initially each node is its own parent
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    ds.unionByRank(i, j);
                }
            }
        }

        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (ds.find(i) == i) {
                provinces++;
            }
        }

        return provinces;
    }
};

// Sample usage
int main() {
    Solution sol;
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Number of Provinces: " << sol.findCircleNum(isConnected) << endl;
    return 0;
}

// Time: O(n² * α(n)) where α is inverse Ackermann (nearly constant)
// Space: O(n) for parent and rank arrays