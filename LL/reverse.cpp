#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
  int data;
  struct Node *next;
}Node;
Node *head=NULL,*tail=NULL;
void insertEnd(int data)
{
  Node *newNode=(Node*)malloc(sizeof(Node));
  newNode->data=data;
  newNode->next=NULL;
  if(head==NULL)
  {
    head=newNode;
    tail=newNode;
    return;
  }
  tail->next=newNode;
  tail=newNode;
}
void reverse()
{
  Node *curr=head,*prev=NULL,*cons=NULL;
  while(curr!=NULL)
  {
    cons=curr->next;
    curr->next=prev;
    prev=curr;
    curr=cons;
  }
  head=prev;
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
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      int data;
      cin>>data;
      insertEnd(data);
    }
    reverse();
    printlist();
    free(head);
  }
}
