#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert Prefix to Infix
string prefixToInfix(string prefix) {
    stack<string> st;

    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            // Operand: push as string
            st.push(string(1, ch));
        }
        else if (isOperator(ch)) {
            // Pop two operands
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Create infix expression
            string expr = "(" + op1 + ch + op2 + ")";
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string prefix = "*+AB-CD";
    cout << "Prefix Expression: " << prefix << endl;

    string infix = prefixToInfix(prefix);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}

// Time Complexity: O(n) — each character is processed once.

// Space Complexity: O(n) — for the stack and intermediate expressions.