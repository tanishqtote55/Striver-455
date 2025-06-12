/*
    Quick Sorting
    Given an array of integers called nums, sort the array in non-decreasing order using the quick sort algorithm and return the sorted array.

    A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.

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
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low]; // ✅ first element as pivot
        int i = low + 1;
        int j = high;

        while (i <= j) {
            while (i <= high && nums[i] <= pivot) i++; // Finds the index at which the element is greater than pivot
            while (j >= low && nums[j] > pivot) j--;   // Finds the index at which the element is lower thean pivot

            // while (i <= high && nums[i] >= pivot) i++;  // Note: >= for descending
            // while (j >= low && nums[j] < pivot) j--;     // Note: < for descending
            
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]); // Place pivot in correct position
        return j;
    }

    void quickSortHelper(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int pi = partition(nums, low, high);
        quickSortHelper(nums, low, pi - 1);
        quickSortHelper(nums, pi + 1, high);
    }

    vector<int> quickSort(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        quickSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {7, 4, 1, 5, 3};

    cout << "Original array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    vector<int> sorted = sol.quickSort(nums);

    cout << "Sorted array: ";
    for (int num : sorted) cout << num << " ";
    cout << endl;

    return 0;
}