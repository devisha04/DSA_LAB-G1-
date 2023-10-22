#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isPalindrome(const std::string &str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());

    return str == reversed;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << input << " is a palindrome." << std::endl;
    } else {
        cout << input << " is not a palindrome." << std::endl;
    }

    return 0;
}
