/*
    547. Number of Provinces
    There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

    A province is a group of directly or indirectly connected cities and no other cities outside of the group.

    You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

    Return the total number of provinces.

    Example 1:
    Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    Output: 2

    Example 2:
    Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
    Output: 3

    Constraints:
    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] is 1 or 0.
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited, int n) {
        visited[node] = true;
        for (int j = 0; j < n; ++j) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, isConnected, visited, n);
                provinces++;
            }
        }

        return provinces;
    }
};

// Sample driver code
int main() {
    Solution sol;

    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << "Output: " << sol.findCircleNum(isConnected1) << endl; // Output: 2

    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    cout << "Output: " << sol.findCircleNum(isConnected2) << endl; // Output: 3

    return 0;
}

// Time Complexity: O(n^2)
// Because the nested loop inside DFS may check all n neighbors for each of the n nodes.

// Space Complexity: O(n)
// For the visited array and recursion stack (in worst case, recursion depth = n).