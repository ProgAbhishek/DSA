#include <iostream>
using namespace std;

// Recursive function to find the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) return 0;       // Base case
    if (n == 1) return 1;       // Base case
    return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive call
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
