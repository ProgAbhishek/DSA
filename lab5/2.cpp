//Implement a queue using a linked list
#include <iostream>
using namespace std;

constexpr auto queuesize = 5;

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

    void frontDelete() {
        if (!head) throw "List is empty";
        Node<T>* temp = head;
        head = head->next;
        delete temp;
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

template <class T>
class Queue {
private:
    int count;
    LinkedList<T> list;

public:
    Queue() : count(0) {}

    void enqueue(T data) {
        if (count >= queuesize) throw "Queue overflow";
        Node<T>* n = new Node<T>(data);
        list.append(n);
        count++;
    }

    void dequeue() {
        if (count <= 0) throw "Queue underflow";
        list.frontDelete();
        count--;
    }

    void show() {
        list.show();
    }
};

int main() {
    try {
        Queue<int> q;
        for (int i = 1; i <= 4; i++) q.enqueue(i);
        q.dequeue();
        cout << "Queue elements after dequeue: ";
        q.show();
    } catch (const char* err) {
        cout << err << endl;
    }
    return 0; 
}
