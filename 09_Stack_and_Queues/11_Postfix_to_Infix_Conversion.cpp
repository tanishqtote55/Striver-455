#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToInfix(string postfix) {
    stack<string> st;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            // If it's an operand (letter or digit)
            st.push(string(1, ch)); // string(1, ch) creates a string of length 1 with the character ch.
        } else if (isOperator(ch)) {
            // Pop two operands
            string right = st.top(); st.pop();
            string left = st.top(); st.pop();
            string expr = "(" + left + ch + right + ")";
            st.push(expr);
        }
    }

    return st.top(); // Final infix expression
}

int main() {
    // You can modify this postfix expression for testing
    string postfix = "ab+c*";

    cout << "Postfix Expression: " << postfix << endl;

    string infix = postfixToInfix(postfix);
    cout << "Converted Infix Expression: " << infix << endl;

    return 0;
}

// Complexity Type	Value
// Time	            O(n)
// Space	        O(n)