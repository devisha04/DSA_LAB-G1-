#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert a new element at the end of the doubly linked list.
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Display the elements in the doubly linked list from head to tail.
    void displayForward() {
        Node* current = head;
        while (current != nullptr) {
            scout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Display the elements in the doubly linked list from tail to head.
    void displayBackward() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "nullptr" << std::endl;
    }
};

int main() {
    DoublyLinkedList doublyList;

    doublyList.insert(1);
    doublyList.insert(2);
    doublyList.insert(3);

 cout << "Doubly Linked List (Forward): ";
    doublyList.displayForward();

   cout << "Doubly Linked List (Backward): ";
    doublyList.displayBackward();

    return 0;
}
