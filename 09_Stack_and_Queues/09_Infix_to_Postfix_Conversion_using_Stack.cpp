#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if character is operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Main function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            // Operand → directly add to postfix
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            // Pop till '('
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Remove '('
        }
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                if (c == '^' && st.top() == '^') break; // Right associative
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}
int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}

// Operation	Complexity
// Time	        O(n)
// Space	    O(n) (for stack and output string)