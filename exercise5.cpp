#include <iostream>
using namespace std;

int MAX_SIZE = 10;

class CircularQueue {
private:
    int a[10000];
    int front;
    int rear;
    int size;
    int flag;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        flag = 0;
    }

    void getSize() {
        cout << "Enter the size of the circular queue: ";
        cin >> size;
    }

    void getElements() {
        while (1) {
            if (size <= MAX_SIZE) {
                front = 0;
                rear = 0;
                cout << "Enter the elements of the circular queue\n";
                for (int i = 0; i < size; i++) {
                    cout << "Enter a[" << i << "]: ";
                    cin >> a[i];
                }
                rear = size - 1;
                break;
            } else {
                cout << "Invalid size\nEnter size less than " << MAX_SIZE << endl;
                getSize();
            }
        }
    }

    void printCircularQueue() {
        cout << "\nDisplaying the circular queue\n";
        int temp = front;
        if (front == -1 ) {
            cout<<"Circular queue is empty\n";
            return;
        }
        while (1) {
            cout << a[temp] << endl;
            if (temp == rear) {
                break;
            }
            temp = (temp+1)%MAX_SIZE;
        }
    }

    void enqueue(int value) {
        if((rear + 1) % MAX_SIZE==front)
        {
            cout<<"Circular queue is full\n";
            return;
        }
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else{
            rear = (rear+1)%MAX_SIZE;
        }
        a[rear] = value;
    }

    void dequeue() {
        if(front==-1)
        {
            cout<<"Circular queue is empty\n";
            return;
        }
        if (front == rear) {
           front=-1;
           rear=-1;       
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    void info() {
        cout << "\nEnter 1 for inserting an element in the circular queue\n";
        cout << "Enter 2 for deleting the element in the circular queue\n";
    }
};

int main() {
    CircularQueue cq1;
    int choice, value;
    char c;

    cq1.getSize();
    cq1.getElements();
    cq1.printCircularQueue();
    cq1.info();

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value: ";
                cin >> value;
                cq1.enqueue(value);
                cq1.printCircularQueue();
                break;

            case 2:
                cq1.dequeue();
                cq1.printCircularQueue();
                break;

            default:
                cout << "Invalid choice\n";
        }

        cout << "Do you want to continue(y/n)?: ";
        cin >> c;

    } while (c == 'Y' || c == 'y');

    return 0;
}