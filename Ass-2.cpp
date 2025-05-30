#include<iostream>
using namespace std;

void mul(int A[5][5], int B[5][5], int C[5][5], int m, int n, int p, int q)
{
    int i, j, k;
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            C[i][j]=0;
            for (k=0;k<q;k++)
            {
                C[i][j] +=  A[i][k] * B[k][j];
            }
        }
    }
}


void add(int A[5][5], int B[5][5], int C[5][5], int m , int n , int p, int q)
{
    int i,j;

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
            {
                C[i][j] = A[i][j] + B[i][j];
            }
    }
}

void transpose(int A[5][5],int C[5][5], int m , int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            {
                C[i][j]=A[j][i];
            }
    }
}

void display(int C[5][5], int m , int n)
{
    int i ,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<C[i][j]<<" ";
        }   cout<<"\n";
    }
}

int main()

{
    int A[5][5], B[5][5], C[5][5];
    int m, n, p, q ;
    int i,j ;
    int ch =9;

    cout<<"Enter the size of matrix 1"<<endl;
    cin >>m;
    cin>>n;
    cout<<"Enter the element in matrix 1"<<endl;
    for(i=0;i<m;i++)
        {
        for(j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<"Enter the size of matrix 2"<<endl;
    cin >>p;
    cin>>q;
    cout<<"Enter the element in matrix 2"<<endl;
    for(i=0;i<p;i++)
       {
        for(j=0;j<q;j++)
        {
            cin>>B[i][j];
        }
    }

    while (ch>0)
    {
        cout<<"select the operation "<<endl;
        cout<<"1.Add"<<endl;
        cout<<"2.Transpose"<<endl;
        cout<<"3.Multiply"<<endl;
        cout<<"Select the choice "<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1:
                add(A,B,C,m,n,p,q);
                display(C,m,n);
            break;

            case 2:
                transpose(A,C,m,n);
                display(C,m,n);
                break;

            case 3:
                mul(A,B,C,m,n,p,q);
                display(C,m,n);
                break;

            default:
                cout<<"Exist"<<endl;
        }
    }
    return 0;

}
