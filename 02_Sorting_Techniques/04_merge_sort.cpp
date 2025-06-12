/*
    Merge Sorting
    Given an array of integers, nums,sort the array in non-decreasing order using the merge sort algorithm. Return the sorted array.

    A sorted array in non-decreasing order is one in which each element is either greater than or equal to all the elements to its left in the array.

    Examples:
    Input: nums = [7, 4, 1, 5, 3]

    Output: [1, 3, 4, 5, 7]

    Explanation: 1 <= 3 <= 4 <= 5 <= 7.

    Thus the array is sorted in non-decreasing order.

    Input: nums = [5, 4, 4, 1, 1]

    Output: [1, 1, 4, 4, 5]

    Explanation: 1 <= 1 <= 4 <= 4 <= 5.

    Thus the array is sorted in non-decreasing order.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;

        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }
    }
    void mergeSortHelper(vector<int>& nums, int low, int high) {
        if(low >= high) return;
        int mid = (low + high) / 2;
        mergeSortHelper(nums, low, mid);
        mergeSortHelper(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> mergeSort(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        mergeSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {7, 4, 1, 5, 3};

    cout << "Original array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    vector<int> sorted = sol.mergeSort(nums);

    cout << "Sorted array: ";
    for (int num : sorted) cout << num << " ";
    cout << endl;

    return 0;
}

// Time Complexity
// Best Case: O(n log n)
// Average Case: O(n log n)
// Worst Case: O(n log n)

// Space Complexity
// O(N) : Worst Case