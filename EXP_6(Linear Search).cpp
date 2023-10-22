#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int array[] = {12, 34, 45, 7, 23, 54, 32, 89, 9};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Enter the element to search: ";
    int target;
    cin >> target;

    int result = linearSearch(array, size, target);

    switch (result) {
        case -1:
            cout << "Element not found in the array." << endl;
            break;
        default:
            cout << "Element found at index " << result << "." << endl;
    }

    return 0;
}
