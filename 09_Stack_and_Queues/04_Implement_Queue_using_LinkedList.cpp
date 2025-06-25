/*
    Implement queue using Linkedlist
    Implement a First-In-First-Out (FIFO) queue using a singly linked list. The implemented queue should support the following operations: push, pop, peek, and isEmpty.

    Implement the LinkedListQueue class:
    void push(int x): Adds element x to the end of the queue.
    int pop(): Removes and returns the front element of the queue.
    int peek(): Returns the front element of the queue without removing it.
    boolean isEmpty(): Returns true if the queue is empty, false otherwise.

    Examples:
    Input:
    ["LinkedListQueue", "push", "push", "peek", "pop", "isEmpty"]
    [[], [3], [7], [], [], []]
    Output:[null, null, null, 3, 3, false]
    Explanation:
    LinkedListQueue queue = new LinkedListQueue();
    queue.push(3);
    queue.push(7);
    queue.peek(); // returns 3
    queue.pop(); // returns 3
    queue.isEmpty(); // returns false

    Input:
    ["LinkedListQueue", "push", "pop", "isEmpty"]
    [[], [2], [], []]
    Output: [null, null, 2, true]
    Explanation:
    LinkedListQueue queue = new LinkedListQueue();
    queue.push(2);
    queue.pop(); // returns 2
    queue.isEmpty(); // returns true
*/

#include <iostream>
using namespace std;

class LinkedListQueue {
private:
    struct queueNode {
        int data;
        queueNode* next;
        queueNode(int d) {
            data = d;
            next = nullptr;
        }
    };
    queueNode* front;
    queueNode* rear;
    int size;

public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }
    
    void push(int x) {
        queueNode* newNode = new queueNode(x);
        if(rear == nullptr){
            // Queue is Empty
            front = rear = newNode;
        } else {
            rear -> next = newNode;
            rear = newNode;
        }
        size++;
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int val = front -> data;
        queueNode* temp = front;
        front = front -> next;
        if(front == nullptr){
            //Queue Becomes Empty
            rear = nullptr;
        }
        size--;
        delete temp;
        return val;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    
    bool isEmpty() {
        return front == nullptr;
    }
    
    int getSize() {
        return size;
    }
};

int main() {
    LinkedListQueue q;

    q.push(3);
    q.push(7);

    cout << "Peek: " << q.peek() << endl;      // 3
    cout << "Pop: " << q.pop() << endl;        // 3
    cout << "Is Empty: " << (q.isEmpty() ? "true" : "false") << endl; // false
    cout << "Size: " << q.getSize() << endl;   // 1

    q.pop();                                   // removes 7
    cout << "Is Empty: " << (q.isEmpty() ? "true" : "false") << endl; // true

    return 0;
}
