#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;

    // Read all edges once
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = make_pair(u, v);
    }

    // Adjacency Matrix
    vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // remove for directed graph
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    // Undirected Adjacency List
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // remove for directed graph
    }

    cout << "\nAdjacency List (Undirected):\n";
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int v : adjList[i]) cout << v << " ";
        cout << "\n";
    }

    // Directed Adjacency List
    vector<vector<int>> adjListDir(n + 1);
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjListDir[u].push_back(v); // only u → v
    }

    cout << "\nAdjacency List (Directed):\n";
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int v : adjListDir[i]) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
