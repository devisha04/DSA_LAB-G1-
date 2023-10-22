#include <iostream>
using namespae std;
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
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; // An empty list or a single node is always a palindrome
    }

    // Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    slow = reverseLinkedList(slow);

    // Compare the first half and the reversed second half
    while (slow != nullptr) {
        if (head->data != slow->data) {
            return false; // Not a palindrome
        }
        head = head->next;
        slow = slow->next;
    }

    return true; // It's a palindrome
}

int main() {
    // Create a sample linked list that is a palindrome
    Node* head = new Node(11);
    head->next = new Node(21);
    head->next->next = new Node(31);
    head->next->next->next = new Node(21);
    head->next->next->next->next = new Node(11);

  cout << "Is the linked list a palindrome? " << (isPalindrome(head) ? "Yes" : "No") << std::endl;

    return 0;
}
