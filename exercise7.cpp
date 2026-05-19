#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "Doubly linked list is empty\n";
            return;
        }
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        length--;
    }

    void deleteLast() {
        if (head == nullptr) {
            cout << "Doubly linked list is empty\n";
            return;
        }
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        length--;
    }

    void printDoublyLinkedList() {
        cout << "Displaying the linked list\n";
        if (head == nullptr) {
            cout << "No elements present in the linked list\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node* returnNode(int index) {
        if (index >= 0 && index < length) {
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
        return nullptr;
    }

    void insertNode(int index, int value) {
        if (index < 0 || index > length) {
            cout << "Invalid index\n";
            return;
        } else if (length == 0 || index == 0) {
            prepend(value);
        } else if (index == length) {
            append(value);
        } else {
            Node* newNode = new Node(value);
            Node* temp = returnNode(index - 1);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            length++;
        }
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) {
            cout << "Invalid index\n";
            return;
        } else if (index == 0) {
            deleteFirst();
        } else if (index + 1 == length) {
            deleteLast();
        } else {
            Node* temp = returnNode(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            length--;
        }
    }

    bool deleteUsingValue(int value) {
        Node* temp = head;
        int index = 0;
        while (temp != nullptr) {
            if (temp->value == value) {
                deleteNode(index);
                return true;
            }
            temp = temp->next;
            index++;
        }
        return false;
    }

    void info() {
        cout << "\nEnter 1 for prepending a node";
        cout << "\nEnter 2 for deleting the first node";
        cout << "\nEnter 3 for appending a node";
        cout << "\nEnter 4 for deleting the last node";
        cout << "\nEnter 5 for inserting a node in any place using index";
        cout << "\nEnter 6 for deleting a node in any place using index";
        cout << "\nEnter 7 for deleting a node using value";
    }

    ~DoublyLinkedList() {
        Node* temp1 = head;
        while (temp1 != nullptr) {
            Node* temp2 = temp1;
            temp1 = temp1->next;
            delete temp2;
        }
    }
};

int main() {
    int choice, value, index;
    char c;
    cout << "Enter value for the first element of the doubly linked list: ";
    cin >> value;

    DoublyLinkedList* dll1 = new DoublyLinkedList(value);
    dll1->printDoublyLinkedList();
    dll1->info();

    do {
        cout << "\nEnter the choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                dll1->prepend(value);
                dll1->printDoublyLinkedList();
                break;

            case 2:
                dll1->deleteFirst();
                dll1->printDoublyLinkedList();
                break;

            case 3:
                cout << "Enter the value: ";
                cin >> value;
                dll1->append(value);
                dll1->printDoublyLinkedList();
                break;

            case 4:
                dll1->deleteLast();
                dll1->printDoublyLinkedList();
                break;

            case 5:
                cout << "Enter the index and value: ";
                cin >> index >> value;
                dll1->insertNode(index, value);
                dll1->printDoublyLinkedList();
                break;

            case 6:
                cout << "Enter the index: ";
                cin >> index;
                dll1->deleteNode(index);
                dll1->printDoublyLinkedList();
                break;

            case 7:
                cout << "Enter the value: ";
                cin >> value;
                if (dll1->deleteUsingValue(value)) {
                    cout << "Node is deleted\n";
                } else {
                    cout << "Value is not found in the linked list\n";
                }
                dll1->printDoublyLinkedList();
                break;

            default:
                cout << "Invalid choice\n";
        }

        cout << "Do you want to continue (y/n)?: ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    return 0;
}
