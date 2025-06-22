#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert at bottom of stack
void insertAtBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }

    int top = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(top);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}

// Utility function to print the stack (top to bottom)
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// Driver code
int main() {
    stack<int> st;

    // Push elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed Stack (top to bottom): ";
    printStack(st);

    return 0;
}
