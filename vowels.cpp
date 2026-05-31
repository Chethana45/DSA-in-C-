#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int count = 0;

    cout << "Enter a string: ";
    getline(cin, str);

    for(char ch : str) {
        ch = tolower(ch);

        if(ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u') {
            count++;
        }
    }

    cout << "Number of vowels = " << count;

    return 0;
}
