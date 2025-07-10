/*
    Disjoint Set
    Design a disjoint set (also called union-find) data structure that supports the following operations:
    DisjointSet(int n) initializes the disjoint set with n elements.
    void unionByRank(int u, int v) merges the sets containing u and v using the rank heuristic.
    void unionBySize(int u, int v) merges the sets containing u and v using the size heuristic.
    bool find(int u, int v) checks if the elements u and v are in the same set and returns true if they are, otherwise false.

    Examples:
    Input:
    ["DisjointSet", "unionByRank", "unionBySize", "find", "find"]
    [[5], [0, 1], [2, 3], [0, 1], [0, 3]]
    Output:
    [null, null, null, true, false]
    Explanation:
    DisjointSet ds = new DisjointSet(5); // Initialize a disjoint set with 5 elements
    ds.unionByRank(0, 1); // Merge sets containing 0 and 1 using rank
    ds.unionBySize(2, 3); // Merge sets containing 2 and 3 using size
    ds.find(0, 1); // Returns true as 0 and 1 are in the same set
    ds.find(0, 3); // Returns false as 0 and 3 are not in the same set

    Input:
    ["DisjointSet", "unionBySize", "unionBySize", "find", "find"]
    [[3], [0, 1], [1, 2], [0, 2], [0, 1]]
    Output:
    [null, null, null, true, true]
    Explanation:
    DisjointSet ds = new DisjointSet(3); // Initialize a disjoint set with 3 elements
    ds.unionBySize(0, 1); // Merge sets containing 0 and 1 using size
    ds.unionBySize(1, 2); // Merge sets containing 1 and 2 using rank
    ds.find(0, 2); // Returns true as 0 and 2 are in the same set
    ds.find(0, 1); // Returns true as 0 and 1 are in the same set
*/

#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank, size;

    // Path Compression
    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    bool find(int u, int v) {
        return findParent(u) == findParent(v);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

#include <iostream>

int main() {
    DisjointSet ds(5);           // Elements: 0 1 2 3 4

    ds.unionByRank(0, 1);        // Union 0 and 1
    ds.unionBySize(2, 3);        // Union 2 and 3

    cout << boolalpha;
    cout << ds.find(0, 1) << endl;  // true
    cout << ds.find(0, 3) << endl;  // false

    ds.unionBySize(1, 2);        // Now connect 0-1-2-3

    cout << ds.find(0, 3) << endl;  // true
}

// | Operation       | Time Complexity |
// | --------------- | --------------- |
// | `findParent()`  | O(α(N))         |
// | `unionByRank()` | O(α(N))         |
// | `unionBySize()` | O(α(N))         |
// | Space           | O(N)            |
