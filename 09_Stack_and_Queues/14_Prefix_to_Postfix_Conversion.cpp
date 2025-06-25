#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert prefix to postfix
string prefixToPostfix(const string& prefix) {
    stack<string> st;

    // Traverse from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            st.push(string(1, ch)); // Operand
        } else if (isOperator(ch)) {
            // Pop two operands
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            // Combine as: operand1 + operand2 + operator
            string expr = op1 + op2 + ch;
            st.push(expr);
        }
    }

    return st.top();
}

int main() {
    string prefix = "*+AB-CD";

    cout << "Prefix Expression: " << prefix << endl;

    string postfix = prefixToPostfix(prefix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}

// | Complexity Type  | Value |
// | ---------------- | ----- |
// | Time Complexity  | O(n)  |
// | Space Complexity | O(n)  |
