/*
    Highest Occurring Element in an Array
    Given an array of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. If there are multiple elements that appear a maximum number of times, find the smallest of them.

    Please note that this section might seem a bit difficult without prior knowledge on what hashing is, we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to give a shot to the problem. Cheers!

    Examples:
    Input: arr = [1, 2, 2, 3, 3, 3]

    Output: 3

    Explanation: The number 3 appears the most (3 times). It is the most frequent element.

    Input: arr = [4, 4, 5, 5, 6]

    Output: 4

    Explanation: Both 4 and 5 appear twice, but 4 is smaller. So, 4 is the most frequent element.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            map[nums[i]]++;
        }
        int max_count = 1;
        int max_elem = nums[0];
        for(auto& it: map){
            if(it.second > max_count){
                max_count = it.second;
                max_elem = it.first;
            }
        }
        return max_elem;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 3, 3, 3}; // Example input
    int result = sol.mostFrequentElement(nums);
    cout << "Most frequent element: " << result << endl;
    return 0;
}