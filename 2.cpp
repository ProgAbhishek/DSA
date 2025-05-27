#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to check precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Function to check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
    char c = infix[i];
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        } else if (isOperator(c)) {
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Infix to Prefix
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());

    // Swap ( with )
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

// Main
int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;

    return 0;
}

