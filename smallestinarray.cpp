#include <iostream>
using namespace std;

int main() {
    int arr[5];

    cout << "Enter 5 elements:\n";

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int smallest = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    cout << "Smallest Element = " << smallest;

    return 0;
}
