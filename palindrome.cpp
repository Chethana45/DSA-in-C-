#include <iostream>
using namespace std;

int main() {
    int num, original, reverse = 0;

    cout << "Enter a number: ";
    cin >> num;

    original = num;

    while (num != 0) {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num = num / 10;
    }

    if (original == reverse) {
        cout << "Palindrome Number";
    } else {
        cout << "Not a Palindrome Number";
    }

    return 0;
}
