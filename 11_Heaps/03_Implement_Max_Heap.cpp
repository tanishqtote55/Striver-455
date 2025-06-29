#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Heapify down from index i
    void heapifyDown(int i) {
        int n = heap.size();
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < n && heap[l] > heap[largest])
            largest = l;
        if (r < n && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Heapify up from index i
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // 1. Initialize the heap
    void initializeHeap() {
        heap.clear();
    }

    // 2. Insert a value into max heap
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // 3. Change value at index
    void changeKey(int index, int new_val) {
        if (index < 0 || index >= heap.size()) return;

        int old_val = heap[index];
        heap[index] = new_val;

        if (new_val > old_val)
            heapifyUp(index);
        else
            heapifyDown(index);
    }

    // 4. Remove maximum element
    void extractMax() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // 5. Return max element
    int getMax() {
        if (heap.empty()) return -1; // or throw
        return heap[0];
    }

    // 6. Return current heap size
    int heapSize() {
        return heap.size();
    }

    // 7. Return if heap is empty
    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap heap;
    vector<string> operations = {
        "initializeheap", "insert", "insert", "insert",
        "getMax", "heapSize", "isEmpty",
        "extractMax", "changeKey", "getMax"
    };

    vector<vector<int>> nums = { {4}, {8}, {10}, {0, 5} };
    int numIdx = 0;

    for (string op : operations) {
        if (op == "initializeheap") {
            heap.initializeHeap();
            cout << "null" << endl;
        } else if (op == "insert") {
            int val = nums[numIdx++][0];
            heap.insert(val);
            cout << "null" << endl;
        } else if (op == "getMax") {
            cout << heap.getMax() << endl;
        } else if (op == "heapSize") {
            cout << heap.heapSize() << endl;
        } else if (op == "isEmpty") {
            cout << heap.isEmpty() << endl;
        } else if (op == "extractMax") {
            heap.extractMax();
            cout << "null" << endl;
        } else if (op == "changeKey") {
            int index = nums[numIdx][0];
            int value = nums[numIdx][1];
            numIdx++;
            heap.changeKey(index, value);
            cout << "null" << endl;
        }
    }

    return 0;
}
