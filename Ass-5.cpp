#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct node
{
    int prn;
    char name[30];
    struct node*next;
};
struct node*head=NULL;

void modify(int prn,char name[])
{
    node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    temp->prn=prn;
    strcpy(temp->name,name);
}

void modifys(int prn,char name[])
{
    struct node*temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prn=prn;
    strcpy(temp->name,name);
    temp->next=NULL;
}

void insert(int prn,char name[])
{
    struct node* temp,*temp1;
    temp1=(struct node*)malloc(sizeof(struct node))  ;
    temp1->prn=prn;
    strcpy(temp1->name,name);
    temp1->next=NULL;
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp1->next=temp->next;
    temp->next=temp1;
}

void delet_e(int prn)
{
    struct node*temp,*temp1;
    temp=head;
    while(temp->next->prn!=prn)
    {
        temp=temp->next;
    }
    temp->next=temp1;
    temp->next=temp1->next;
    free(temp1);
}

void display()
{
    struct node* temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<"->";
        cout<<temp->prn;
        cout<<temp->name;
        temp=temp->next;
    }
}

int main()
{
    int prn;
    char name[30];

    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node))  ;
    cout<<"Enter details of pm.\n";
    cout<<"\n prn of pm:";
    cin>>prn;
    newnode->prn=prn;
    cout<<"\n name of pm:";
    cin>>name;
    strcpy(newnode->name,name);
    newnode->next=NULL;
    head=newnode;

      struct node*newn;
      newn=(struct node*)malloc(sizeof(struct node))  ;

      cout<<"Enter details of secretary.\n";
      cout<<"\nprn of secretary:";
      cin>>prn;
      newn->prn=prn;
      cout<<"\nname of secretary:";
      cin>>name;
      strcpy(newn->name,name);
      newn->next=NULL;
      newnode->next=newn;

    display();

    int ch=9;
    while(ch>0)
    {
         cout<<"\nYou can do below operations:\n";
         cout<<"1.update information of pm\n";
         cout<<"2.update information of secretary.\n";
         cout<<"3.Insert new node.\n";
         cout<<"4.Delete node.\n";
         cin>>ch;
         switch(ch)
         {
         case 1:
             {
              cout<<"Enter the prn of pm.\n";
              cin>>prn;
              cout<<"name of pm.";
              cin>>name;
              modify(prn,name);
              display();
              break;
             }
         case 2:
             {
              cout<<"Enter the prn of secretary .\n";
              cin>>prn;
              cout<<"name of secretary.";
              cin>>name;
              modifys(prn,name);
              display();
              break;
             }
         case 3:
             {
              cout<<"Enter the prn of new member .\n";
              cin>>prn;
              cout<<"name of new member.";
              cin>>name;
              insert(prn,name);
              display();
              break;
             }
         case 4:
            {
             cout<<"Enter the prn of node you want to delete .\n";
             cin>>prn;
             if(newnode->prn!=prn || newn->prn!=prn)
             {
                 delet_e(prn);
                 display();
             }
             cout<<"You can not delete information of pm and secretary.";
             break;
            }

        }

    }
return 0;

}
