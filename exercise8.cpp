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

class CircularLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    CircularLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        head->next = head;
        tail = head;
        length = 1;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            tail = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        length++;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        length++;
    }

    void deleteFirst() {
        if (head == nullptr) {
            cout << "Circular linked list is empty\n";
            return;
        }
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            tail->next = head;
        }
        length--;
        delete temp;
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
    if (head == nullptr) {
        cout << "Circular linked list is empty\n";
        return;
    }
    Node* temp = tail;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        Node* prev = returnNode(length - 2);
        tail = prev;
        tail->next = head; // fix circular connection
    }
    length--;
    delete temp;
}


    void insertNode(int index, int value) {
        if (index < 0 || index > length) {
            cout << "Invalid index\n";
            return;
        } else if (index == 0) {
            prepend(value);
        } else if (index == length) {
            append(value);
        } else {
            Node* temp = returnNode(index - 1);
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) {
            cout << "Invalid index";
            return;
        } else if (index == 0) {
            deleteFirst();
        } else if (index + 1 == length) {
            deleteLast();
        } else {
            Node* prev = returnNode(index - 1);
            Node* temp = prev->next;
            prev->next = temp->next;
            delete temp;
            length--;
        }
    }

    bool deleteUsingValue(int value) {
        if(head==nullptr) return;
        Node* temp = head;
        int index = 0;
        do{
            if (temp->value == value) {
                deleteNode(index);
                return true;
            }
            temp = temp->next;
            index++;
        }while(temp != head); 
        return false;
    }

    void printCircularLinkedList() {
        if (head == nullptr) {
            cout << "No elements present in the circular linked list";
            return;
        }
        Node* temp = head;
        while (1) {
            cout << temp->value << "->";
            temp = temp->next;
            if (temp == head) break;
        }
        cout << "head" << endl;
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

    ~CircularLinkedList() {
    if (head == nullptr) return; // avoid crash when list is empty
    tail->next = nullptr; // break circular link

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
    cout << "Enter value for the first element of the circular linked list: ";
    cin >> value;

    CircularLinkedList* cll1 = new CircularLinkedList(value);
    cll1->printCircularLinkedList();
    cll1->info();

    do {
        cout << "\nEnter the choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                cll1->prepend(value);
                cll1->printCircularLinkedList();
                break;

            case 2:
                cll1->deleteFirst();
                cll1->printCircularLinkedList();
                break;

            case 3:
                cout << "Enter the value: ";
                cin >> value;
                cll1->append(value);
                cll1->printCircularLinkedList();
                break;

            case 4:
                cll1->deleteLast();
                cll1->printCircularLinkedList();
                break;

            case 5:
                cout << "Enter the index and value: ";
                cin >> index >> value;
                cll1->insertNode(index, value);
                cll1->printCircularLinkedList();
                break;

            case 6:
                cout << "Enter the index: ";
                cin >> index;
                cll1->deleteNode(index);
                cll1->printCircularLinkedList();
                break;

            case 7:
                cout << "Enter the value: ";
                cin >> value;
                if (cll1->deleteUsingValue(value))
                    cout << "Node is deleted\n";
                else
                    cout << "Value is not found in the linked list\n";
                cll1->printCircularLinkedList();
                break;

            default:
                cout << "Invalid choice\n";
        }
        cout << "\nDo you want to continue(y/n)?: ";
        cin >> c;
    } while (c == 'y' || c == 'Y');

    return 0;
}
