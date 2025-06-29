#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Default constructor
    MinHeap() {}

    // Constructor from vector -> build heap
    MinHeap(const vector<int>& arr) {
        heap = arr;
        buildMinHeap();
    }

    // Build heap from current vector
    void buildMinHeap() {
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int top() {
        if (!heap.empty())
            return heap[0];
        throw out_of_range("Heap is empty");
    }

    void pop() {
        if (heap.empty())
            throw out_of_range("Heap is empty");
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    // Optional: print heap (for debug)
    void printHeap() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    vector<int> arr = {10, 5, 20, 2, 8};
    MinHeap pq(arr);  // Uses buildMinHeap()

    cout << "Initial Min-Heap: ";
    pq.printHeap();

    pq.push(1);
    cout << "After Inserting 1: ";
    pq.printHeap();

    cout << "Min Element: " << pq.top() << endl;

    pq.pop();
    cout << "After Popping Min: ";
    pq.printHeap();

    return 0;
}
