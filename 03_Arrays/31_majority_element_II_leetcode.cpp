/*
    229. Majority Element II
    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

    Example 1:

    Input: nums = [3,2,3]
    Output: [3]
    Example 2:

    Input: nums = [1]
    Output: [1]
    Example 3:

    Input: nums = [1,2]
    Output: [1,2]
    
    Constraints:

    1 <= nums.length <= 5 * 104
    -109 <= nums[i] <= 109

    Follow up: Could you solve the problem in linear time and in O(1) space?
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Better Solution
    // vector<int> majorityElement(vector<int>& nums) {
    //     map<int, int> freq;
    //     vector<int> result;
    //     for(int x: nums){
    //         freq[x]++;
    //     }
    //     for(auto it: freq){
    //         if(it.second > (nums.size() / 3))
    //             result.push_back(it.first);
    //     }
    //     return result;
    // }

    // Optimal Solution: Boyer-Moore Voting Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;

        // 1st pass: find potential candidates
        for (int num : nums) {
            if (count1 == 0 && num != candidate2) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0 && num != candidate1) {
                candidate2 = num;
                count2 = 1;
            }
            else if (num == candidate1) {
                count1++;
            }
            else if (num == candidate2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        // 2nd pass: validate the candidates
        vector<int> result;
        int freq1 = 0, freq2 = 0;
        for (int num : nums) {
            if (num == candidate1) freq1++;
            if (num == candidate2) freq2++;
        }
        
        if (freq1 > nums.size() / 3) result.push_back(candidate1);
        if (freq2 > nums.size() / 3 && candidate2 != candidate1) result.push_back(candidate2);
        
        return result;
    }
};

int main() {
    int n;
    cout << "Enter size of array: "; 
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: "; 
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    Solution sol;
    vector<int> result = sol.majorityElement(nums);
    
    cout << "Elements appearing more than n/3:" << endl;
    for(int x : result) cout << x << " "; 
    cout << endl;

    return 0;
}