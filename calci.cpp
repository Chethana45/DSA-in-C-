#include <iostream>
using namespace std;

int main() {
    int a, b, choice;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";

    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {

        case 1:
            cout << "Result = " << a + b;
            break;

        case 2:
            cout << "Result = " << a - b;
            break;

        case 3:
            cout << "Result = " << a * b;
            break;

        case 4:
            cout << "Result = " << a / b;
            break;

        default:
            cout << "Invalid Choice";
    }

    return 0;
}
