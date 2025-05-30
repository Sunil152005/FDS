#include<iostream>
#include<stdlib.h>
using namespace std;

#define N 5
int q[N];
int rear =-1,front=-1;

int isfull()
{
    if((rear+1)%N==front)
        return 1;
    else
        return 0;
}

int isempty()
{
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}

void enqueue(int ele)
{
    if(isfull())
    {
        cout<<"queue is full";
        return;
    }
    if (isempty)
    {
        front=0;
    }
    rear=(rear+1)%N;
    q[rear]=ele;
}

int dequeue()
{
    if(isempty())
        {
        cout<<"queue is empty";
        return 1;
        }

    int ele=q[front];
    cout<<"delete element is:-"<<ele<<endl;

    if(front==rear)
        {
        front=rear=-1;
        }
    else
        {
        front=(front+1)%N;
        }
    return ele;
}

void dis()
{
    if(isempty())
        {
        cout<<"queue is empty";
        return;
        }
        int i;
        i=front;
        cout<<"queue element is:-";
        while(i!=rear)
            {
            cout<<q[i]<<" ";
            i=(i+1)%N;
            }
        cout<<q[rear];
}

int main()
{
    int ch=9, ele;
    int res,out;
    while(ch!=0)
    {
        cout << "\n Menu:";
        cout << "\n 1.Enqueue";
        cout << "\n 2.Dequeue";
        cout << "\n 3.Display";
        cout << "\n 4.isfull";
        cout << "\n 5.isempty";
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
                dequeue();
                break;

            case 3:
                dis();
                break;

            case 4:
                res=isfull();
                if(res==1)
                    {
                    cout<<"queue is full";
                    }
                else
                    {
                    cout<<"queue is not full";
                    }
                break;
            case 5:
                out=isempty();
                if(out==1)
                    {
                    cout<<"queue is empty";
                    }
                else
                    {
                    cout<<"queue is not empty";
                    }
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
