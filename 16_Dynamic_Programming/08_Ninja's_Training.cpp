/*
    Problem statement
    Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

    You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

    For Example
    If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints:
    1 <= T <= 10
    1 <= N <= 100000.
    1 <= values of POINTS arrays <= 100 .

    Time limit: 1 sec
    Sample Input 1:
    2
    3
    1 2 5 
    3 1 1
    3 3 3
    3
    10 40 70
    20 50 80
    30 60 90
    Sample Output 1:
    11
    210
    Explanation of sample input 1:
    For the first test case,
    One of the answers can be:
    On the first day, Ninja will learn new moves and earn 5 merit points. 
    On the second day, Ninja will do running and earn 3 merit points. 
    On the third day, Ninja will do fighting and earn 3 merit points. 
    The total merit point is 11 which is the maximum. 
    Hence, the answer is 11.

    For the second test case:
    One of the answers can be:
    On the first day, Ninja will learn new moves and earn 70 merit points. 
    On the second day, Ninja will do fighting and earn 50 merit points. 
    On the third day, Ninja will learn new moves and earn 90 merit points. 
    The total merit point is 210 which is the maximum. 
    Hence, the answer is 210.
    Sample Input 2:
    2
    3
    18 11 19
    4 13 7
    1 8 13
    2
    10 50 1
    5 100 11
    Sample Output 2:
    45
    110
*/
// Greedy Fails Here Then Try All Possible Ways Using Recursion Then Find Max

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 1. Memoization O(N * 4 * 3) = O(N)	O(N * 4)
    int memo(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
        if (day == 0) {
            int maxi = 0;
            for (int i = 0; i < 3; ++i) {
                if (i != last) {
                    maxi = max(maxi, points[0][i]);
                }
            }
            return dp[0][last] = maxi;
        }

        if (dp[day][last] != -1) return dp[day][last];

        int maxi = 0;
        for (int i = 0; i < 3; ++i) {
            if (i != last) {
                int pts = points[day][i] + memo(day - 1, i, points, dp);
                maxi = max(maxi, pts);
            }
        }

        return dp[day][last] = maxi;
    }

    // 2. Tabulation O(N * 4 * 3) = O(N)	O(N * 4)
    int tabulation(int n, vector<vector<int>>& points) {
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base case for day 0
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

        for (int day = 1; day < n; ++day) {
            for (int last = 0; last < 4; ++last) {
                dp[day][last] = 0;
                for (int i = 0; i < 3; ++i) {
                    if (i != last) {
                        int activity = points[day][i] + dp[day - 1][i];
                        dp[day][last] = max(dp[day][last], activity);
                    }
                }
            }
        }

        return dp[n - 1][3]; // 3 means no activity restriction on last day
    }

    // 3. Space Optimized O(N * 4 * 3) = O(N)	O(4) = O(1)
    int ninjaTraining(int n, vector<vector<int>>& points) {
        vector<int> prev(4, 0);

        // Base case for day 0
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; ++day) {
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; ++last) {
                temp[last] = 0;
                for (int i = 0; i < 3; ++i) {
                    if (i != last) {
                        int activity = points[day][i] + prev[i];
                        temp[last] = max(temp[last], activity);
                    }
                }
            }
            prev = temp;
        }

        return prev[3]; // No restriction on last day's activity
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(3));
        for (int i = 0; i < n; ++i)
            cin >> points[i][0] >> points[i][1] >> points[i][2];

        Solution sol;

        // 1. Memoization
        vector<vector<int>> dp(n, vector<int>(4, -1));
        cout << "Memoization: " << sol.memo(n - 1, 3, points, dp) << endl;

        // 2. Tabulation
        cout << "Tabulation: " << sol.tabulation(n, points) << endl;

        // 3. Space Optimized
        cout << "Space Optimized: " << sol.ninjaTraining(n, points) << endl;
    }

    return 0;
}
