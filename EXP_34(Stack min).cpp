#include <iostream>
#include <stack>

class MinStack {
private:
    std::stack<int> mainStack;     // The main stack
    std::stack<int> minElementStack; // Stack to keep track of minimum elements

public:
    // Push an element onto the stack
    void push(int value) {
        mainStack.push(value);

        // If the minElementStack is empty or the new value is less than or equal to the current minimum,
        // push the new value onto the minElementStack.
        if (minElementStack.empty() || value <= getMin()) {
            minElementStack.push(value);
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (mainStack.empty()) {
            return; // Stack is empty
        }

        // If the value being popped is the current minimum, pop it from the minElementStack as well.
        if (mainStack.top() == getMin()) {
            minElementStack.pop();
        }

        mainStack.pop();
    }

    // Get the top element of the stack
    int top() {
        if (mainStack.empty()) {
            return -1; // Stack is empty
        }
        return mainStack.top();
    }

    // Get the minimum element in the stack
    int getMin() {
        if (minElementStack.empty()) {
            return -1; // Stack is empty
        }
        return minElementStack.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(3);
    minStack.push(5);
    minStack.push(2);
    minStack.push(1);

    std::cout << "Minimum element: " << minStack.getMin() << std::endl; // Should print 1

    minStack.pop();
    std::cout << "Minimum element after popping: " << minStack.getMin() << std::endl; // Should print 2

    return 0;
}
