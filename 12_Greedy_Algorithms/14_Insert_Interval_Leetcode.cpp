/*
    57. Insert Interval
    You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

    Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

    Return intervals after the insertion.

    Note that you don't need to modify intervals in-place. You can make a new array and return it.

    Example 1:

    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]
    Example 2:

    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
    
    Constraints:

    0 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 105
    intervals is sorted by starti in ascending order.
    newInterval.length == 2
    0 <= start <= end <= 105
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        for (const auto& interval : intervals) {
            // Case 1: Current interval ends before new interval starts — no overlap
            if (interval[1] < newInterval[0]) {
                result.push_back(interval);
            }
            // Case 2: Current interval starts after new interval ends — no overlap
            else if (interval[0] > newInterval[1]) {
                result.push_back(newInterval);
                newInterval = interval; // assign current interval to newInterval for further merging
            }
            // Case 3: Overlapping intervals — merge
            else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        // Push the remaining interval
        result.push_back(newInterval);
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    vector<vector<int>> result1 = sol.insert(intervals1, newInterval1);

    cout << "Merged intervals: ";
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    vector<vector<int>> result2 = sol.insert(intervals2, newInterval2);

    cout << "Merged intervals: ";
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}


// | Metric | Value |
// | ------ | ----- |
// | Time   | O(n)  |
// | Space  | O(n)  |
