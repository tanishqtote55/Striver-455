/*
    Check if an array represents a min heap
    Given an array of integers nums. Check whether the array represents a binary min-heap or not. Return true if it does, otherwise return false.

    A binary min-heap is a complete binary tree where the key at the root is the minimum among all keys present in a binary min-heap and the same property is recursively true for all nodes in a Binary Tree.

    Examples:
    Input: nums = [10, 20, 30, 21, 23]
    Output: true
    Explanation: Each node has a lower or equal value than its children.

    Input: nums = [10, 20, 30, 25, 15]
    Output: false
    Explanation: The node with value 20 has a child with value 15, thus it is not a min-heap.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isHeap(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= (n - 2) / 2; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && nums[i] > nums[left])
                return false;
            if (right < n && nums[i] > nums[right])
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<int> heap1 = {1, 3, 5, 7, 9, 6};  // Valid Min Heap
    vector<int> heap2 = {10, 15, 14, 25, 30}; // Valid Min Heap
    vector<int> notHeap = {10, 5, 20, 2};     // Not a Min Heap

    cout << "heap1 is a Min Heap? " << (sol.isHeap(heap1) ? "Yes" : "No") << endl;
    cout << "heap2 is a Min Heap? " << (sol.isHeap(heap2) ? "Yes" : "No") << endl;
    cout << "notHeap is a Min Heap? " << (sol.isHeap(notHeap) ? "Yes" : "No") << endl;

    return 0;
}
