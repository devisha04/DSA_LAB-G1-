#include <iostream>
using namespace std;
// Define a structure for a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a linked list
Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Save the next node
        current->next = prev; // Reverse the pointer
        prev = current; // Move to the next nodes
        current = next;
    }

    return prev; // New head of the reversed list
}

// Function to display a linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
       cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a sample linked list
    Node* head = new Node(7);
    head->next = new Node(8);
    head->next->next = new Node(9);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(11);

    cout << "Original Linked List: ";
    displayList(head);

    // Reverse the linked list
    Node* reversedHead = reverseLinkedList(head);

  cout << "Reversed Linked List: ";
    displayList(reversedHead);

    return 0;
}
