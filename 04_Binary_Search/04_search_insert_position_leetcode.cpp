/*
    35. Search Insert Position
    Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:

    Input: nums = [1,3,5,6], target = 5
    Output: 2
    Example 2:

    Input: nums = [1,3,5,6], target = 2
    Output: 1
    Example 3:

    Input: nums = [1,3,5,6], target = 7
    Output: 4

    Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums contains distinct values sorted in ascending order.
    -104 <= target <= 104
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // int searchInsert(vector<int>& nums, int target) {
    //     int ans = nums.size();
    //     for(int i = 0; i < nums.size(); i++){
    //         if(nums[i] == target){
    //             ans = i;
    //             break;
    //         } else if(nums[i] >= target){
    //             ans = i;
    //             break;
    //         }
    //     }
    //     return ans;
    // }

    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int ans = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            // maybe an answer
            if (nums[mid] >= target) {
                ans = mid;
                //look for smaller index on the left
                right = mid - 1;
            }
            else {
                left = mid + 1; // look on the right
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = sol.searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}