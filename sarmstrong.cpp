#include <iostream>
using namespace std;

int main() {
    int num, original, sum = 0;

    cout << "Enter a number: ";
    cin >> num;

    original = num;

    while (num != 0) {
        int digit = num % 10;
        sum = sum + (digit * digit * digit);
        num = num / 10;
    }

    if (sum == original) {
        cout << "Armstrong Number";
    } else {
        cout << "Not an Armstrong Number";
    }

    return 0;
}
