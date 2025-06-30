/*
    Job sequencing Problem
    Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline , Jobs[i][2] represents Profit associated with that job. Each Job takes 1 unit of time to complete and only one job can be scheduled at a time.

    The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs and maximum profit.

    Examples:
    Input : Jobs = [ [1, 4, 20] , [2, 1, 10] , [3, 1, 40] , [4, 1, 30] ]
    Output : 2 60
    Explanation : Job with JobID 3 can be performed at time t=1 giving a profit of 40.
    Job with JobID 1 can be performed at time t=2 giving a profit of 20.
    No more jobs can be scheduled, So total Profit = 40 + 20 => 60.
    Total number of jobs completed are two, JobID 1, JobID 3.
    So answer is 2 60.
    Input : Jobs = [ [1, 2, 100] , [2, 1, 19] , [3, 2, 27] , [4, 1, 25] , [5, 1, 15] ]
    Output : 2 127
    Explanation : Job with JobID 1 can be performed at time time t=1 giving a profit of 100.
    Job with JobID 3 can be performed at time t=2 giving a profit of 27.
    No more jobs can be scheduled, So total Profit = 100 + 27 => 127.
    Total number of jobs completed are two, JobID 1, JobID 3.
    So answer is 2 127.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        // Sort jobs by profit in descending order
        sort(Jobs.begin(), Jobs.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] > b[2]; // sort by profit
        });

        int maxDeadline = 0;
        for (auto& job : Jobs) {
            maxDeadline = max(maxDeadline, job[1]);
        }

        // Initialize slots: slot[i] = true means time i is occupied
        vector<bool> slot(maxDeadline + 1, false);

        int count = 0;  // number of jobs done
        int profit = 0; // total profit

        for (auto& job : Jobs) {
            int id = job[0];
            int deadline = job[1];
            int jobProfit = job[2];

            // Find a free slot from deadline → 1
            for (int t = deadline; t >= 1; t--) {
                if (!slot[t]) {
                    slot[t] = true;
                    count++;
                    profit += jobProfit;
                    break;
                }
            }
        }

        return {count, profit};
    }
};

#include <iostream>
int main() {
    Solution sol;

    vector<vector<int>> jobs1 = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> res1 = sol.JobScheduling(jobs1);
    cout << res1[0] << " " << res1[1] << endl; // Output: 2 60

    vector<vector<int>> jobs2 = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
    vector<int> res2 = sol.JobScheduling(jobs2);
    cout << res2[0] << " " << res2[1] << endl; // Output: 2 127

    return 0;
}

// | Metric | Value                                                      |
// | ------ | ---------------------------------------------------------- |
// | Time   | O(n log n + n\*d) ≈ O(n²) in worst case (d = max deadline) |
// | Space  | O(d)                                                       |
