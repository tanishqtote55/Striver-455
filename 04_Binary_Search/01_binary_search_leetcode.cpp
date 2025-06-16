/*

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // int search(vector<int>& nums, int target) {
    //     int left = 0;
    //     int right = nums.size() - 1;

    //     while (left <= right) {
    //         int mid = left + (right - left) / 2;

    //         if (nums[mid] == target) {
    //             return mid;
    //         }
    //         else if (nums[mid] < target) {
    //             left = mid + 1;
    //         }
    //         else {
    //             right = mid - 1;
    //         }
    //     }
        
    //     return -1;
    // }

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) 
            return binarySearch(nums, mid + 1, right, target);
        else 
            return binarySearch(nums, left, mid - 1, target);
    }
    
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int target = 5;
    Solution sol;
    int idx = sol.search(nums, target);
    if (idx != -1) {
        cout << "Target " << target << " found at index " << idx << endl;
    } else {
        cout << "Target " << target << " not found in array." << endl;
    }
}