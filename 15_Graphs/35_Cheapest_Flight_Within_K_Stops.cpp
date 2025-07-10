/*
    787. Cheapest Flights Within K Stops

    There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

    You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

    Example 1:
    Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
    Output: 700
    Explanation:
    The graph is shown above.
    The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
    Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

    Example 2:
    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
    Output: 200
    Explanation:
    The graph is shown above.
    The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

    Example 3:
    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
    Output: 500
    Explanation:
    The graph is shown above.
    The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
    
    Constraints:

    1 <= n <= 100
    0 <= flights.length <= (n * (n - 1) / 2)
    flights[i].length == 3
    0 <= fromi, toi < n
    fromi != toi
    1 <= pricei <= 104
    There will not be any multiple flights between two cities.
    0 <= src, dst, k < n
    src != dst
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int CheapestFlight(int n, vector<vector<int>> &flights, int src, int dst, int K){
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > K)
                continue;

            for (auto iter : adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;

                if (cost + edW < dist[adjNode]) {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency list: u -> {v, cost}
        vector<vector<pair<int, int>>> adj(n);
        for (auto &flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // Queue: {node, stops, cost}
        queue<vector<int>> q;
        q.push({src, 0, 0});

        // Min cost to reach each node
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            int node = front[0];
            int stops = front[1];
            int cost = front[2];

            // If we exceed k stops, skip
            if (stops > k) continue;

            for (auto &[nei, price] : adj[node]) {
                int newCost = cost + price;
                // Only push to queue if the cost is better (to avoid TLE)
                if (newCost < dist[nei]) {
                    dist[nei] = newCost;
                    q.push({nei, stops + 1, newCost});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    int src = 0, dst = 2, k = 1;
    int ans = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest price: " << ans << endl; // Expected: 200
    return 0;
}

// | Metric | Value        |
// | ------ | ------------ |
// | Time   | O(V + E × K) |
// | Space  | O(V)         |
