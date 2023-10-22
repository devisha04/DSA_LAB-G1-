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

    void deleteAtEnd() {
        if (head == nullptr) {
            std::cout << "Linked list is empty. Cannot delete." << std::endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
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

    list.deleteAtEnd();
    std::cout << "After deleting the last element: ";
    list.display();

    return 0;
}
