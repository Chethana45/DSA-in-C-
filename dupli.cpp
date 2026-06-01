#include <iostream>
using namespace std;

int main() {
    int arr[6] = {1, 2, 2, 3, 4, 4};

    cout << "Unique Elements: ";

    for(int i = 0; i < 6; i++) {
        bool duplicate = false;

        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                duplicate = true;
                break;
            }
        }

        if(!duplicate)
            cout << arr[i] << " ";
    }

    return 0;
}
