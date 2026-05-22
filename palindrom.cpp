#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, reverse = "";

    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = str.length() - 1; i >= 0; i--) {
        reverse = reverse + str[i];
    }

    if (str == reverse) {
        cout << "Palindrome String";
    } else {
        cout << "Not a Palindrome String";
    }

    return 0;
}
