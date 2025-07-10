/*
    Minimum multiplications to reach end

    Given start, end, and an array arr of n numbers. At each step, the start is multiplied by any number in the array and then a mod operation with 100000 is done to get the new start.

    Find the minimum steps in which the end can be achieved starting from the start. If it is not possible to reach the end, then return -1.

    Examples:
    Input: arr = [2, 5, 7], start = 3, end = 30
    Output: 2
    Explanation: 
    Step 1: 3*2 = 6 % 100000 = 6 
    Step 2: 6*5 = 30 % 100000 = 30
    Therefore, in minimum 2 multiplications, we reach the end number which is treated as a destination node of a graph here.
    Input: arr = [3, 4, 65], start = 7, end = 66175
    Output: 4
    Explanation: 
    Step 1: 7*3 = 21 % 100000 = 21 
    Step 2: 21*3 = 6 % 100000 = 63 
    Step 3: 63*65 = 4095 % 100000 = 4095 
    Step 4: 4095*65 = 266175 % 100000 = 66175
    Therefore, in minimum 4 multiplications we reach the end number which is treated as a destination node of a graph here.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution{
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        const int MOD = 100000;
        vector<int> dist(MOD, -1); // stores minimum steps to each number
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int factor : arr) {
                int next = (curr * factor) % MOD;

                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    if (next == end) return dist[next];
                    q.push(next);
                }
            }
        }

        return -1; // unreachable
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 5, 7};
    int start = 3, end = 30;
    cout << sol.minimumMultiplications(arr, start, end) << endl; // Output: 2
    return 0;
}