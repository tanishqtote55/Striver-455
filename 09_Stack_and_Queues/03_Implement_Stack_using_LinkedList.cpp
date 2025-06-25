/*

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
