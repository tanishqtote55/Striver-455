#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthSmallest(vector<int>& nums, int k) {
        // Max heap to store k smallest elements
        priority_queue<int> maxHeap;

        for (int num : nums) {
            maxHeap.push(num);
            if (maxHeap.size() > k) {
                maxHeap.pop(); // remove largest among the k smallest
            }
        }

        return maxHeap.top(); // kth smallest element
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    cout << "The " << k1 << "th smallest element is: " << sol.findKthSmallest(nums1, k1) << endl;

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    cout << "The " << k2 << "th smallest element is: " << sol.findKthSmallest(nums2, k2) << endl;

    return 0;
}
