#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a new element at the end of the list.
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Search for an element and print it.
    void searchAndPrint(int target) {
        Node* current = head;
        bool found = false;

        while (current != nullptr) {
            if (current->data == target) {
                found = true;
                std::cout << "Element " << target << " found in the linked list." << std::endl;
                break;
            }
            current = current->next;
        }

        if (!found) {
            std::cout << "Element " << target << " not found in the linked list." << std::endl;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);

    std::cout << "Linked List: ";
    list.display();

    list.searchAndPrint(2);

    return 0;
}
