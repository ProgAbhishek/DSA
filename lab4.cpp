// Program to implement a singly linked list with various operations
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at end
void insert_end(int info) {
    Node *ptr, *newNode;
    newNode = new Node();
    newNode->data = info;
    newNode->next = NULL;

    ptr = head;
    if (ptr != NULL) {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    } else {
        head = newNode;
    }
}

// Insert at beginning
void insert_beg(int info) {
    Node* newNode = new Node();
    newNode->data = info;
    newNode->next = head;
    head = newNode;
}

// Insert after specific value
void insert_after(int key, int info) {
    Node *ptr, *newNode;
    ptr = head;
    while (ptr != NULL && ptr->data != key)
        ptr = ptr->next;
    if (ptr == NULL) {
        cout << "Node not found\n";
        return;
    }
    newNode = new Node();
    newNode->data = info;
    newNode->next = ptr->next;
    ptr->next = newNode;
}

// Insert before specific value
void insert_before(int key, int info) {
    Node *ptr, *prev, *newNode;
    if (head == NULL) return;
    if (head->data == key) {
        insert_beg(info);
        return;
    }
    ptr = head;
    while (ptr != NULL && ptr->data != key) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        cout << "Node not found\n";
        return;
    }
    newNode = new Node();
    newNode->data = info;
    newNode->next = ptr;
    prev->next = newNode;
}

// Insert at position
void insert_pos(int pos, int info) {
    Node *ptr, *newNode;
    if (pos == 1) {
        insert_beg(info);
        return;
    }
    ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->next;
    if (ptr == NULL) {
        cout << "Position not found\n";
        return;
    }
    newNode = new Node();
    newNode->data = info;
    newNode->next = ptr->next;
    ptr->next = newNode;
}

// Delete from beginning
void delete_beg() {
    if (head == NULL) return;
    Node* ptr = head;
    head = head->next;
    delete ptr;
}

// Delete from end
void delete_end() {
    Node *ptr, *prev;
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    ptr = head;
    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    delete ptr;
}

// Delete after a value
void delete_after(int key) {
    Node *ptr, *temp;
    ptr = head;
    while (ptr != NULL && ptr->data != key)
        ptr = ptr->next;
    if (ptr == NULL || ptr->next == NULL) {
        cout << "Node not found or no node after it\n";
        return;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

// Delete at position
void delete_pos(int pos) {
    Node *ptr, *temp;
    if (head == NULL) return;
    if (pos == 1) {
        delete_beg();
        return;
    }
    ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->next;
    if (ptr == NULL || ptr->next == NULL) {
        cout << "Position not found\n";
        return;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

// Display list
void display() {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}

// Main menu using switch
int main() {
    int choice, info, key, pos;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Insert Before\n5. Insert at Position\n";
        cout << "6. Delete from Beginning\n7. Delete from End\n8. Delete After\n9. Delete at Position\n10. Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> info;
                insert_beg(info);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> info;
                insert_end(info);
                break;
            case 3:
                cout << "Insert after which value? ";
                cin >> key;
                cout << "Enter new data: ";
                cin >> info;
                insert_after(key, info);
                break;
            case 4:
                cout << "Insert before which value? ";
                cin >> key;
                cout << "Enter new data: ";
                cin >> info;
                insert_before(key, info);
                break;
            case 5:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter data: ";
                cin >> info;
                insert_pos(pos, info);
                break;
            case 6:
                delete_beg();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                cout << "Delete node after which value? ";
                cin >> key;
                delete_after(key);
                break;
            case 9:
                cout << "Enter position to delete: ";
                cin >> pos;
                delete_pos(pos);
                break;
            case 10:
                display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
