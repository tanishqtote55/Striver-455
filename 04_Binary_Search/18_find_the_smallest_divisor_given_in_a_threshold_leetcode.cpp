/*
    1283. Find the Smallest Divisor Given a Threshold
    Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

    Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

    The test cases are generated so that there will be an answer.

    Example 1:

    Input: nums = [1,2,5,9], threshold = 6
    Output: 5
    Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
    If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
    Example 2:

    Input: nums = [44,22,33,11,1], threshold = 5
    Output: 44

    Constraints:

    1 <= nums.length <= 5 * 104
    1 <= nums[i] <= 106
    nums.length <= threshold <= 106
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    // int smallestDivisor(vector<int>& nums, int threshold) {
    //     int max = *max_element(nums.begin(), nums.end());
    //     int ans = max;
    //     for(int i = 1; i <= max; i++){
    //         int sum = 0;
    //         for(int j = 0; j < nums.size(); j++){
    //             sum += ceil((double)nums[j] / i);
    //         }
    //         if(sum <= threshold){
    //             ans = i;
    //             break;
    //         }
    //     }
    //     return ans;
    // }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int right = *max_element(nums.begin(), nums.end());
        int left = 1;
        int ans = right;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int sum = 0;
            for(int i = 0; i < nums.size(); i++){
                sum += ceil((double)nums[i] / mid);
            }
            if(sum <= threshold){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    Solution sol;
    int result = sol.smallestDivisor(nums, threshold);

    cout << "Smallest Divisor = " << result << endl;

    return 0;
}