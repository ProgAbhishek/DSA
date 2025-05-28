#include <iostream>
using namespace std;

// Tail-recursive helper function
int fibonacciTail(int n, int a = 0, int b = 1) {
    if (n == 0) return a;
    if (n == 1) return b;
    return fibonacciTail(n - 1, b, a + b);  // Tail-recursive call
}

// Wrapper function (optional)
int fibonacci(int n) {
    return fibonacciTail(n);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Fibonacci is not defined for negative numbers." << endl;
    } else {
        cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;
    }

    return 0;
}
