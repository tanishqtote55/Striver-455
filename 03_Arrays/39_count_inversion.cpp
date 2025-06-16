/*
    Count Inversions
    Given an integer array nums. Return the number of inversions in the array.

    Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

    It indicates how close an array is to being sorted.
    A sorted array has an inversion count of 0.
    An array sorted in descending order has maximum inversion.

    Examples:
    Input: nums = [2, 3, 7, 1, 3, 5]

    Output: 5

    Explanation: The responsible indexes are:

    nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3

    nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3

    nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3

    nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4

    nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5

    Input: nums = [-10, -5, 6, 11, 15, 17]

    Output: 0

    Explanation: nums is sorted, hence no inversions present.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Better Approach
    // long long int numberOfInversions(vector<int> nums) {
    //     int n = nums.size();
    //     int count = 0;
    //     for(int i = 0; i < n; i++){
    //         for(int j = i + 1; j < n; j++){
    //             if(nums[i] > nums[j]){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }

    // Optimal Approach
    long long int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        long long int count = 0;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                count += (mid - left + 1);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return count;
    }

    long long int mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high) / 2;
        long long int count = 0;

        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);

        return count;
    }

    long long int numberOfInversions(vector<int> nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 3, 7, 1, 3, 5};

    cout << "Number of inversions in [2, 3, 7, 1, 3, 5] = "
         << sol.numberOfInversions(nums1) << endl;

    vector<int> nums2 = {-10, -5, 6, 11, 15, 17};

    cout << "Number of inversions in [-10, -5, 6, 11, 15, 17] = "
         << sol.numberOfInversions(nums2) << endl;

    return 0;
}