/*
    Implement Queue using Arrays
    Implement a First-In-First-Out (FIFO) queue using an array. The implemented queue should support the following operations: push, dequeue, pop, and isEmpty.

    Implement the ArrayQueue class:

    void push(int x): Adds element x to the end of the queue.
    int pop(): Removes and returns the front element of the queue.
    int peek(): Returns the front element of the queue without removing it.
    boolean isEmpty(): Returns true if the queue is empty, false otherwise.

    Examples:
    Input:
    ["ArrayQueue", "push", "push", "peek", "pop", "isEmpty"]
    [[], [5], [10], [], [], []]
    Output: [null, null, null, 5, 5, false]
    Explanation:
    ArrayQueue queue = new ArrayQueue();
    queue.push(5);\
    queue.push(10);
    queue.peek(); // returns 5
    queue.pop(); // returns 5
    queue.isEmpty(); // returns false

    Input:
    ["ArrayQueue", "isEmpty"]
    [[]]
    Output:[null, true]
    Explanation:
    ArrayQueue queue = new ArrayQueue();
    queue.isEmpty(); // returns true
*/

#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;
public:
    ArrayQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        count = 0;
    }
    
    void push(int x) {
        if(count == capacity){
            cout << "Queue Overflow" << endl;
            return;
        }  
        if(count == 0){
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }    
        arr[rear] = x;
        count += 1;     
    }
    
    int pop() {
        if(count == 0){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int el = arr[front];
        if(count == 1){
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        count -= 1;
        return el;
    }
    
    int peek() {
        if(count == 0){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }
    
    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};

// Sample usage
int main() {
    ArrayQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << endl;    // 10
    cout << "Pop: " << q.pop() << endl;       // 10
    cout << "Is Empty: " << (q.isEmpty() ? "true" : "false") << endl;
    cout << "Size: " << q.size() << endl;     // 2

    return 0;
}

// | Operation | Time | Space       |
// | --------- | ---- | ----------- |
// | `push`    | O(1) | O(capacity) |
// | `pop`     | O(1) | O(capacity) |
// | `peek`    | O(1) | O(capacity) |
// | `isEmpty` | O(1) | O(capacity) |
// | `size`    | O(1) | O(capacity) |
