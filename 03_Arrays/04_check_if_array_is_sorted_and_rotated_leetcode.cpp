/*
    1752. Check if Array Is Sorted and Rotated
    Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

    There may be duplicates in the original array.

    Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

    Example 1:

    Input: nums = [3,4,5,1,2]
    Output: true
    Explanation: [1,2,3,4,5] is the original sorted array.
    You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].
    Example 2:

    Input: nums = [2,1,3,4]
    Output: false
    Explanation: There is no sorted array once rotated that can make nums.
    Example 3:

    Input: nums = [1,2,3]
    Output: true
    Explanation: [1,2,3] is the original sorted array.
    You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

    Constraints:

    1 <= nums.length <= 100
    1 <= nums[i] <= 100
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        // First loop: find where the order breaks
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                // Second loop: check if the rest is sorted
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] < nums[j - 1]) {
                        return false;
                    }
                }
                // Wrap-around check
                if (nums[n - 1] > nums[0]) {
                    return false;
                }
                return true;
            }
        }
        // If no break was found, the array is already sorted
        return true;
    }
    
    // bool check(vector<int>& nums) {
    //     int count = 0;
    //     int n = nums.size();
    //     for(int i = 0; i < n; i++) {
    //         if(nums[i] > nums[(i + 1) % n]) {
    //             count++;
    //         }
    //     }
    //     return count <= 1;
    // }
};

int main() {
    Solution sol;

    // You can test with different inputs here
    vector<int> nums = {3, 4, 5, 1, 2};  // Change this to test other cases

    cout << "Input array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    bool result = sol.check(nums);

    if (result) {
        cout << "The array is sorted and rotated (or already sorted)." << endl;
    } else {
        cout << "The array is NOT sorted and rotated." << endl;
    }

    return 0;
}
