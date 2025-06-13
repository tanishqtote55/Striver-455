/*
    1. Two Sum
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.

    Example 1:

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    Example 2:

    Input: nums = [3,2,4], target = 6
    Output: [1,2]
    Example 3:

    Input: nums = [3,3], target = 6
    Output: [0,1]
    
    Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
    
    Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Normal Approach
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> result;
    //     for(int i = 0; i < nums.size() - 1; i++){
    //         for(int j = i + 1; j < nums.size(); j++){
    //             if(nums[i] + nums[j] == target){
    //                 result.push_back(i);
    //                 result.push_back(j);
    //                 return result;
    //             }
    //         }
    //     }
    //     return result;
    // }

    // Better Approach using Hashmap
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int, int> m; // to store number and its index
    //     for(int i = 0; i < nums.size(); i++) {
    //         int complement = target - nums[i];
    //         if (m.find(complement) != m.end()) {
    //             return {m[complement], i};

    //         }
    //         m[nums[i]] = i;
    //     }
    //     return {}; // Shouldn't reach here if there is a solution
    // }

    // Optimal Approach using Two Pointers
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;
        for(int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i}); // {value, original index}
        }
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int sum = arr[left].first + arr[right].first;
            if (sum == target) {
                return {arr[left].second, arr[right].second};

            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return {}; // If no such pair is found
    }
};

int main() {
    Solution sol;
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    vector<int> result = sol.twoSum(nums, target);
    if (result.size() == 2) {
        cout << "Pair found at indices: " << result[0] << " and " << result[1] << '\n';
    }
    else {
        cout << "Pair not found\n";
    }
    return 0;
}
