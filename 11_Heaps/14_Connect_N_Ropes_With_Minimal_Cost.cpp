/*
    Problem Statement
    Given n ropes with different lengths, we want to connect them into a single rope. Every time we connect two ropes of lengths a and b, the cost is a + b. We want to minimize the total cost of connecting all ropes.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minCostToConnectRopes(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes.begin(), ropes.end());

    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int cost = first + second;
        totalCost += cost;

        minHeap.push(cost);
    }

    return totalCost;
}

int main() {
    vector<int> ropes1 = {4, 3, 2, 6};
    cout << "Minimum cost to connect ropes: " << minCostToConnectRopes(ropes1) << endl;
    // Output: 29 → steps: (2+3)=5, (5+4)=9, (9+6)=15 → total = 5+9+15 = 29

    vector<int> ropes2 = {1, 2, 3, 4, 5};
    cout << "Minimum cost to connect ropes: " << minCostToConnectRopes(ropes2) << endl;
    // Output: 33

    return 0;
}
