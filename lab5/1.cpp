//Implement Stack as a Linked List
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

    T top() {
        if (head) return head->data;
        throw "List is empty";
    }

    void append(Node<T>* n) {
        if (!head) {
            head = n;
        } else {
            Node<T>* ptr = head;
            while (ptr->next) ptr = ptr->next;
            ptr->next = n;
        }
    }

    void prepend(Node<T>* n) {
        n->next = head;
        head = n;
    }

    void frontDelete() {
        if (!head) throw "List is empty";
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void endDelete() {
        if (!head) throw "List is empty";
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* ptr = head;
        while (ptr->next->next) ptr = ptr->next;
        delete ptr->next;
        ptr->next = nullptr;
    }

    void show() {
        Node<T>* ptr = head;
        while (ptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> s1;
    try {
        for (int i = 1; i <= 4; i++) {
            s1.append(new Node<int>(i));
        }
        cout << "Stack elements: ";
        s1.show();
        s1.frontDelete();
        cout << "After front delete: ";
        s1.show();
        cout << "Top is: " << s1.top() << endl;
    } catch (const char* err) {
        cout << err << endl;
    }
    return 0;
}
