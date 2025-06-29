/*
    Implement Min Heap
    You need to implement the Min Heap with the following given methods.

    insert (x) -> insert value x to the min heap
    getMin -> Output the minimum value from min heap
    exctractMin -> Remove the minimum element from the heap
    heapSize -> return the current size of the heap
    isEmpty -> returns if heap is empty or not
    changeKey (ind, val) -> update the value at given index to val (index will be given 0-based indexing)
    initializeHeap -> Initialize the heap

    Examples:
    Input : operation = [ "initializeheap", "insert", "insert", "insert", "getMin", "heapSize", "isEmpty", "extractMin", "changeKey" , "getMin" ]
    nums = [ [4], [1], [10], [0, 16] ]
    Output : [ null, null, null, null, 1, 3, 0, null, null, 10 ]
    Explanation : In 1st operation we initialize the heap to empty heap.
    In 2nd, 3rd, 4th operation we insert 4, 1, 10 to the heap respectively. The heap after 4th operation will be -> [1, 4, 10].
    In 5th operation we output the minimum element from the heap i.e. 1.
    In 6th operation we output the size of the current heap i.e. 3.
    In 7th operation we output whether the heap is empty or not i.e. false (0).
    In 8th operation we remove the minimum element from heap. So the ne heap becomes -> [4, 10].
    In 9th operation we change the 0th index element to 16. So new heap becomes -> [16, 10]. After heapify -> [10, 16].
    In 10th operation we output the minimum element of the heap i.e. 10.

    Input : operation = [ "initializeheap", "insert", "insert", "extractMin", "getMin", "insert", "heapSize", "isEmpty", "extractMin", "changeKey" , "getMin" ]
    nums = [ [4], [1], [1], [0, 2] ]
    Output : [ null, null, null, null, 4, null, 2, 0, null, null, 2 ]
    Explanation : In 1st operation we initialize the heap to empty heap.
    In 2nd, 3rd operation we insert 4, 1 to the heap respectively. The heap after 4th operation will be -> [1, 4].
    In 4th operation we remove the minimum element from heap. So the ne heap becomes -> [4].
    In 5th operation we output the minimum element of the heap i.e. 4.
    In 6th operation we operation we insert 1 to the heap. The heap after 6th operation will be -> [1, 4].
    In 7th operation we output the size of the current heap i.e. 2.
    In 8th operation we output whether the heap is empty or not i.e. false (0).
    In 9th operation we remove the minimum element from heap. So the ne heap becomes -> [4].
    In 10th operation we change the 0th index element to 2. So new heap becomes -> [2].
    In 11th operation we output the minimum element of the heap i.e. 2.

    Constraints:
    1 <= n <= 105
    -105 <= nums[i] <= 105
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Heapify down from index i
    void heapifyDown(int i) {
        int n = heap.size();
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < n && heap[l] < heap[smallest])
            smallest = l;
        if (r < n && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Heapify up from index i
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // 1. Initialize empty heap
    void initializeHeap() {
        heap.clear();
    }

    // 2. Insert key into heap
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    // 3. Change value at given index
    void changeKey(int index, int new_val) {
        if (index < 0 || index >= heap.size()) return;

        int old_val = heap[index];
        heap[index] = new_val;

        if (new_val < old_val)
            heapifyUp(index);
        else
            heapifyDown(index);
    }

    // 4. Remove minimum element
    void extractMin() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // 5. Return true if heap is empty
    bool isEmpty() {
        return heap.empty();
    }

    // 6. Get minimum element
    int getMin() {
        if (heap.empty()) return -1; // or throw error
        return heap[0];
    }

    // 7. Return current size
    int heapSize() {
        return heap.size();
    }
};


int main() {
    Solution heap;
    vector<string> operations = { "initializeheap", "insert", "insert", "insert", "getMin", "heapSize", "isEmpty", "extractMin", "changeKey", "getMin" };
    vector<vector<int>> nums = { {4}, {1}, {10}, {0, 16} };

    int numIdx = 0;

    for (string op : operations) {
        if (op == "initializeheap") {
            heap.initializeHeap();
            cout << "null" << endl;
        } else if (op == "insert") {
            int val = nums[numIdx++][0];
            heap.insert(val);
            cout << "null" << endl;
        } else if (op == "getMin") {
            cout << heap.getMin() << endl;
        } else if (op == "heapSize") {
            cout << heap.heapSize() << endl;
        } else if (op == "isEmpty") {
            cout << heap.isEmpty() << endl;
        } else if (op == "extractMin") {
            heap.extractMin();
            cout << "null" << endl;
        } else if (op == "changeKey") {
            int ind = nums[numIdx][0];
            int val = nums[numIdx][1];
            numIdx++;
            heap.changeKey(ind, val);
            cout << "null" << endl;
        }
    }

    return 0;
}
