#include<iostream>
using namespace std;

void bubble(int A[20],int a)
{
    int i,j;
    int temp;
    for(i=0;i<a-1;i++)
    {
        for(j=0;j<a-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                temp= A[j];
                A[j]= A[j+1];
                A[j+1]= temp;
            }
        }
    }
}

void selection(int A[20],int a)
{
    int i;
    int j=0;
    int temp;
    for(i=0;i<a-1;i++)
    {
        for(j=i+1;j<a;j++)
            {
            if(A[i]>A[j])
            {
                temp= A[i];
                A[i]= A[j];
                A[j]= temp;
            }
        }
    }
}

void insertion(int A[20],int a)
{
    int i,j;
    int temp;
    for(i=0;i<a;i++)
    {
        j=i-1;
        temp=A[i];

        while(j>=0 && A[j]>temp)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
    }
}

int partition(int A[20],int l,int h)
{
    int i,j,pivot;
    pivot = A[l];
    i=l;
    j=h;
    while(i<j)
    {
        do
        {
            i++;
        }
        while(A[i]<=pivot && i<h);

        do
        {
            j--;
        }
        while(A[j]>pivot && j>=l);
        {
           if(i<j)
           {
               swap(A[i],A[j]);
           }
        }
        swap(A[j],A[l]);
    }
    return j;
}

void quick(int A[20],int l,int h)
{
     if(l<h)
     {
         int j = partition(A,l,h);
         quick(A,l,j);
         quick(A,j+1,h);
     }
}

void merge(int A[20],int l,int m,int r)
{
    int i,j,k;
    int a1 = m+1-l;
    int a2 = r-m;
    int L[a1],R[a2];

    for (i=0;i<a1;i++)
        L[i] = A[l+i];
    for (j=0;j<a2;j++)
        R[j] = A[m+1+j];

    i=0; j=0; k=l;
    while (i<a1 && j<a2)
    {
        if (L[i]<=R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i<a1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j<a2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int A[20], int l, int r)
{
    if (l<r)
    {
        int m = l+(r-1)/2;
        merge_sort(A, l, m);
        merge_sort(A, m+1, r);
        merge (A, l, m, r);
    }
}

void linear_search(int A[], int a)
{
     int i, num, temp = 0;
     cout<<"Enter the number:";
     cin>>num;
     for(i=0; i<a; i++)
     {
          if(num == A[i])
          {
              cout<<"Number found at index"<<i<<endl;
              temp = 1;
              break;
          }
     }
     if(temp == 0)
     cout<<"Number no found"<<endl;
}

int binary(int A[20],int a)
{
    int l=0;
    int data;
    int r=a-1;
    int mid;
    cout<<"Enter the data:";
    cin>>data;
    while(l<r)
    {
        mid=(l+r)/2;
        if(data==A[mid])
        return mid;
        else if(A[mid]<data)
        {
            l=mid+1;
        }
        else
        r=mid-1;
    }
    return -1;
}

void display(int A[20],int a)
{
    int i;
    for(i=0;i<a;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
}

int main()
{
    int A[20];
    int a;
    int i;
    int pos;
    int l,h;
    int ch=9;

        cout<<"Enter the size of array:"<<endl;
        cin>>a;
        cout<<"Enter the elements:"<<endl;
        for(i=0;i<a;i++)
        {
            cin>>A[i];
        }
    while(ch>0)
    {
    cout<<"See the option:"<<endl;
    cout<<"1.Bubble :"<<endl;
    cout<<"2.Selection :"<<endl;
    cout<<"3.Insertion :"<<endl;
    cout<<"4.Quick sort :"<<endl;
    cout<<"5.Merge sort :"<<endl;
    cout<<"6.Linear search :"<<endl;
    cout<<"7.Binary search :"<<endl;
    cout<<"Enter the choice"<<endl;
    cin>>ch;

    switch(ch)
    {
        case 1:
        bubble (A,a);
        display (A,a);
        break;

        case 2:
        selection (A,a);
        display (A,a);
        break;

        case 3:
        insertion (A,a);
        display (A,a);
        break;

        case 4:
        quick (A,0,a-1);
        display (A,a);
        break;

        case 5:
        merge_sort (A,0,a-1);
        display (A,a);
        break;

        case 6:
        linear_search (A,a);
        break;

        case 7:
        pos=binary(A,a);
        if(pos!=-1)
        {
            cout<<"\n number is found at position"<<pos;
        }
        else
            cout<<"number not found \n";
        break;


        default:
        cout<<"Exit"<<endl;
    }
}
return 0;
}
