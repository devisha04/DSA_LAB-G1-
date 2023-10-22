#include <iostream>
using namespace std;

int main() {
    int array[100];  // Assuming a maximum of 100 elements
    int size = 0;

    while (true) {
        cout << "Current Array Elements: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        cout << "Choose an option:\n";
        cout << "1. Insert an element at the beginning\n";
        cout << "2. Delete an element from the beginning\n";
        cout << "3. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            if (size < 100) {
                cout << "Enter the element to insert: ";
                int newElement;
                cin >> newElement;
                for (int i = size; i > 0; i--) {
                    array[i] = array[i - 1];
                }
                array[0] = newElement;
                size++;
                cout << "Element inserted at the beginning successfully.\n";
            } else {
                cout << "Array is full. Cannot insert more elements.\n";
            }
        } else if (choice == 2) {
            if (size > 0) {
                for (int i = 0; i < size - 1; i++) {
                    array[i] = array[i + 1];
                }
                size--;
                cout << "Element at the beginning deleted successfully.\n";
            } else {
                cout << "Array is empty. Cannot delete elements.\n";
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
