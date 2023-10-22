#include <iostream>
using namespace std;
class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
           cout << "Stack overflow. Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow. Cannot pop from an empty stack." << endl;
            return -1; // You can return a specific value to indicate an error.
        }
        return arr[top--];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
bool isFull() {
        return top == capacity - 1;
    }
    // Function to get the top element of the stack
    int topele() {
        if (isEmpty()) {
            cout << "Stack is empty." << std::endl;
            return -1; // You can return a specific value to indicate an error.
        }
        return arr[top];
    }
};

int main() {
    Stack stack(5); // Create a stack with a capacity of 5

    stack.push(10);
    stack.push(20);
    stack.push(30);

   cout << "Top element: " << stack.topele() << endl;

    cout << "Popped element: " << stack.pop() << endl;

    cout << "Top element: " << stack.topele() << endl;

    return 0;
}
