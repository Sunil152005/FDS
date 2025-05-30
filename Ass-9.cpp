#include<iostream>
#include<stdlib.h>
using namespace std;

#define N 10
int q[N];
int front=-1;
int rear=-1;

int isempty()
{
    if(front==-1&&rear==-1)
    {
        return 1;
    }
    else
    return 0;
}

int isfull()
{
    if(rear==N-1)
        return 1;
    else
        return 0;
}

int enqueue(int x)
{
    if(isfull())
    {
    cout<<"Queue IS Full"<<endl;
    return 1;
    }
     rear++;
    q[rear]=x;
    return x;
 }

int dequeue()
{
    if(isempty())
    {
        cout<<"Queue is Empty"<<endl;
        return 0;
    }
    int ele;
    front++;
    ele = q[front];
    return ele;
}



void display()
{
    for(int i=front+1;i<rear+1;i++)
    {
        cout<<" "<<q[i];
    }
}

int main()
{
    int ch=9, ele;
    int res,out;

    while (ch>0)
        {
        cout << "\nQueue Menu";
        cout << "\n 1.Enqueue";
        cout << "\n 2.Dequeue";
        cout << "\n 3.Display";
        cout << "\n 4.isempty";
        cout << "\n 5.isfull";
        cout << "\n 6.Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> ele;
                enqueue(ele);
                break;

            case 2:
                cout<<dequeue();

                break;

            case 3:
                display();
                break;

            case 4:
                res=isempty();
                if(res==1)
                {
                    cout<<"queue is empty";
                }
                else
                {
                    cout<<"queue is not empty";
                }
                break;
            case 5:
                out=isfull();
                if(out==1)
                {
                    cout<<"queue is full";
                }
                else
                {
                    cout<<"queue is not full";
                }
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
