#include <iostream>

class Queue {
private:
    int* array;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size) {
        capacity = size;
        array = new int[capacity];
        front = 0;
        rear = -1;
    }

    // Function to check if the queue is empty.
    bool isEmpty() {
        return front > rear;
    }

    // Function to check if the queue is full.
    bool isFull() {
        return rear == capacity - 1;
    }

    // Function to enqueue (push) an element into the queue.
    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
        } else {
            array[++rear] = item;
        }
    }

    // Function to dequeue (pop) an element from the queue.
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Return a placeholder value (you can customize this).
        } else {
            return array[front++];
        }
    }

    // Function to get the front element of the queue without dequeueing it.
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot peek." << std::endl;
            return -1; // Return a placeholder value (you can customize this).
        } else {
            return array[front];
        }
    }

    // Function to display the elements of the queue.
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
        } else {
            std::cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                std::cout << array[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    ~Queue() {
        delete[] array;
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.display();

    std::cout << "Front element: " << queue.peek() << std::endl;

    int removed = queue.dequeue();
    std::cout << "Dequeued element: " << removed << std::endl;

    queue.display();

    return 0;
}
