#include <iostream>

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int value) : data(value), next(nullptr) {}
};

// Function to find the length of a linked list.
int getLength(ListNode* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the merge point of two linked lists.
ListNode* findMergePoint(ListNode* head1, ListNode* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Move the pointer of the longer list ahead by the difference in lengths.
    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }
    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    // Now, both pointers are equidistant from the merge point.
    while (head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1;  // Return the merge point, or nullptr if there is no merge point.
}

int main() {
    // Create two linked lists with a common merge point.
    ListNode* common = new ListNode(7);
    common->next = new ListNode(8);
    common->next->next = new ListNode(9);

    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = common;

    ListNode* head2 = new ListNode(4);
    head2->next = new ListNode(5);
    head2->next->next = common;

    // Find the merge point and print the data.
    ListNode* mergePoint = findMergePoint(head1, head2);
    if (mergePoint != nullptr) {
        std::cout << "Merge Point Data: " << mergePoint->data << std::endl;
    } else {
        std::cout << "No merge point found." << std::endl;
    }

    return 0;
}
