/*
    Summary of Algorithm
    Insert first k+1 elements into a min heap.
    For every remaining element:
    Extract the minimum (put into result)
    Insert the next element into the heap
    Once all elements are processed, extract all remaining elements from the heap.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> sortKSortedArray(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> result;

    // Step 1: Push first k+1 elements into the min heap
    for (int i = 0; i <= k && i < arr.size(); i++) {
        minHeap.push(arr[i]);
    }

    // Step 2: For the rest of the elements
    for (int i = k + 1; i < arr.size(); i++) {
        result.push_back(minHeap.top());
        minHeap.pop();
        minHeap.push(arr[i]);
    }

    // Step 3: Pop remaining elements from the heap
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}

int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    vector<int> sortedArr = sortKSortedArray(arr, k);

    cout << "Sorted K-Sorted Array: ";
    for (int val : sortedArr)
        cout << val << " ";
    cout << endl;

    return 0;
}
