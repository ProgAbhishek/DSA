#include <iostream>
#include <cmath>     // for pow()
using namespace std;

const int MAX = 100;

// Custom Stack class for integers
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
            return -1;  // Return dummy value
        } else {
            return arr[top--];
        }
    }

    T tos() const {  // Top of stack
        if (top >= 0)
            return arr[top];
        else
            return -1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void display() const {
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Helper function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Postfix evaluation function
void evaluatePostfix(const string &exp) {
    Stack<int> s;
    int operand1, operand2;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (c == ' ') continue;  // Skip spaces

        if (isdigit(c)) {
            s.push(c - '0');  // Convert char to int
        } else if (isOperator(c)) {
            operand2 = s.pop();
            operand1 = s.pop();

            switch (c) {
                case '^':
                    s.push(pow(operand1, operand2));
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
            }
        }
    }

    cout << "The result of the postfix expression \"" << exp << "\" = " << s.tos() << endl;
}

// Main function to run
int main() {
    string exp;
    cout << "Enter a postfix expression (single-digit operands only): ";
    getline(cin, exp);

    evaluatePostfix(exp);

    return 0;
}
