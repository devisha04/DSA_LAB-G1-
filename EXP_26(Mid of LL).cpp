#include <iostream>

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a new element at the end of the linked list.
    void insert(int value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Find and return the middle node of the linked list.
    ListNode* findMiddle() {
        if (head == nullptr) {
            return nullptr;  // Empty list, no middle.
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Move one step at a time.
            fast = fast->next->next; // Move two steps at a time.
        }

        return slow;  // Slow pointer is at the middle node.
    }

    void display() {
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    std::cout << "Linked List: ";
    list.display();

    ListNode* middleNode = list.findMiddle();
    if (middleNode != nullptr) {
        std::cout << "Middle Node: " << middleNode->data << std::endl;
    } else {
        std::cout << "The list is empty; there is no middle node." << std::endl;
    }

    return 0;
}
