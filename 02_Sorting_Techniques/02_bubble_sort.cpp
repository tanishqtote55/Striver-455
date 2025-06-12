/*
    Bubble Sort
    Given an array of integers called nums,sort the array in non-decreasing order using the bubble sort algorithm and return the sorted array.

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
    // vector<int> bubbleSort(vector<int>& nums) {
    //     for (int i = nums.size() - 1; i >= 1; i--) {
    //         bool swapped = false;
    //         for (int j = 0; j < i; j++) {
    //             if (nums[j] > nums[j + 1]) {
    //                 swap(nums[j], nums[j + 1]);
    //                 swapped = true;
    //             }
    //         }
    //         if (!swapped) break;
    //     }
    //     return nums;
    // }
    vector<int> bubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {5, 1, 4, 2, 8};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> sortedArr = sol.bubbleSort(arr);

    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}