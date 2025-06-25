#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert postfix to prefix
string postfixToPrefix(string postfix) {
    stack<string> st;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            // Operand: push as a string
            st.push(string(1, ch));
        } else if (isOperator(ch)) {
            // Pop two operands
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            // Combine: operator + operand1 + operand2
            string expr = ch + op1 + op2;
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string postfix = "ab+cd-*";

    cout << "Postfix Expression: " << postfix << endl;

    string prefix = postfixToPrefix(postfix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}

// | Complexity Type  | Value |
// | ---------------- | ----- |
// | Time Complexity  | O(n)  |
// | Space Complexity | O(n)  |
