/*
    743. Network Delay Time
    You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

    We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

    Example 1:
    Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    Output: 2

    Example 2:
    Input: times = [[1,2,1]], n = 2, k = 1
    Output: 1

    Example 3:
    Input: times = [[1,2,1]], n = 2, k = 2
    Output: -1
    
    Constraints:

    1 <= k <= n <= 100
    1 <= times.length <= 6000
    times[i].length == 3
    1 <= ui, vi <= n
    ui != vi
    0 <= wi <= 100
    All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the adjacency list: u -> {v, weight}
        vector<vector<pair<int, int>>> adj(n + 1); // 1-based indexing
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back(make_pair(v, w));
        }

        // Min-heap: {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push(make_pair(0, k)); // {time, source}

        while (!pq.empty()) {
            pair<int, int> topPair = pq.top();
            pq.pop();

            int time = topPair.first;
            int node = topPair.second;

            for (int i = 0; i < adj[node].size(); i++) {
                int neighbor = adj[node][i].first;
                int weight = adj[node][i].second;

                if (time + weight < dist[neighbor]) {
                    dist[neighbor] = time + weight;
                    pq.push(make_pair(dist[neighbor], neighbor));
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;

    int result = sol.networkDelayTime(times, n, k);
    cout << "Minimum time for all nodes to receive signal: " << result << endl;

    return 0;
}

// | Metric           | Value                                               |
// | ---------------- | --------------------------------------------------- |
// | Time Complexity  | `O(E log V)` — E edges, V vertices                  |
// | Space Complexity | `O(V + E)` — Adjacency list + distance array + heap |
