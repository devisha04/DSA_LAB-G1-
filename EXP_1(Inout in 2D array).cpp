#include <iostream>
using namespae std;
int main() {
    const int numStudents = 5;
    const int numSubjects = 3; // Assuming 3 subjects per student

    int marks[numStudents][numSubjects];

    // Input marks for each student and each subject
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter marks for Student " << i + 1 << ":" << std::endl;
        for (int j = 0; j < numSubjects; j++) {
            cout << "Enter marks for Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    // Display the entered marks
    std::cout << "Entered Marks:" << std::endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ": ";
        for (int j = 0; j < numSubjects; j++) {
            cout << marks[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
