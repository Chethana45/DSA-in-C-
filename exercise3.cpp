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
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void append(int value) {
         Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void printLinkedList() {
        if (head == nullptr) {
            cout << "No elements present in the linked list\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteFirst() {
        if (head == nullptr) return;

        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        length--;
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

    void deleteLast() {
        if (head == nullptr) return;

        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* prev = returnNode(length - 2);
            Node* temp = tail;
            tail = prev;
            tail->next = nullptr;
            delete temp;
        }
        length--;
    }

    void insertNode(int index, int value) {
        if (index < 0 || index > length) {
            cout << "Invalid index\n";
        } else if (index == 0) {
            prepend(value);
        } else if (index == length) {
            append(value);
        } else {
            Node* newNode = new Node(value);
            Node* prev = returnNode(index - 1);
            if(prev==nullptr)
            {
                cout<<"Invalid index";
                return;
            }
            Node* after = prev->next;
            newNode->next = after;
            prev->next = newNode;
            length++;
        }
        printLinkedList();
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) {
            cout << "Invalid index\n";
        } else if (index == 0) {
            deleteFirst();
        } else if (index == length - 1) {
            deleteLast();
        } else {
            Node* prev = returnNode(index - 1);
            if(prev!=nullptr)
            {
            Node* temp = prev->next;
            prev->next = temp->next;
            delete temp;
            }
            length--;
        }
        printLinkedList();
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
        cout << "\nEnter 7 to delete a node using value\n";
    }

    ~LinkedList() {
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

    cout << "Enter the value for the first element of the linked list: ";
    cin >> value;

    LinkedList* l1 = new LinkedList(value);
    l1->printLinkedList();
    l1->info();

    do {
        cout << "\nEnter the choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                l1->prepend(value);
                l1->printLinkedList();
                break;

            case 2:
                l1->deleteFirst();
                l1->printLinkedList();
                break;

            case 3:
                cout << "Enter the value: ";
                cin >> value;
                l1->append(value);
                l1->printLinkedList();
                break;

            case 4:
                l1->deleteLast();
                l1->printLinkedList();
                break;

            case 5:
                cout << "Enter the index and value: ";
                cin >> index >> value;
                l1->insertNode(index, value);
                break;

            case 6:
                cout << "Enter the index: ";
                cin >> index;
                l1->deleteNode(index);
                break;

            case 7:
                cout << "Enter the value: ";
                cin >> value;
                if (l1->deleteUsingValue(value))
                    cout << "Node is deleted\n";
                else
                    cout << "Value is not found in the linked list\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

        cout << "Do you want to continue (y/n)?: ";
        cin >> c;

    } while (c == 'y' || c == 'Y');

    delete l1;
    return 0;
}
