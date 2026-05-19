#include<iostream>
using namespace std;
 
class Node
{
    public:
    int value;
    Node* next;
    
    public:
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
    private:
    Node* head;
    Node* tail;
    int length;

    public:
    LinkedList(int value)
    {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while(head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    displayList()
    {
        Node* temp = head;
        while(temp!= nullptr)
        {
            cout<<temp->value<<endl;
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList* l1 = new LinkedList(10); 
    l1->displayList();
}
