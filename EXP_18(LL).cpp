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

    // Insert a new element at a specified position in the list.
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        int index = 0;

        while (current != nullptr && index < position - 1) {
            current = current->next;
            index++;
        }

        if (current == nullptr) {
         cout << "Invalid position for insertion." << std::endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Delete the element at a specified position in the list.
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "Linked list is empty. Cannot delete." << std::endl;
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        int index = 0;

        while (current != nullptr && index < position - 1) {
            current = current->next;
            index++;
        }

        if (current == nullptr || current->next == nullptr) {
            cout << "Invalid position for deletion." << std::endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
           cout << current->data << " -> ";
            current = current->next;
        }
       cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtPosition(1, 0);
    list.insertAtPosition(2, 1);
    list.insertAtPosition(3, 2);

    cout << "Linked List: ";
    list.display();

    list.deleteAtPosition(1);
    std::cout << "After deleting element at position 1: ";
    list.display();

    return 0;
}

