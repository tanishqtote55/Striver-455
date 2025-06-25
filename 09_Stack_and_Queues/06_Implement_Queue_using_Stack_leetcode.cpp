/*
    232. Implement Queue using Stacks
    Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

    Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.
    Notes:

    You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
    

    Example 1:

    Input
    ["MyQueue", "push", "push", "peek", "pop", "empty"]
    [[], [1], [2], [], [], []]
    Output
    [null, null, null, 1, 1, false]

    Explanation
    MyQueue myQueue = new MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek(); // return 1
    myQueue.pop(); // return 1, queue is [2]
    myQueue.empty(); // return false
    

    Constraints:

    1 <= x <= 9
    At most 100 calls will be made to push, pop, peek, and empty.
    All the calls to pop and peek are valid.
    

    Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
*/

#include <iostream>
#include <stack>

using namespace std;

// class MyQueue {
// private:
//     stack<int> stack1, stack2;

// public:
//     MyQueue() {
//         // nothing to initialize
//     }

//     // Push element x to the back of queue
//     void push(int x) {
//         // Move all elements from stack1 to stack2
//         while (!stack1.empty()) {
//             stack2.push(stack1.top());
//             stack1.pop();
//         }

//         // Push new element to stack1
//         stack1.push(x);

//         // Move all elements back from stack2 to stack1
//         while (!stack2.empty()) {
//             stack1.push(stack2.top());
//             stack2.pop();
//         }
//     }

//     // Removes the element from the front of queue and returns it
//     int pop() {
//         if (stack1.empty()) {
//             cout << "Queue is empty" << endl;
//             return -1;
//         }
//         int val = stack1.top();
//         stack1.pop();
//         return val;
//     }

//     // Get the front element
//     int peek() {
//         if (stack1.empty()) {
//             cout << "Queue is empty" << endl;
//             return -1;
//         }
//         return stack1.top();
//     }

//     // Returns whether the queue is empty
//     bool empty() {
//         return stack1.empty();
//     }
// };

class MyQueue {
private:
    stack<int> inStack;   // For enqueue operations
    stack<int> outStack;  // For dequeue operations

public:
    MyQueue() {
        // No initialization needed beyond constructor
    }

    // Push element x to the back of queue
    void push(int x) {
        inStack.push(x);
    }

    // Removes the element from the front of queue and returns it
    int pop() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    // Get the front element
    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    // Returns whether the queue is empty
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

// Sample usage
int main() {
    MyQueue myQueue;

    myQueue.push(1);             // queue: [1]
    myQueue.push(2);             // queue: [1, 2]
    cout << myQueue.peek() << endl;  // return 1
    cout << myQueue.pop() << endl;   // return 1
    cout << (myQueue.empty() ? "true" : "false") << endl; // return false

    return 0;
}