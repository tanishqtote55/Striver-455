/*
    435. Non-overlapping Intervals
    Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

    Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

    Example 1:

    Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
    Output: 1
    Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
    Example 2:

    Input: intervals = [[1,2],[1,2],[1,2]]
    Output: 2
    Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
    Example 3:

    Input: intervals = [[1,2],[2,3]]
    Output: 0
    Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

    Constraints:

    1 <= intervals.length <= 105
    intervals[i].length == 2
    -5 * 104 <= starti < endi <= 5 * 104
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // N Meetings in One Room
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1; // count of non-overlapping intervals
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= lastEnd) {
                // no overlap
                count++;
                lastEnd = intervals[i][1];
            }
        }

        // intervals.size() - count = minimum removals
        return intervals.size() - count;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> intervals1 = {{1,2},{2,3},{3,4},{1,3}};
    cout << "Minimum to remove: " << sol.eraseOverlapIntervals(intervals1) << endl; // Output: 1

    vector<vector<int>> intervals2 = {{1,2},{1,2},{1,2}};
    cout << "Minimum to remove: " << sol.eraseOverlapIntervals(intervals2) << endl; // Output: 2

    vector<vector<int>> intervals3 = {{1,2},{2,3}};
    cout << "Minimum to remove: " << sol.eraseOverlapIntervals(intervals3) << endl; // Output: 0

    return 0;
}



// | Metric | Complexity                       |
// | ------ | -------------------------------- |
// | Time   | O(n log n) — for sorting         |
// | Space  | O(1) extra — in-place if allowed |
