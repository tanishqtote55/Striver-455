/*
    N meetings in one room
    Given one meeting room and N meetings represented by two arrays, start and end, where start[i] represents the start time of the ith meeting and end[i] represents the end time of the ith meeting, determine the maximum number of meetings that can be accommodated in the meeting room if only one meeting can be held at a time.

    Examples:
    Input : Start = [1, 3, 0, 5, 8, 5] , End = [2, 4, 6, 7, 9, 9]
    Output : 4
    Explanation : The meetings that can be accommodated in meeting room are (1,2) , (3,4) , (5,7) , (8,9).

    Input : Start = [10, 12, 20] , End = [20, 25, 30]
    Output : 1
    Explanation : Given the start and end time, only one meeting can be held in meeting room.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> meetings;
        
        // Create pairs of (end time, start time)
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }

        // Sort by end time
        sort(meetings.begin(), meetings.end());

        int count = 1; // first meeting always selected
        int lastEnd = meetings[0].first;

        for (int i = 1; i < n; i++) {
            if (meetings[i].second > lastEnd) {
                count++;
                lastEnd = meetings[i].first;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    cout << "Max meetings: " << sol.maxMeetings(start, end) << endl;  // Output: 4

    return 0;
}

// | Complexity | Value                    |
// | ---------- | ------------------------ |
// | Time       | O(N log N) – for sorting |
// | Space      | O(N) – for storing pairs |
