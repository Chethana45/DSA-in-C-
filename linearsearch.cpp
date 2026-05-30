#include <iostream>
using namespace std;

int main() {
    int arr[5], key;
    bool found = false;

    cout << "Enter 5 elements:\n";

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < 5; i++) {
        if (arr[i] == key) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Element Found";
    } else {
        cout << "Element Not Found";
    }

    return 0;
}
