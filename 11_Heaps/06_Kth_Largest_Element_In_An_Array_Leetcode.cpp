/*
    215. Kth Largest Element in an Array
    Given an integer array nums and an integer k, return the kth largest element in the array.
    Note that it is the kth largest element in the sorted order, not the kth distinct element.
    Can you solve it without sorting?

    Example 1:
    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5

    Example 2:
    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4

    Constraints:

    1 <= k <= nums.length <= 105
    -104 <= nums[i] <= 104
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min heap to keep the top k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // remove smallest among top k
            }
        }

        return minHeap.top(); // kth largest element
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "The " << k1 << "th largest element is: " << sol.findKthLargest(nums1, k1) << endl;

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "The " << k2 << "th largest element is: " << sol.findKthLargest(nums2, k2) << endl;

    return 0;
}
