#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}Node;
Node *head=NULL,*tail=NULL;
void insertBeg(int data)
{
  Node *newNode=(Node*)malloc(sizeof(Node));
  if(head==NULL)
  {
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    head=newNode;
    return;
  }
  else
  {
    newNode->data=data;
    newNode->next=head;
    newNode->prev=NULL;
    head->prev=newNode;
    head=newNode;
  }
}
void print()
{
  Node *temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data;
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
    int n,sum=0;
    cin>>n;
    sum=n+1;
    int x=sum;
    while(x!=0)
    {
      insertBeg(x%10);
      x=x/10;
    }
    print();
    free(head);
    free(tail);
  }
}
