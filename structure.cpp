#include <iostream>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    Student s;

    cout << "Enter Roll Number: ";
    cin >> s.rollNo;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Marks: ";
    cin >> s.marks;

    cout << "\nStudent Details\n";
    cout << "Roll No : " << s.rollNo << endl;
    cout << "Name    : " << s.name << endl;
    cout << "Marks   : " << s.marks << endl;

    return 0;
}
