/*
    Shortest Job First
    A software engineer is tasked with using the shortest job first (SJF) policy to calculate the average waiting time for each process. The shortest job first also known as shortest job next (SJN) scheduling policy selects the waiting process with the least execution time to run next.

    Given an array of n integers representing the burst times of processes, determine the average waiting time for all processes and return the closest whole number that is less than or equal to the result.

    Examples:
    Input : bt = [4, 1, 3, 7, 2]
    Output : 4
    Explanation : The total waiting time is 20.
    So the average waiting time will be 20/5 => 4.

    Input : bt = [1, 2, 3, 4]
    Output : 2
    Explanation : The total waiting time is 10.
    So the average waiting time will be 10/4 => 2.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end()); // Step 1: Sort burst times

        long long totalWaitingTime = 0;
        long long currentWait = 0;

        for (int i = 1; i < bt.size(); i++) {
            currentWait += bt[i - 1];       // Wait time = sum of previous burst times
            totalWaitingTime += currentWait;
        }

        return totalWaitingTime / bt.size(); // ⌊avg⌋ as required
    }
};

int main() {
    Solution sol;

    vector<int> bt1 = {4, 1, 3, 7, 2};
    cout << "Average waiting time: " << sol.solve(bt1) << endl; // Output: 4

    vector<int> bt2 = {1, 2, 3, 4};
    cout << "Average waiting time: " << sol.solve(bt2) << endl; // Output: 2

    vector<int> bt3 = {5, 5, 5};
    cout << "Average waiting time: " << sol.solve(bt3) << endl; // Output: 3

    return 0;
}

// | Metric | Value      |
// | ------ | ---------- |
// | Time   | O(n log n) |
// | Space  | O(1) extra |
