/*
    1011. Capacity To Ship Packages Within D Days
    A conveyor belt has packages that must be shipped from one port to another within days days.

    The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

    Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

    Example 1:

    Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
    Output: 15
    Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
    1st day: 1, 2, 3, 4, 5
    2nd day: 6, 7
    3rd day: 8
    4th day: 9
    5th day: 10

    Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
    Example 2:

    Input: weights = [3,2,2,4,1,4], days = 3
    Output: 6
    Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
    1st day: 3, 2
    2nd day: 2, 4
    3rd day: 1, 4
    Example 3:

    Input: weights = [1,2,3,1,1], days = 4
    Output: 3
    Explanation:
    1st day: 1
    2nd day: 2
    3rd day: 3
    4th day: 1, 1

    Constraints:

    1 <= days <= weights.length <= 5 * 104
    1 <= weights[i] <= 500
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int findDays(vector<int>& weights, int capacity) {
        int days = 1;
        int currentLoad = 0;
        
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                days++;              // Need one more day
                currentLoad = 0;     // Reset load for next day
            }
            currentLoad += weight;  // Load the current package
        }
        
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int ans = right;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(findDays(weights, mid) <= days){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << "Minimum capacity = " << sol.shipWithinDays(weights, days) << endl;
    return 0;
}