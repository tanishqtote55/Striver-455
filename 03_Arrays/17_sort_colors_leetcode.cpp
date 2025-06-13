/*
    75. Sort Colors
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

    You must solve this problem without using the library's sort function.

    Example 1:

    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
    Example 2:

    Input: nums = [2,0,1]
    Output: [0,1,2]
    
    Constraints:

    n == nums.length
    1 <= n <= 300
    nums[i] is either 0, 1, or 2.
    
    Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Brute Force Approach
    // void merge(vector<int>& nums, int low, int mid, int high) {
    //     vector<int> temp;
    //     int left = low;
    //     int right = mid + 1;
    //     while(left <= mid && right <= high) {
    //         if(nums[left] <= nums[right]){
    //             temp.push_back(nums[left]);
    //             left++;
    //         }else{
    //             temp.push_back(nums[right]);
    //             right++;
    //         }
    //     }
    //     while(left <= mid){
    //         temp.push_back(nums[left]);
    //         left++;
    //     }
    //     while(right <= high){
    //         temp.push_back(nums[right]);
    //         right++;
    //     }
    //     for(int i = low; i <= high; i++){
    //         nums[i] = temp[i - low];
    //     }
    // }
    // void mergeSortHelper(vector<int>& nums, int low, int high) {
    //     if(low >= high) return;
    //     int mid = (low + high) / 2;
    //     mergeSortHelper(nums, low, mid);
    //     mergeSortHelper(nums, mid+1, high);
    //     merge(nums, low, mid, high);
    // }
    // void sortColors(vector<int>& nums) {
    //     if(nums.size() <= 1) return;
    //     mergeSortHelper(nums, 0, nums.size() - 1);
    // }

    // Better Approach
    // void sortColors(vector<int>& nums) {
    //     int count0 = 0, count1 = 0, count2 = 0;
        
    //     // First pass to count 0s, 1s, and 2s
    //     for(int i = 0; i < nums.size(); i++) {
    //         if (nums[i] == 0) count0++;
    //         else if (nums[i] == 1) count1++;
    //         else count2++;
    //     }
        
    //     // Second pass to overwrite array
    //     int idx = 0;
    //     for(int i = 0; i < count0; i++) {
    //         nums[idx++] = 0;
    //     }
    //     for(int i = 0; i < count1; i++) {
    //         nums[idx++] = 1;
    //     }
    //     for(int i = 0; i < count2; i++) {
    //         nums[idx++] = 2;
    //     }
    // }

    // Optimal Approach: Dutch National Flag
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
            else { // nums[mid] == 1
                mid++;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    Solution s;
    s.sortColors(nums);
    
    for(int i : nums) cout << i << " "; cout << '\n';

    return 0;
}