// Reverse the infix - Change Opening Bracket to Closing Bracket and vice-versa
// Infix to Postfix  - Equal Priority Operator should be pushed into the stack without popping out the previous one
// Reverse the answer

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Helper: get precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Check if character is operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Convert infix to postfix
string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (char c : s) {
        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        else if (isOperator(c)) {
            // Equal Priority Operator should be pushed into the stack without popping out the previous one
            while (!st.empty() && precedence(st.top()) > precedence(c) ||
                   (precedence(st.top()) == precedence(c) && c != '^')) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

// Convert infix to prefix
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    // Swap '(' with ')' and vice versa
    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string infix = "(a-b/c)*(a/k-l)";
    cout << "Infix:   " << infix << endl;
    cout << "Prefix:  " << infixToPrefix(infix) << endl;
    return 0;
}
