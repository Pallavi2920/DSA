#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
  int data;
  struct Node *next=NULL;
}Node;
Node *head=NULL,*tail=NULL;

void insertEnd(int data)
{
  Node *newNode=(Node *)malloc(sizeof(Node));
  newNode->data=data;
  newNode->next=NULL;
  if(head==NULL)
  {
    head=newNode;
    tail=newNode;
    return;
  }
  else
  {
    tail->next=newNode;
    tail=newNode;
  }
}
void insert(int data)
{
  Node *temp=head;
  Node *newNode=(Node *)malloc(sizeof(Node));
  newNode->data=data;
  newNode->next=NULL;
  if(head==NULL || head->data>=newNode->data )
  {
    newNode->next=head;
    head=newNode;
    return;
  }
  else
  {
    while(temp->next!=NULL && temp->next->data<newNode->data)
    {
      temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
  }
}
void printlist()
{
  Node *temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      cin>>data;
      insertEnd(data);
    }
    int num1;
    cin>>num1;
    insert(num1);
    printlist();
    free(head);
  }
}
