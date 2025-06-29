//Doubly linked List 
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d = 0) : data(d), next(NULL), prev(NULL) {}
};

class DLinkedList {
private:
    Node* head;

public:
    DLinkedList() : head(NULL) {}

    Node* giveHead() {
        return head;
    }

    Node* nodeExists(int data) {
        Node* ptr = head;
        while (ptr != NULL) {
            if (data == ptr->data) return ptr;
            ptr = ptr->next;
        }
        return NULL; // Return NULL if node doesn't exist
    }

    void insertStart(Node* n) {
        if (head == NULL) {
            head = n;
        } else {
            head->prev = n;
            n->next = head;
            head = n;
        }
    }

    void insertEnd(Node* n) {
        if (head == NULL) {
            head = n;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL) ptr = ptr->next;
            ptr->next = n;
            n->prev = ptr;
        }
    }

    void insertAfter(int data, Node* n) {
        Node* ptr = nodeExists(data);
        if (ptr) {
            n->next = ptr->next;
            n->prev = ptr;
            if (ptr->next) {
                ptr->next->prev = n;
            }
            ptr->next = n;
        }
    }

    void insertBefore(int data, Node* n) {
        Node* ptr = nodeExists(data);
        if (ptr) {
            n->next = ptr;
            n->prev = ptr->prev;
            if (ptr->prev) {
                ptr->prev->next = n;
            } else {
                head = n; // Update head if inserting before the first node
            }
            ptr->prev = n;
        }
    }

    void deleteFirst() {
        if (head) {
            head = head->next;
            if (head) head->prev = NULL;
        }
    }

    void deleteEnd() {
        if (head) {
            Node* ptr = head;
            while (ptr->next != NULL) ptr = ptr->next;
            if (ptr->prev) {
                ptr->prev->next = NULL;
            } else {
                head = NULL; // List becomes empty
            }
        }
    }

    void deleteAfter(int data) {
        Node* ptr = nodeExists(data);
        if (ptr && ptr->next) {
            Node* toDelete = ptr->next;
            ptr->next = toDelete->next;
            if (toDelete->next) {
                toDelete->next->prev = ptr;
            }
            delete toDelete; // Free memory
        }
    }

    void deleteBefore(int data) {
        Node* ptr = nodeExists(data);
        if (ptr && ptr->prev) {
            Node* toDelete = ptr->prev;
            if (toDelete->prev) {
                toDelete->prev->next = ptr;
                ptr->prev = toDelete->prev;
            } else {
                head = ptr; // Update head if deleting the first node
                ptr->prev = NULL;
            }
            delete toDelete; // Free memory
        }
    }

    void show() {
        Node* ptr = head;
        cout << "The data are: ";
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    DLinkedList d;
    Node n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    d.insertStart(&n1);
    d.insertEnd(&n2);
    d.show();
    d.insertAfter(2, &n3);
    d.show();
    d.insertAfter(2, &n4);
    d.show();
    d.insertBefore(3, &n5);
    d.show();
    d.insertBefore(4, &n6);
    d.show();
    d.deleteBefore(2);
    d.show();
    d.deleteAfter(2);
    d.show();
    d.deleteFirst();
    d.show();
    d.deleteEnd();
    d.show();
    
    return 0; 
}
