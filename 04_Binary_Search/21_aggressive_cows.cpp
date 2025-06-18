/*
    Aggressive Cows
    Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.

    Examples:
    Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]

    Output: 3

    Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.

    Input : n = 5, k = 2, nums = [4, 2, 1, 3, 6]

    Output: 5

    Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions [1, 6]. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canWePlace(vector<int> &stalls, int dist, int cows){
        int n = stalls.size(); //size of array
        int cntCows = 1; //no. of cows placed
        int last = stalls[0]; //position of last placed cow.
        for (int i = 1; i < n; i++) {
            if (stalls[i] - last >= dist) {
                cntCows++; //place next cow.
                last = stalls[i]; //update the last location.
            }
            if (cntCows >= cows) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int limit = nums[n - 1] - nums[0];
        for(int i = 1; i <= limit; i++){
            if(canWePlace(nums, i, k) == false){
                return i - 1;
            }
        }
        return limit;
    }

    // Optimal Approach
    int aggressiveCows(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 1, high = nums[n - 1] - nums[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canWePlace(nums, mid, k) == true){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};

int main() {
    Solution sol;
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = sol.aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}
