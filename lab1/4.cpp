#include <iostream>
using namespace std;

const int MAX = 100;

// Custom Stack class for characters
template <typename T>
class Stack {
private:
    T arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(T val) {
        if (top >= MAX - 1)
            cout << "Stack Overflow\n";
        else
            arr[++top] = val;
    }

    T pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return '\0';
        } else {
            return arr[top--];
        }
    }

    T tos() const {
        if (top >= 0)
            return arr[top];
        else
            return '\0';
    }

    bool isEmpty() const {
        return top == -1;
    }
};

// Returns the matching opening bracket for a given closing bracket
char pairOf(char c) {
    return (c == ')') ? '(' : (c == '}') ? '{' : '[';
}

// Function to check for balanced parentheses
void checkParenthesis(const string &exp) {
    Stack<char> s;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty() || s.tos() != pairOf(c)) {
                cout << exp << " = Parenthesis not balanced" << endl;
                return;
            }
            s.pop();
        }
    }

    if (s.isEmpty())
        cout << exp << " = Balanced parenthesis" << endl;
    else
        cout << exp << " = Parenthesis not balanced" << endl;
}

// Main function to test
int main() {
    string expression;
    cout << "Enter a mathematical expression: ";
    getline(cin, expression);

    checkParenthesis(expression);

    return 0;
}
