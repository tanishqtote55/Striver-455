/*
    Minimize Max Distance to Gas Station
    Given a sorted array arr of size n, containing integer positions of n gas stations on the X-axis, and an integer k, place k new gas stations on the X-axis. The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions. Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations. Find the minimum value of dist.


    Examples:
    Input: n = 10, arr = [1, 2, 3, 4, 5, 6 ,7, 8, 9, 10], k = 10

    Output: 0.50000

    Explanation: One of the possible ways to place 10 gas stations is [1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10]. Thus the maximum difference between adjacent gas stations is 0.5. Hence, the value of dist is 0.5. It can be shown that there is no possible way to add 10 gas stations in such a way that the value of dist is lower than this.

    Input : n = 10, arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 1

    Output: 1.00000

    Explanation: One of the possible ways to place 1 gas station is [0.5, 1, 1.5, 2, 3, 4, 5, 6, 7, 8, 9, 10]. Thus the maximum difference between adjacent gas stations is still 1. Hence, the value of dist is 1. It can be shown that there is no possible way to add 1 gas station in such a way that the value of dist is lower than this. 
*/

#include <iostream>
#include <vector>
#include <algorithm>    
#include <numeric> 
#include <iomanip>
using namespace std;

class Solution {
public:
    // Helper function: Count stations needed for a given max allowed distance
    bool isPossible(vector<int>& stations, int k, double dist) {
        int required = 0;
        for (int i = 1; i < stations.size(); ++i) {
            double gap = stations[i] - stations[i - 1];
            required += int(gap / dist);  // Number of extra stations needed in this gap
        }
        return required <= k;
    }

    // Brute-force: Try every possible distance
    double minmaxGasDistBrute(vector<int>& stations, int k) {
        double maxGap = 0;
        for (int i = 1; i < stations.size(); ++i) {
            maxGap = max(maxGap, double(stations[i] - stations[i - 1]));
        }

        double ans = maxGap;
        for (double d = 0.0001; d <= maxGap; d += 0.0001) {
            if (isPossible(stations, k, d)) {
                ans = d;
                break;  // First valid d found
            }
        }
        return ans;
    }

    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0, right = stations.back() - stations.front();
        double eps = 1e-6;

        while (right - left > eps) {
            double mid = (left + right) / 2.0;
            if (isPossible(stations, k, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return left;
    }
};

int main() {
    Solution s;
    vector<int> stations = {1, 2, 3, 4, 5, 6 ,7, 8, 9, 10};
    int k = 10;
    cout << fixed << setprecision(5) << s.minmaxGasDistBrute(stations, k) << endl;
    return 0;
}
