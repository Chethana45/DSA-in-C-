#include <iostream>
using namespace std;

int main() {
    int num, count = 0;

    cout << "Enter a number: ";
    cin >> num;

    while (num != 0) {
        count++;
        num = num / 10;
    }

    cout << "Number of Digits = " << count;

    return 0;
}
