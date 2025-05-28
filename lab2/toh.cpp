#include<iostream>
using namespace std;

//Recursive function to solve Tower of Hanoi
void toh(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    toh(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    toh(n - 1, auxiliary, destination, source);
}

int main() {
    int n; 
    cout << "Enter the number of disks: ";
    cin >> n;
    
   
    toh(n, 'A', 'B', 'C'); // A, B and C are names of rods
    
    return 0;
}