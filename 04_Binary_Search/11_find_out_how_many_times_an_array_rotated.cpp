/*
    Find out how many times the array is rotated
    Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.

    Examples:
    Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

    Output: 4

    Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.

    Input: nums = [3, 4, 5, 1, 2]

    Output: 3

    Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return i + 1;
            }
        }
        return 0;
    }

    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int ans = INT_MAX, index = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] < ans) {
                ans = arr[i];
                index = i;
            }
        }
        return index;
    }

    // O(log n)
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        int ans = INT_MAX;
        int index = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            //search space is already sorted
            //then arr[low] will always be
            //the minimum in that search space:
            if (arr[low] <= arr[high]) {
                if (arr[low] < ans) {
                    index = low;
                    ans = arr[low];
                }
                break;
            }

            //if left part is sorted:
            if (arr[low] <= arr[mid]) {
                // keep the minimum:
                if (arr[low] < ans) {
                    index = low;
                    ans = arr[low];
                }

                // Eliminate left half:
                low = mid + 1;
            }
            else { //if right part is sorted:

                // keep the minimum:
                if (arr[mid] < ans) {
                    index = mid;
                    ans = arr[mid];
                }

                // Eliminate right half:
                high = mid - 1;
            }
        }
        return index;
    }

    int findKRotation(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= arr[right]) {
                // minimum might be at or left of mid
                right = mid;
            } else {
                // minimum is in the right side
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = sol.findKRotation(arr);
    cout << "The array is rotated " << ans << " times.\n";
    return 0;
}
