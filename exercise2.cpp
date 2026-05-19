#include<iostream>
using namespace std;
class List
{
        private:
        int a[10000];
        int size;

        public:
        void getSize()
        {
                cout<<"Enter the size of the list:";
                cin>>size;
        }
        void getList()
        {
                cout<<"For list\n";
                for(int i=0;i<size;i++)
                {
                        cout<<"Enter a["<<i<<"]: ";
                        cin>>a[i];
                }
        }
        void printList()
        {
                cout<<"Displaying the list"<<endl;
                for(int i=0;i<size;i++)
                {
                        cout<<a[i]<<endl;
                }
        }
        void insert(int value, int index)
        {
                cout<<"List after inserting the value "<<value<<" in index "<<index<<endl;
                for(int i=size-1;i>=index;i--)
                {
                        a[i+1]=a[i];
                }
                a[index]=value;
                size++;
                printList();
        }
        void deleteIndex(int index)
        {
                if(index>=size)
                {
                        cout<<"Invalid index";
                        return;
                }
                cout<<"List after deleting the value of the index "<<index<<endl;
                for(int i=index;i<size;i++)
                {
                        a[i]=a[i+1];
                }
                size--;
                printList();
        }
        void deleteLast()
        {
                cout<<"List after deleting the last index"<<endl;
                size--;
                printList();
        }
        void deleteUsingValue(int value)
        {
                int flag=0;
                cout<<"List after deleting all the occurrences of the value "<<value<<endl;
                for(int i=0;i<size;)
                {
                        if(a[i]==value)
                        {
                                deleteIndex(i);
                                flag=1;
                                /* break; is used it delete only single occurrence of the value unless it delete all the occurrences */
                        }
                        else i++;
                }
                if(flag==0)
                {
                        cout<<"List does not contain the value "<<value;
                        return;
                }
                printList();
        }
        void search(int value)
        {
                int flag=0;
                for(int i=0;i<size;i++)
                {
                        if(a[i]==value)
                        {
                                cout<<"Element is present\n";
                                flag=1;
                                break;
                        }
                }
                if(flag==0)
                {
                        cout<<"Element is not present\n";
                }
        }

        void maxOrMin(int choice)
        {
                int b[10000];
                for(int i=0;i<size;i++)
                {
                        b[i]=a[i];
                }
                for(int i=0;i<size;i++)
                {
                        for(int j=0;j<size;j++)
                        {
                                if(b[i]>b[j])
                                {
                                        int temp=b[i];
                                        b[i]=b[j];
                                        b[j]=temp;
                                }
                        }
                }
                if(choice==1)
                {
                        cout<<"The maximum element in the list is "<<a[size-1]<<endl;
                }
                                if(choice==0)
                {
                        cout<<"The minimum element in the list is "<<a[0];
                }
        }
        void info()
        {
                cout<<"\nEnter 1 for inserting the element in the list";
                cout<<"\nEnter 2 for delete using index";
                cout<<"\nEnter 3 for deleting the last value";
                cout<<"\nEnter 4 for delete using value";
                cout<<"\nEnter 5 for searching the element";
                cout<<"\nEnter 6 for displaying the maximum element";
                cout<<"\nEnter 7 for displaying the minimum element\n";
        }

};

int main()
{
        List l1;
        l1.getSize();
        l1.getList();
        int index, value,choice;
        char c;
        do
        {
                l1.info();
                cout<<"Enter the choice: ";
                cin>>choice;
                switch(choice)
                {
                        case 1:
                                cout<<"Enter the value and index:";
                                cin>>value>>index;
                                l1.insert(value,index);
                                break;
                        case 2:
                                cout<<"Enter the index: ";
                                cin>>index;
                                l1.deleteIndex(index);
                                break;
                        case 3:
                                l1.deleteLast();
                                break;
                        case 4:
                                cout<<"Enter the value: ";
                                cin>>value;
                                l1.deleteUsingValue(value);
                                break;
                        case 5:
                                cout<<"Enter the value to search: ";
                                cin>>value;
                                l1.search(value);
                                break;
                        case 6:
                                l1.maxOrMin(1);
                                break;
                        case 7:
                                l1.maxOrMin(0);
                                break;
                        default:
                                cout<<"Invalid choice";
                }
                cout<<"Do you want to continue(y/n)?: ";
                cin>>c;
                cin.ignore();
        }while(c=='y'|| c=='Y');
        return 0;
}