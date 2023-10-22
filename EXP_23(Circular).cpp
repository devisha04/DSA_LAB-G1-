#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert a new element at the end of the circular linked list.
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point back to itself to create a circular loop.
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; // Make the new node point to the head.
        }
    }

    // Display the elements in the circular linked list.
    void display() {
        if (head == nullptr) {
           cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
       cout << "Head" << std::endl;
    }
};

int main() {
    CircularLinkedList circularList;

    circularList.insert(1);
    circularList.insert(2);
    circularList.insert(3);

    std::cout << "Circular Linked List: ";
    circularList.display();

    return 0;
}
