/*
    Implement Stack using Arrays
    Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack should support the following operations: push, pop, peek, and isEmpty.

    Implement the ArrayStack class:

    void push(int x): Pushes element x onto the stack.
    int pop(): Removes and returns the top element of the stack.
    int top(): Returns the top element of the stack without removing it.
    boolean isEmpty(): Returns true if the stack is empty, false otherwise.

    Please note that this section might seem a bit difficult without prior knowledge on what stacks is, we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to give a shot to the problem. Cheers!


    Examples:
    Input: ["ArrayStack", "push", "push", "top", "pop", "isEmpty"]
    [[], [5], [10], [], [], []]
    Output: [null, null, null, 10, 10, false]
    Explanation:
    ArrayStack stack = new ArrayStack();
    stack.push(5);
    stack.push(10);
    stack.top(); // returns 10
    stack.pop(); // returns 10
    stack.isEmpty(); // returns false

    Input: ["ArrayStack","isEmpty", "push", "pop", "isEmpty"]
    [[], [], [1], [], []]
    Output: [null, true, null, 1, true]
    Explanation: 
    ArrayStack stack = new ArrayStack();
    stack.push(1);
    stack.pop(); // returns 1
    stack.isEmpty(); // returns true
*/

#include <iostream>
#include <vector>

using namespace std;

class ArrayStack {
private:
    int* arr;       // dynamically allocated array
    int topIndex;   // index of top element
    int capacity;   // maximum size of the stack

public:
    // Constructor to set custom size
    ArrayStack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Destructor to free allocated memory
    ~ArrayStack() {
        delete[] arr;
    }

    // TC O(1) SC O(capacity)
    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    // TC O(1) SC O(capacity)
    int pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[topIndex--];
    }

    // TC O(1) SC O(capacity)
    int top() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // TC O(1) SC O(capacity)
    bool isEmpty() {
        return topIndex == -1;
    }

    // TC O(1) SC O(capacity)
    int size() {
        return topIndex + 1;
    }
};

// Sample usage
int main() {
    int size;
    cout << "Enter size of stack: ";
    cin >> size;

    ArrayStack stack(size);

    stack.push(5);
    stack.push(10);

    cout << "Top: " << stack.top() << endl;     // 10
    cout << "Pop: " << stack.pop() << endl;     // 10
    cout << "Is Empty: " << (stack.isEmpty() ? "true" : "false") << endl;
    cout << "Size: " << stack.size() << endl;

    cout << "Pop: " << stack.pop() << endl;     // removes 5
    cout << "Is Empty: " << (stack.isEmpty() ? "true" : "false") << endl;

    return 0;
}
