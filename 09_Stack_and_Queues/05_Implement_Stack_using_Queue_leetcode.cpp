/*
    225. Implement Stack using Queues
    Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

    Implement the MyStack class:

    void push(int x) Pushes element x to the top of the stack.
    int pop() Removes the element on the top of the stack and returns it.
    int top() Returns the element on the top of the stack.
    boolean empty() Returns true if the stack is empty, false otherwise.
    Notes:

    You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
    Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
    
    Example 1:

    Input
    ["MyStack", "push", "push", "top", "pop", "empty"]
    [[], [1], [2], [], [], []]
    Output
    [null, null, null, 2, 2, false]

    Explanation
    MyStack myStack = new MyStack();
    myStack.push(1);
    myStack.push(2);
    myStack.top(); // return 2
    myStack.pop(); // return 2
    myStack.empty(); // return False

    Constraints:

    1 <= x <= 9
    At most 100 calls will be made to push, pop, top, and empty.
    All the calls to pop and top are valid.

    Follow-up: Can you implement the stack using only one queue?
*/

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2; // main queue: q1, helper queue: q2

public:
    MyStack() {
        // constructor does nothing special
    }

    // Push element x onto stack.
    void push(int x) {
        q2.push(x); // Step 1: Push new element to q2

        // Step 2: Push all elements of q1 to q2 (reverse order)
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2
        swap(q1, q2);
    }

    // Removes the element on the top of the stack and returns it.
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    // Get the top element.
    int top() {
        return q1.front();
    }

    // Returns whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack* myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    cout << myStack->top() << endl;   // Output: 2
    cout << myStack->pop() << endl;   // Output: 2
    cout << (myStack->empty() ? "true" : "false") << endl; // Output: false
    return 0;
}
