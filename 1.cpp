 #include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> st;
    string postfix;

    for(char ch : infix) {
        if(isalnum(ch)) {
            // Operand goes directly to the output
            postfix += ch;
        }
        else if(ch == '(') {
            st.push(ch);
        }
        else if(ch == ')') {
            // Pop until '('
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // pop '('
        }
        else if(isOperator(ch)) {
            // Pop operators with higher or equal precedence
            while(!st.empty() && precedence(st.top()) >= precedence(ch)) {
                if(ch == '^' && st.top() == '^') break; // Right associative for ^
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop any remaining operators
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
// This program converts an infix expression to postfix notation using the Shunting Yard algorithm.