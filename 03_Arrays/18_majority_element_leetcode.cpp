/*
    169. Majority Element
    Given an array nums of size n, return the majority element.

    The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

    Example 1:

    Input: nums = [3,2,3]
    Output: 3
    Example 2:

    Input: nums = [2,2,1,1,1,2,2]
    Output: 2
    
    Constraints:

    n == nums.length
    1 <= n <= 5 * 104
    -109 <= nums[i] <= 109
    
    Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Brute Force Approach
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int, int> freq;
    //     for(int i = 0; i < nums.size(); i++){
    //         freq[nums[i]]++;
    //     }
    //     for(auto it: freq){
    //         if(it.second > nums.size() / 2){
    //             return it.first;
    //         }
    //     }
    //     return -1;
    // }

    // Optimal Approach: Moore’s Voting Algorithm:
    int majorityElement(vector<int> nums) {
        int n = nums.size();
        int cnt = 0; // count
        int el; // candidate element
        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                el = nums[i];
                cnt = 1;
            }
            else if (el == nums[i]) cnt++;
            else cnt--;
        }
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) cnt1++;
        }
        if (cnt1 > n / 2) return el;
        return -1;
    }
};

int main()
{
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << sol.majorityElement(nums) << '\n';

    return 0;
}