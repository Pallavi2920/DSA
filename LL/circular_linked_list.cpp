#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
  int data;
  struct Node *next;
}Node;
Node *head=NULL,*tail=NULL;
void insertBeg(int data)
{
  Node *temp=head;
  Node *new_Node;
  new_Node=(Node*)malloc(sizeof(Node));
  new_Node->data=data;
  new_Node->next=NULL;
  if(head==NULL)
  {
    head=new_Node;
    tail=new_Node;
    return;
  }
  new_Node->next=head;
  head=new_Node;
  tail->next=new_Node;
}
void insertEnd(int data)
{
  Node *temp=head;
  Node *new_Node;
  new_Node=(Node*)malloc(sizeof(Node));
  new_Node->data=data;
  new_Node->next=NULL;
  if(head==NULL)
  {
    head=new_Node;
    tail=new_Node;
    return;
  }
  tail->next=new_Node;
  tail=new_Node;
  tail->next=head;
}
void insertAtMid(int data,int pos)
{
  int counter=1;
  Node *temp=head;
  Node *new_Node;
  new_Node=(Node*)malloc(sizeof(Node));
  new_Node->data=data;
  new_Node->next=NULL;
  if(head==NULL)
  {
    head=new_Node;
    tail=new_Node;
    return;
  }
  if(temp->next==NULL)
  {
    tail->next=new_Node;
    tail=new_Node;
    tail->next=head;
    return;
  }
  while(counter<pos && temp->next!=head)
  {
    counter++;
    temp=temp->next;
  }
  if(temp->next==head)
  {
    tail->next=new_Node;
    tail=new_Node;
    tail->next=head;
    return;
  }
  new_Node->next=temp;
  temp->next=new_Node;

}
void display()
{
  Node *temp=head;
  do
  {
    cout<<temp->data<<"->";
    temp=temp->next;
  }while(temp!=head);
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,x;
    for(int i=0;i<n;i++)
    {

      cin>>x;
      insertBeg(x);
    }
    cout<<"Insertion at the beginning";
    display();
    head=NULL;
    for(int i=0;i<n;i++)
    {
      cin>>x;
      insertEnd(x);
    }
    cout<<"Insertion at the beginning";
    display();
    cout<<"Enter the data";
    int data;
    cin>>data;
    cout<<"Enter the position you want to insert:";
    int pos;
    cin>>pos;
    insertAtMid(data,pos);
    display();
  }
}
