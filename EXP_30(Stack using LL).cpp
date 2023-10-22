#include <iostream>
using namespace std;
// Define a structure for a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() {
        top = nullptr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << std::endl;
            return -1; // You can return a specific value to indicate an error.
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to get the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << std::endl;
            return -1; // You can return a specific value to indicate an error.
        }
        return top->data;
    }

    // Function to display the stack
    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << std::endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.peek() << std::endl;

    cout << "Popped element: " << stack.pop() << std::endl;

    cout << "Top element: " << stack.peek() << std::endl;

   cout << "Stack contents: ";
    stack.display();

    return 0;
}
