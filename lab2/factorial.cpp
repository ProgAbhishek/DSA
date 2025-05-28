#include <iostream>
using namespace std;

// Recursive function to compute factorial
long long factorial(int n) {
    if (n <= 1) return 1; // Base case: 0! = 1! = 1
    return n * factorial(n - 1); // Recursive case
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << num << " is " << factorial(num) << endl;
    }

    return 0;
}
