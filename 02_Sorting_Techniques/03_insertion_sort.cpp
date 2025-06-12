/*
    Insertion Sorting
    Given an array of integers called nums, sort the array in non-decreasing order using the insertion sort algorithm and return the sorted array.

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
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n - 1; i++){
            int j = i;
            while(j > 0 && nums[j-1] > nums[j]){
                swap(nums[j-1], nums[j]);
                j--;
            }
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {9, 3, 1, 5, 4};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> sortedArr = sol.insertionSort(arr);

    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
