/*
    Frog Jump

    A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step.

    To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from any step either one or two steps, provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

    Examples:
    
    Input: heights = [2, 1, 3, 5, 4]
    Output: 2
    Explanation: One possible route can be,
    0th step -> 2nd Step = abs(2 - 3) = 1
    2nd step -> 4th step = abs(3 - 4) = 1
    Total = 1 + 1 = 2.

    Input: heights = [7, 5, 1, 2, 6]
    Output: 9
    Explanation: One possible route can be,
    0th step -> 1st Step = abs(7 - 5) = 2
    1st step -> 3rd step = abs(5 - 2) = 3
    3rd step -> 4th step = abs(2 - 6) = 4
    Total = 2 + 3 + 4 = 9.
*/

// Why a greedy solution does not work?
// 30 10 60 10 60 50 => Greedy will go from 30 to 10 then 10 to 10 and then 10 to 50 So Total 60
// 30 10 60 10 60 50 => Ans should be from 30 to 60 then 60 to 60 then 60 to 50 So Total 40

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    // 1. Memoization (Top-Down)
    int frogJumpMemo(int i, vector<int>& heights, vector<int>& dp) {
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];

        int oneStep = frogJumpMemo(i - 1, heights, dp) + abs(heights[i] - heights[i - 1]);
        int twoStep = INT_MAX;
        if (i > 1)
            twoStep = frogJumpMemo(i - 2, heights, dp) + abs(heights[i] - heights[i - 2]);

        return dp[i] = min(oneStep, twoStep);
    }

    // 2. Tabulation (Bottom-Up)
    int frogJumpTab(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n);
        dp[0] = 0;

        for (int i = 1; i < n; ++i) {
            int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int twoStep = (i > 1) ? dp[i - 2] + abs(heights[i] - heights[i - 2]) : INT_MAX;
            dp[i] = min(oneStep, twoStep);
        }

        return dp[n - 1];
    }

    // 3. Space Optimized
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        int prev2 = 0, prev1 = 0, curr = 0;

        for (int i = 1; i < n; ++i) {
            int oneStep = prev1 + abs(heights[i] - heights[i - 1]);
            int twoStep = INT_MAX;
            if (i > 1)
                twoStep = prev2 + abs(heights[i] - heights[i - 2]);

            curr = min(oneStep, twoStep);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main() {
    Solution sol;
    vector<int> heights;
    int n, h;

    cout << "Enter number of steps: ";
    cin >> n;
    cout << "Enter heights of each step:\n";
    for (int i = 0; i < n; ++i) {
        cin >> h;
        heights.push_back(h);
    }

    // Memoization
    vector<int> dp(n, -1);
    cout << "Minimum energy (Memoization): " << sol.frogJumpMemo(n - 1, heights, dp) << endl;

    // Tabulation
    cout << "Minimum energy (Tabulation): " << sol.frogJumpTab(heights) << endl;

    // Space Optimized
    cout << "Minimum energy (Space Optimized): " << sol.frogJump(heights) << endl;

    return 0;
}