#include <iostream>
using namespace std;

const int MAX_SIZE = 10;  // Maximum size of the array

int arr[MAX_SIZE];  // Initialize an integer array
int currentSize = 0;  // Keep track of the current number of elements in the array

void displayArray() {
    cout << "Array: ";
    for (int i = 0; i < currentSize; i++) {
        std::cout << arr[i] << " ";
    }
    cout << std::endl;
}

void insertElement(int value) {
    if (currentSize < MAX_SIZE) {
        arr[currentSize] = value;
        currentSize++;
        cout << "Inserted " << value << " into the array." << endl;
    } else {
        cout << "Overflow: Cannot insert, the array is full." << endl;
    }
}

void deleteElement() {
    if (currentSize > 0) {
        int deletedValue = arr[currentSize - 1];
        currentSize--;
        cout << "Deleted " << deletedValue << " from the array." << endl;
    } else {
        cout << "Underflow: Cannot delete, the array is empty." << endl;
    }
}

int main() {
    int choice;
    int value;

    while (true) {
        cout << "\nMenu:" << std::endl;
        cout << "1. Insert element" << endl;
        cout << "2. Delete element" <<endl;
        cout << "3. Display array" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                insertElement(value);
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                displayArray();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
