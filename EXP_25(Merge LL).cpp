#include <iostream>
using namespace std;
// Define a structure for a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* list1, Node* list2) {
    Node dummy(0); // Create a dummy node to simplify list construction
    Node* current = &dummy;

    while (list1 && list2) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Append any remaining elements from list1 or list2
    if (list1) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return dummy.next; // Return the merged list
}

// Function to display a linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
  cout << "nullptr" << std::endl;
}

int main() {
    // Create two sorted linked lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

   cout << "List 1: ";
    displayList(list1);

   cout << "List 2: ";
    displayList(list2);

    // Merge the two sorted linked lists
    Node* mergedList = mergeSortedLists(list1, list2);

   cout << "Merged List: ";
    displayList(mergedList);

    return 0;
}
