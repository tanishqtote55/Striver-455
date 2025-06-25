/*
    155. Min Stack
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.
    You must implement a solution with O(1) time complexity for each function.

    Example 1:

    Input
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]

    Output
    [null,null,null,null,-3,null,0,-2]

    Explanation
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
    
    Constraints:

    -231 <= val <= 231 - 1
    Methods pop, top and getMin operations will always be called on non-empty stacks.
    At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
        // Constructor - nothing to initialize
    }
    // TC O(1) SC O(2*N)
    void push(int val) {
        if (st.empty()) {
            st.push({val, val}); // both value and min are val
        } else {
            int currentMin = min(val, st.top().second);
            st.push({val, currentMin});
        }
    }
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};


class MinStack {
private:
    stack<long long> st;
    long long minElement;

public:
    MinStack() {
        minElement = 0;
    }
    // TC O(1) SC O(N)
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minElement = val;
        } else {
            if (val >= minElement) {
                st.push(val);
            } else {
                // Encode the new value
                st.push(2LL * val - minElement);
                minElement = val;
            }
        }
    }
    void pop() {
        if (st.empty()) return;
        long long top = st.top();
        st.pop();
        if (top < minElement) {
            // Recover the previous minElement
            minElement = 2LL * minElement - top;
        }
    }
    int top() {
        long long top = st.top();
        if (top >= minElement) {
            return top;
        } else {
            // Encoded value, return current minElement
            return minElement;
        }
    }
    int getMin() {
        return minElement;
    }
};

int main() {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << ms.getMin() << endl; // -3
    ms.pop();
    cout << ms.top() << endl;    // 0
    cout << ms.getMin() << endl; // -2
    return 0;
}