#include <iostream>
using namespace std;

int main() {

    cout << "Prime Numbers from 1 to 100:\n";

    for (int num = 1; num <= 100; num++) {

        int count = 0;

        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                count++;
            }
        }

        if (count == 2) {
            cout << num << " ";
        }
    }

    return 0;
}
