/*
    56. Merge Intervals
    Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

    Example 1:

    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
    Example 2:

    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.
    

    Constraints:

    1 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Brute Force

    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     int n = intervals.size();
    //     sort(intervals.begin(), intervals.end());
    //     vector<vector<int>> ans;
    //     for(int i = 0; i < n; i++){
    //         int start = intervals[i][0];
    //         int end = intervals[i][1];
    //         if(!ans.empty() && end <= ans.back()[1]){
    //             continue;
    //         }
    //         for(int j = i + 1; j < n; j++){
    //             if(intervals[j][0] <= end) {
    //                 end = max(end, intervals[j][1]);
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //         ans.push_back({start, end});
    //     }
    //     return ans;
    // }

    // Optimal Approach

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = sol.merge(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
