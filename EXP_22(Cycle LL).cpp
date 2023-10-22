#include <iostream>
using namespace std;
class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int value) : data(value), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;  // No cycle if the list is empty or has only one element.
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       // Move one step at a time.
        fast = fast->next->next; // Move two steps at a time.

        if (slow == fast) {
            return true;  // If they meet, there is a cycle.
        }
    }

    return false;  // If fast reaches the end of the list, there is no cycle.
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    // Uncomment the next line to create a cycle.
    // node5->next = node2;

    bool hasCycleResult = hasCycle(head);
    if (hasCycleResult) {
        cout << "The linked list contains a cycle." << std::endl;
    } else {
        cout << "The linked list does not contain a cycle." << std::endl;
    }

    return 0;
}
