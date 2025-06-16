/*
    88. Merge Sorted Array

    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

    Merge nums1 and nums2 into a single array sorted in non-decreasing order.

    The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

    Example 1:

    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
    Example 2:

    Input: nums1 = [1], m = 1, nums2 = [], n = 0
    Output: [1]
    Explanation: The arrays we are merging are [1] and [].
    The result of the merge is [1].
    Example 3:

    Input: nums1 = [0], m = 0, nums2 = [1], n = 1
    Output: [1]
    Explanation: The arrays we are merging are [] and [1].
    The result of the merge is [1].
    Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
    
    Constraints:

    nums1.length == m + n
    nums2.length == n
    0 <= m, n <= 200
    1 <= m + n <= 200
    -109 <= nums1[i], nums2[j] <= 109
    
    Follow up: Can you come up with an algorithm that runs in O(m + n) time?
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     for(int i = 0; i < n; i++){
    //         nums1[m + i] = nums2[i];
    //     }
    //     sort(nums1.begin(), nums1.end()); 
    // }


    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     int i = m - 1;
    //     int j = n - 1;
    //     int k = m + n - 1;

    //     while (j >= 0) { // we need to put all elements of nums2
    //         if (i >= 0 && nums1[i] > nums2[j]) {
    //             nums1[k--] = nums1[i--];
    //         } else {
    //             nums1[k--] = nums2[j--];
    //         }
    //     }
    // }

    // Gap Algorithm (also known as Shell Sort Gap Method) : O(n + m)

    void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int idx1, int idx2) {
        if (arr1[idx1] > arr2[idx2]) {
            swap(arr1[idx1], arr2[idx2]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                // If left is in nums1 and right is in nums2
                if (left < m && right >= m) {
                    swapIfGreater(nums1, nums2, left, right - m);
                }
                // If both are in nums2
                else if (left >= m) {
                    swapIfGreater(nums2, nums2, left - m, right - m);
                }
                // If both are in nums1
                else {
                    swapIfGreater(nums1, nums1, left, right);
                }
                left++;
                right++;
            }
            
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    
        // After merging, we need to put back elements from nums2 into the end of nums1
        for(int i = 0; i < n; i++) {
            nums1[m+i] = nums2[i];
        }
    }

};

int main() {
    Solution sol;
    int m = 4, n = 3;
    vector<int> nums1 = {1, 4, 8, 10, 0, 0, 0};

    vector<int> nums2 = {2, 3, 9};

    sol.merge(nums1, m, nums2, n);

    cout << "Merged array:" << endl;
    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " "; 
    }
    cout << endl;

    return 0;
}