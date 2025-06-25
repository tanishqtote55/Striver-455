/*
    Implement stack using Linkedlist
    Implement a Last-In-First-Out (LIFO) stack using a singly linked list. The implemented stack should support the following operations: push, pop, top, and isEmpty.

    Implement the LinkedListStack class:
    void push(int x): Pushes element x onto the stack.
    int pop(): Removes and returns the top element of the stack.
    int top(): Returns the top element of the stack without removing it.
    boolean isEmpty(): Returns true if the stack is empty, false otherwise.

    Examples:
    Input:
    ["LinkedListStack", "push", "push", "pop", "top", "isEmpty"]
    [[], [3], [7], [], [], []]
    Output: [null, null, null, 7, 3, false]
    Explanation:
    LinkedListStack stack = new LinkedListStack();
    stack.push(3);
    stack.push(7);
    stack.pop(); // returns 7
    stack.top(); // returns 3
    stack.isEmpty(); // returns false

    Input:
    ["LinkedListStack", "isEmpty"]
    [[]]
    Output: [null, true]
    Explanation:
    LinkedListStack stack = new LinkedListStack();
    stack.isEmpty(); // returns true
*/

#include <iostream>
using namespace std;

class LinkedListStack {
private:
    struct stackNode {
        int data;
        stackNode* next;
        stackNode(int d) {
            data = d;
            next = nullptr;
        }
    };

    stackNode* topNode; // top of the stack
    int size;

public:
    LinkedListStack() {
        topNode = nullptr;
        size = 0;
    }

    // TC O(1)
    void push(int x) {
        stackNode* newNode = new stackNode(x);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    // TC O(1)
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int val = topNode->data;
        stackNode* temp = topNode;
        topNode = topNode->next;
        delete temp;
        size--;
        return val;
    }

    // TC O(1)
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return topNode->data;
    }

    // TC O(1)
    bool isEmpty() {
        return topNode == nullptr;
    }

    // TC O(1)
    int getSize() {
        return size;
    }
};

int main() {
    LinkedListStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl;  // 30
    cout << "Popped: " << stack.pop() << endl;        // 30
    cout << "Popped: " << stack.pop() << endl;        // 20

    cout << "Is Empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;  // No
    cout << "Top element: " << stack.top() << endl;  // 10
    cout << "Size: " << stack.getSize() << endl;      // 1

    stack.pop();                                      // removes 10
    cout << "Is Empty now: " << (stack.isEmpty() ? "Yes" : "No") << endl;  // Yes

    return 0;
}

// | Operation | Time | Space         |
// | --------- | ---- | ------------- |
// | `push`    | O(1) | O(1) for node |
// | `pop`     | O(1) | O(1)          |
// | `top`     | O(1) | O(1)          |
// | `isEmpty` | O(1) | O(1)          |
// | `getSize` | O(1) | O(1)          |
