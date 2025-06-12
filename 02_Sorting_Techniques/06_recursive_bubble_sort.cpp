/*
    Recursive Bubble Sort Algorithm
    Problem Statement: Given an array of N integers, write a program to implement the Recursive Bubble Sort algorithm.

    Examples:

    Example 1:
    Input: N = 6, array[] = {13,46,24,52,20,9}
    Output: 9,13,20,24,46,52
    Explanation: After sorting we get 9,13,20,24,46,52

    Example 2:
    Input: N = 5, array[] = {5,4,3,2,1}
    Output: 1,2,3,4,5
    Explanation: After sorting we get 1,2,3,4,5
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void bubbleSort(vector<int>& nums, int n) {
        if(n == 1) return;
        bool swapped = false;
        for(int j = 0; j <= n - 2; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
                swapped = true;
            }
        }
        if (!swapped) return;
        bubbleSort(nums, n - 1);
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

    sol.bubbleSort(arr, arr.size());

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity: O(N2) for the worst and average cases and O(N) for the best case. Here, N = size of the array.

// Space Complexity: O(N) auxiliary stack space.