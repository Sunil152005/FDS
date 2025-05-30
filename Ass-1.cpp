#include <iostream>
using namespace std;

int uni(int A[10], int B[10], int C[20], int a, int b)
{
    int i, j;
    int c = 0;
    int flag = 0;

    for (i = 0; i < a; i++)
    {
        flag = 0;
        for (j = 0; j < c; j++)
        {
            if (C[j] == A[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            C[c] = A[i];
            c++;
        }
    }

    for (i = 0; i < b; i++)
    {
        flag = 0;
        for (j = 0; j < c; j++)
        {
            if (C[j] == B[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            {
            C[c] = B[i];
            c++;
            }
    }
    return c;
}

int inter(int A[10],int B[10],int C[20],int a,int b)
{
    int i,j;
    int c=0;
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            if(A[i]==B[j])
            {
                C[c]=A[i];
                c++;
            }
        }
    }
    return c;
}

int diff(int A[10],int B[10],int C[20],int a,int b)
{
    int i,j;
    int c=0;
    int flag=0;
    for(i=0;i<a;i++)
    {
        flag=0;
        for(j=0;j<b;j++)
        {
            if(A[i]==B[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            C[c]=A[i];
            c++;
        }
    }
    return c;
}

int sydiff(int A[10],int B[10],int C[20],int a,int b)
{
    int D[20],E[20];
    int d,e,c;
    d=diff(A,B,D,a,b);
    e=diff(B,A,E,b,a);
    c=uni(D,E,C,d,e);
    return c;
}

void display(int C[20], int c)
{
    for (int i = 0; i < c; i++)
        {
        cout << C[i] << " ";
        }
    cout << endl;
}

int main()
{
    int A[10], B[10], C[20];
    int a, b, c;
    int i, j;
    int ch = 9;

    cout << "Enter the number of elements in array A: ";
    cin >> a;
    cout << "Enter elements of array A: "<<endl;
    for (i = 0; i < a; i++)
        {
        cin >> A[i];
        }

    cout << "Enter the number of elements in array B: ";
    cin >> b;
    cout << "Enter elements of array B: "<<endl;
    for (i = 0; i < b; i++)
        {
        cin >> B[i];
        }

    while (ch > 0)
    {
        cout << "\n 1. Union \n 2. Intersection \n 3. Difference \n 4. Symmetric Difference\n ";
        cout << "\n Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                c = uni(A,B,C,a,b);
                display(C, c);
                break;
            case 2:
                c = inter(A,B,C,a,b);
                display(C,c);
                break;
            case 3:
                c=diff(A,B,C,a,b);
                display(C,c);
                break;
            case 4:
                c=sydiff(A,B,C,a,b);
                display(C,c);
                break;
            default:
                cout << "Invalid choice! Exiting.\n";

                break;
        }
    }
    return 0;
}
