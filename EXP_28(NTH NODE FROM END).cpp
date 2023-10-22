#include <iostream>
using namespace std;

// Define a structure for a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the nth node from the end of a linked list
void printNthFromEnd(Node* head, int n) {
    if (head == nullptr || n <= 0) {
        cout << "Invalid input or empty list." << std::endl;
        return;
    }

    Node* firstPointer = head;
    Node* secondPointer = head;

    // Move the second pointer n nodes ahead
    for (int i = 0; i < n; i++) {
        if (secondPointer == nullptr) {
            cout << "List is not long enough." << std::endl;
            return;
        }
        secondPointer = secondPointer->next;
    }

    // Move both pointers until the second pointer reaches the end
    while (secondPointer != nullptr) {
        firstPointer = firstPointer->next;
        secondPointer = secondPointer->next;
    }

   cout << "The " << n << "th node from the end is: " << firstPointer->data << std::endl;
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original Linked List: ";
    displayList(head);

    int n;
  cout << "Enter the value of n: ";
    cin >> n;

    printNthFromEnd(head, n);

    return 0;
}
