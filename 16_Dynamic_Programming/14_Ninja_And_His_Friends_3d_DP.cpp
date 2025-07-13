/*
    Ninja and his Friends

    Ninja has a grid of size R x C, where each cell contains some chocolates. He has two friends: Alice and Bob, and wants to collect as many chocolates as possible using their help.

    Alice starts at the top-left cell (0, 0)
    Bob starts at the top-right cell (0, C - 1)
    Both can only move to the next row, and from position (i, j), they can move to:
    (i + 1, j)
    (i + 1, j - 1)
    (i + 1, j + 1)

    Both must remain within the grid bounds.
    Each collects all chocolates in their current cell.
    If both land on the same cell, the chocolates are only counted once.

    Return the maximum number of chocolates Ninja can collect using his two friends.

    Examples:
    Input: grid = [[2, 3, 1, 2],[3, 4, 2, 2],[5, 6, 3, 5]]
    Output: 21
    Explanation: 
    Alice: (0,0) → (1,1) → (2,1) → chocolates = 2 + 4 + 6 = 12
    Bob:  (0,3) → (1,3) → (2,3) → chocolates = 2 + 2 + 5 = 9
    Total = 12 + 9 = 21

    Input: grid = [[1, 2],[3, 4]]
    Output: 10
    Explanation:
    Alice: (0,0) → (1,0) → 1 + 3 = 4
    Bob:  (0,1) → (1,1) → 2 + 4 = 6
    But both can’t pick at same time (if they land same cell), so:
    Best is (0,0)+(1,0)+(0,1)+(1,1) - overlap = 1+3+2+4 = 10
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 1. Memoization
    int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int r = grid.size(), c = grid[0].size();

        if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
            return -1e9; // out of bounds

        if (i == r - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e9;
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int val = 0;
                if (j1 == j2) val = grid[i][j1];
                else val = grid[i][j1] + grid[i][j2];

                val += f(i + 1, j1 + dj1, j2 + dj2, grid, dp);
                maxi = max(maxi, val);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    // 2. Tabulation
    int tabulation(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                if (j1 == j2) dp[r - 1][j1][j2] = grid[r - 1][j1];
                else dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }

        for (int i = r - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < c; j1++) {
                for (int j2 = 0; j2 < c; j2++) {
                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;
                            if (nj1 >= 0 && nj1 < c && nj2 >= 0 && nj2 < c) {
                                int val = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                                val += dp[i + 1][nj1][nj2];
                                maxi = max(maxi, val);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][c - 1];
    }

    // 3. Space Optimized
    int maxChocolates(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> front(c, vector<int>(c, 0));

        // Base case: last row
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                if (j1 == j2) front[j1][j2] = grid[r - 1][j1];
                else front[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
            }
        }

        for (int i = r - 2; i >= 0; i--) {
            vector<vector<int>> curr(c, vector<int>(c, 0));
            for (int j1 = 0; j1 < c; j1++) {
                for (int j2 = 0; j2 < c; j2++) {
                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;
                            if (nj1 >= 0 && nj1 < c && nj2 >= 0 && nj2 < c) {
                                int val = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                                val += front[nj1][nj2];
                                maxi = max(maxi, val);
                            }
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }

        return front[0][c - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{2, 3, 1, 2},
                                {3, 4, 2, 2},
                                {5, 6, 3, 5}};

    // Memoization
    int r = grid.size(), c = grid[0].size();
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    cout << "Memoization: " << sol.f(0, 0, c - 1, grid, dp) << endl;

    // Tabulation
    cout << "Tabulation: " << sol.tabulation(grid) << endl;

    // Space Optimized
    cout << "Space Optimized: " << sol.maxChocolates(grid) << endl;

    return 0;
}


// | Approach        | Time             | Space        |
// | --------------- | ---------------- | ------------ |
// | Memoization     | O(R × C × C × 9) | O(R × C × C) |
// | Tabulation      | O(R × C × C × 9) | O(R × C × C) |
// | Space Optimized | O(R × C × C × 9) | O(C × C)     |