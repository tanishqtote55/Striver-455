/*
    Convert Min Heap to Max Heap
    Given a min-heap in array representation named nums, convert it into a max-heap and return the resulting array.

    A min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in the Binary Tree.

    A max-heap is a complete binary tree where the key at the root is the maximum among all keys present in a binary max-heap and the same property is recursively true for all nodes in the Binary Tree.

    Since there can be multiple answers, the compiler will return true if it's correct, else false.

    Examples:
    Input: nums = [10, 20, 30, 21, 23]
    Output: [30, 21, 23, 10, 20]
    Explanation:
    Input: nums = [-5, -4, -3, -2, -1]
    Output: [-1, -2, -3, -4, -5]
    Explanation:
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    // Max-heapify: ensures subtree rooted at i satisfies max-heap
    void heapifyDown(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest])
            largest = left;
        if (right < n && nums[right] > nums[largest])
            largest = right;

        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapifyDown(nums, n, largest);
        }
    }
public:
    vector<int> minToMaxHeap(vector<int> nums) {
        int n = nums.size();
        // Start from the last internal node and heapify down
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(nums, n, i);
        }
        return nums;
    }
};

int main() {
    Solution sol;

    vector<int> minHeap1 = {10, 20, 30, 21, 23};
    vector<int> minHeap2 = {-5, -4, -3, -2, -1};

    vector<int> maxHeap1 = sol.minToMaxHeap(minHeap1);
    vector<int> maxHeap2 = sol.minToMaxHeap(minHeap2);

    cout << "Converted MaxHeap1: ";
    for (int val : maxHeap1) cout << val << " ";
    cout << endl;

    cout << "Converted MaxHeap2: ";
    for (int val : maxHeap2) cout << val << " ";
    cout << endl;

    return 0;
}
