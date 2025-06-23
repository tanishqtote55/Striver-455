/*
    Rat in a Maze
    Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1).

    Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).

    The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.

    Examples:
    Input : n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]

    Output : [ "DDRDRR" , "DRDDRR" ]

    Explanation : The rat has two different path to reach (3, 3).

    The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).

    The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).

    Input : n = 2 , grid = [ [1, 0] , [1, 0] ]

    Output : -1

    Explanation : There is no path that rat can choose to travel from (0,0) to (1,1).
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis){
        if(i == n - 1 && j == n - 1){
            ans.push_back(move);
            return;
        }
        // DLRU
        // Downward
        if(i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1){
            vis[i][j] = 1;
            solve(i + 1, j, a, n, ans, move + 'D', vis);
            vis[i][j] = 0;
        }
        // Left
        if(j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1){
            vis[i][j] = 1;
            solve(i, j - 1, a, n, ans, move + 'L', vis);
            vis[i][j] = 0;
        }
        // Right
        if(j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1){
            vis[i][j] = 1;
            solve(i, j + 1, a, n, ans, move + 'R', vis);
            vis[i][j] = 0;
        }
        // Upward
        if(i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1){
            vis[i][j] = 1;
            solve(i - 1, j, a, n, ans, move + 'U', vis);
            vis[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int> > &grid) {
        //your code goes here
        int n = grid.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        if(grid[0][0] == 1) solve(0, 0, grid, n, ans, "", vis);
        return ans;
    }

    void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
        vector < vector < int >> & vis, int di[], int dj[]) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }
    
    vector < string > findPath(vector < vector < int >> & m) {
        int n = m.size();
        vector < string > ans;
        vector < vector < int >> vis(n, vector < int > (n, 0));
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
        return ans;
    }
};

// Main function to test the code
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = sol.findPath(grid);

    if (paths.empty()) {
        cout << "No path found.\n";
    } else {
        cout << "Paths found:\n";
        for (const string &path : paths) {
            cout << path << "\n";
        }
    }

    return 0;
}

// Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.

// Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).