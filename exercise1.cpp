#include<iostream>
using namespace std; 
int MAX_SIZE=100;
class Stack
{
        private:
        int a[10000];
        int top;
        public:
        Stack()
        {
                top=-1;
        }
        void getElement(int size)
        {
                for(int i=0;i<size;i++)
                {
                        top=top+1;
                        cout<<"Enter a["<<top<<"]: ";
                        cin>>a[top];
                }
        }

        void push(int value)
        {
                if(top+1 == MAX_SIZE)
                {
                        cout<<"Element cannot be inserted into the top, Stack size reached"<<endl;
                        return;
                }
                top= top+1;
                a[top]=value;
        }

        void pop()
        {
                if(top==-1)
                {
                        cout<<"Stack does not contain any element"<<endl;
                        return;
                }
                top--;
        }

        void printStack()
        {
                if(top>=0)
                {
                        cout<<"Displaying the stack"<<endl;
                        for(int i=top;i>=0;i--)
                        {
                                cout<<a[i]<<endl;
                        }
               }
               else
               {
                       cout<<"Stack does not contain any element";
               }
        }
        void info()
        {
                cout<<"\nEnter 1 for pushing the element in the stack";
                                cout<<"\nEnter 2 for poping the element in the stack\n";
        }
};

int main()
{
        Stack s1;
        int choice,value,size;
        char c;
        cout<<"Enter the size of the stack: ";
        cin>>size;
        s1.getElement(size);
        s1.printStack();
        do
        {
                s1.info();
                cout<<"Enter the choice: ";
                cin>>choice;
                switch(choice)
                {
                        case 1:
                                cout<<"Enter the value: ";
                                cin>>value;
                                s1.push(value);
                                s1.printStack();
                                break;
                        case 2:
                                s1.pop();
                                s1.printStack();
                                break;
                }
                cout<<"Do you want to continue(y/n)?: ";
                cin>>c;
                cin.ignore();
        }while(c=='Y' || c=='y');
        return 0;
}