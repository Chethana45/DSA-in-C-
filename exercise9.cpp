#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    static int size;
    Node* top;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        top = newNode;
        length = 1;
    }

    bool isFull() {
        if (length == size) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (length == 0) {
            return true;
        }
        return false;
    }

    void push(int value) {
        if (!isFull()) {
            Node* newNode = new Node(value);
            if (length == 0) {
                top = newNode;
            } else {
                newNode->next = top;
                top = newNode;
            }
            length++;
        } else {
            cout << "Stack is full and cannot push any element into it\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty and cannot delete any elements from it\n";
        } else {
            Node* temp = top;
            top = top->next;
            delete temp;
            length--;
        }
    }

    void display() {
        cout << "Displaying the stack\n";
        if (length == 0) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void info() {
        cout << "\nEnter 1 for push function\nEnter 2 for pop function\n";
    }
};

int LinkedList::size = 10;

int main() {
    int choice, value;
    char c;

    cout << "Enter the value for the first element of the stack: ";
    cin >> value;

    LinkedList* s = new LinkedList(value);
    s->info();

    do {
        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                s->push(value);
                s->display();
                break;
            case 2:
                s->pop();
                s->display();
                break;
            default:
                cout << "Invalid choice\n";
        }

        cout << "Do you want to continue (y/n)?: ";
        cin >> c;
    } while (c == 'Y' || c == 'y');

    return 0;
}
