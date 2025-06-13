/*
    485. Max Consecutive Ones
    Given a binary array nums, return the maximum number of consecutive 1's in the array.

    Example 1:

    Input: nums = [1,1,0,1,1,1]
    Output: 3
    Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
    Example 2:

    Input: nums = [1,0,1,1,0,1]
    Output: 2

    Constraints:

    1 <= nums.length <= 105
    nums[i] is either 0 or 1.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // int findMaxConsecutiveOnes(vector<int>& nums) {
    //     int n = nums.size();
    //     int max_count = 0;

    //     for(int i = 0; i < n; i++) {
    //         if (nums[i] == 0) continue;

    //         int count = 0;
    //         while (i < n && nums[i] != 0) { // <- Corrected condition here
    //             count++;
    //             i++;
    //         }
    //         max_count = max(max_count, count);
    //     }
    //     return max_count;
    // }
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                count++;
                max_count = max(count, max_count);
            }else{
                count = 0;
            }
        }
        return max_count;
    }
};

int main()
{
    int n;
    cin >> n; // Number of elements in the array
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i]; // Input array elements
    }
    
    Solution sol;
    int result = sol.findMaxConsecutiveOnes(nums);
    cout << result << endl; // Prints maximum consecutive ones
    
    return 0;
}