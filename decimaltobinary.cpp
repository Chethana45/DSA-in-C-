#include <iostream>
using namespace std;

int main() {
    int num;
    string binary = "";

    cout << "Enter a decimal number: ";
    cin >> num;

    while(num > 0) {
        binary = char((num % 2) + '0') + binary;
        num /= 2;
    }

    cout << "Binary = " << binary;

    return 0;
}
