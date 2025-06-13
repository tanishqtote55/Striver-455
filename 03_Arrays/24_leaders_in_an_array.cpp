/*
    Given an integer array nums, return a list of all the leaders in the array.

    A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.

    Examples:
    Input: nums = [1, 2, 5, 3, 1, 2]

    Output: [5, 3, 2]

    Explanation: 2 is the rightmost element, 3 is the largest element in the index range [3, 5], 5 is the largest element in the index range [2, 5]

    Input: nums = [-3, 4, 5, 1, -4, -5]

    Output: [5, 1, -4, -5]

    Explanation: -5 is the rightmost element, -4 is the largest element in the index range [4, 5], 1 is the largest element in the index range [3, 5] and 5 is the largest element in the range [2, 5]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Brute Force
    // vector<int> leaders(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> result;
    //     for(int i = n - 1; i >= 0; i--) { // iterate backwards
    //         bool leader = true;
    //         for(int j = i + 1; j < n; j++) { // check subsequent elements
    //             if (nums[j] >= nums[i]) { // if we find a bigger or equal element
    //                 leader = false;
    //                 break;
    //             }
    //         }
    //         if (leader) result.push_back(nums[i]);
    //     }
    //     reverse(result.begin(), result.end()); // reverse to match original order
    //     return result;
    // }

    // Optimal Approach
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int max = nums[n - 1];
        result.push_back(nums[n-1]);
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] > max){
                result.push_back(nums[i]);
                max = nums[i];
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 5, 3, 1, 2};

    Solution s;
    vector<int> leaders = s.leaders(nums);

    cout << "Leaders in the array are: "; 
    for(int i : leaders) { 
        cout << i << " "; 
    }
    cout << endl;

    return 0;
}

