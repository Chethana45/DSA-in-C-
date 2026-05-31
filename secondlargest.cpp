#include <iostream>
using namespace std;

int main() {
    int arr[5];

    cout << "Enter 5 elements:\n";

    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int largest = arr[0];
    int secondLargest = arr[0];

    for(int i = 1; i < 5; i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    cout << "Second Largest = " << secondLargest;

    return 0;
}
