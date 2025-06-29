// This program adds two polynomial equations represented as linked lists and displays the result in polar form.

#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node* next;

    Node(T dataIn = T(), Node* nextIn = nullptr) : data(dataIn), next(nextIn) {}
};

template <class T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void append(Node<T>* n) {
        if (!head) {
            head = n;
        } else {
            Node<T>* ptr = head;
            while (ptr->next) ptr = ptr->next;
            ptr->next = n;
        }
    }

    Node<T>* giveHead() {
        return head;
    }
};

template <class T>
LinkedList<T> add(LinkedList<T> l1, LinkedList<T> l2) {
    LinkedList<T> result;
    Node<T>* ptr1 = l1.giveHead();
    Node<T>* ptr2 = l2.giveHead();

    while (ptr1 || ptr2) {
        T sum = (ptr1 ? ptr1->data : 0) + (ptr2 ? ptr2->data : 0);
        result.append(new Node<T>(sum));
        if (ptr1) ptr1 = ptr1->next;
        if (ptr2) ptr2 = ptr2->next;
    }
    return result;
}

template <class T>
void displayPolar(LinkedList<T> list, int degree) {
    Node<T>* ptr = list.giveHead();
    for (int count = 0; ptr; count++) {
        if (count > 0 && ptr->data != 0) cout << "+";
        if (ptr->data != 0) {
            cout << ptr->data;
            if (count > 0) cout << "x^" << count;
        }
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    int degree, temp;
    LinkedList<int> l1, l2;
    cout << "Enter the degree of polynomial equation: ";
    cin >> degree;

    try {
        cout << "For the first polynomial equation, enter coefficients (spaces in between): ";
        for (int i = 0; i <= degree; i++) {
            cin >> temp;
            l1.append(new Node<int>(temp));
        }

        cout << "For the second polynomial equation, enter coefficients (spaces in between): ";
        for (int i = 0; i <= degree; i++) {
            cin >> temp;
            l2.append(new Node<int>(temp));
        }

        cout << "\nThe addition of the polynomials gives: ";
        displayPolar(add(l1, l2), degree);
    } catch (const char* err) {
        cout << err << endl;
    }
    return 0; 
}
