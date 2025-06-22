#include <iostream>
#include <stack>
using namespace std;

// Helper function to insert an element in sorted order
void insertSorted(stack<int> &st, int element) {
    // Base case: empty stack or top is smaller
    if (st.empty() || element > st.top()) {
        st.push(element);
        return;
    }

    // Remove the top and recur
    int top = st.top();
    st.pop();
    insertSorted(st, element);

    // Push back the top
    st.push(top);
}

// Recursive function to sort the stack
void sortStack(stack<int> &st) {
    if (st.empty()) return;

    // Remove top element
    int top = st.top();
    st.pop();

    // Sort the remaining stack
    sortStack(st);

    // Insert the element in sorted order
    insertSorted(st, top);
}

// Utility function to print the stack
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// Driver Code
int main() {
    stack<int> st;

    // Sample input
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(5);

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    // Sort the stack
    sortStack(st);

    cout << "Sorted Stack (top to bottom): ";
    printStack(st);

    return 0;
}
