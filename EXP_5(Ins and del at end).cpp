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
        cout << "1. Insert an element at the end\n";
        cout << "2. Delete an element from the end\n";
        cout << "3. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            if (size < 100) {
                cout << "Enter the element to insert: ";
                cin >> array[size];
                size++;
                cout << "Element inserted at the end successfully.\n";
            } else {
                cout << "Array is full. Cannot insert more elements.\n";
            }
        } else if (choice == 2) {
            if (size > 0) {
                size--;
                cout << "Element at the end deleted successfully.\n";
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
