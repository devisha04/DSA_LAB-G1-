#include <iostream>
using namespace std;
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }

    // Move n-1 disks from source to auxiliary peg using destination as the auxiliary peg.
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination.
   cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;

    // Move the n-1 disks from auxiliary to destination using source as the auxiliary peg.
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int numDisks = 3; // Change this value to the number of disks you want to solve for.
    towerOfHanoi(numDisks, 'A', 'B', 'C');
    return 0;
}
