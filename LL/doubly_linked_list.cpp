#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
}Node;
Node *head=NULL,*tail=NULL;

void insertBeg(int data)
{
  Node *new_Node=(Node*)malloc(sizeof(Node));
  if(head==NULL)
  {
    new_Node->data=data;
    new_Node->next=NULL;
    new_Node->prev=NULL;
    head=new_Node;
    return;
  }
  new_Node->data=data;
  new_Node->next=head;
  new_Node->prev=NULL;
  head->prev=new_Node;
  head=new_Node;
}
void insertEnd(int data)
{
  Node *new_Node=(Node*)malloc(sizeof(Node));
  if(head==NULL)
  {
    new_Node->data=data;
    new_Node->next=NULL;
    new_Node->prev=NULL;
    head=new_Node;
    return;
  }
  Node *tail=head;
  while(tail->next!=NULL)
  {
    tail=tail->next;
  }
  new_Node->data=data;
  new_Node->next=NULL;
  new_Node->prev=tail;
  tail->next=new_Node;
  tail=new_Node;

}
void insertAtMid(int data,int position)
{

    Node *new_Node=(Node*)malloc(sizeof(Node));
    new_Node->data=data;
    new_Node->next=NULL;
    new_Node->prev=NULL;
    Node *temp=head;
    int count=1;
    if(temp==NULL)
    {
      head=new_Node;
      return;
    }
    while(count<position && temp->next!=NULL)
    {
      count++;
      temp=temp->next;
    }
    if(temp->next==NULL)
    {
      temp->next=new_Node;
      new_Node->prev=temp;
      return;
    }
    new_Node->next=temp->next;
    new_Node->prev=temp;
    new_Node->next->prev=new_Node;
    temp->next=new_Node;
}
void deleteBeg()
{
  Node *temp=head;
  if(temp==NULL)
  {
    cout<<"No item in the list";
    return;
  }
  if(temp->next==NULL)
  {
    cout<<"Deleted item is"<<temp->data;
    head=NULL;
    free(temp);
    return;
  }
  cout<<"Deleted item is"<<temp->data<<endl;
  head=head->next;
  head->prev=NULL;
  temp->next=NULL;
  free(temp);
}
void deleteEnd()
{
  Node *temp=head,*tail;
  if(temp==NULL)
  {
    cout<<"No item in the list";
    return;
  }
  if(temp->next==NULL)
  {
    cout<<"Deleted item is"<<temp->data;
    head=NULL;
    free(temp);
    return;
  }
  tail=temp;
  while(temp->next->next!=NULL)
  {
    temp=temp->next;
  }
  tail=temp->next;
  temp->next=NULL;
  tail->prev=NULL;
  free(tail);
}
void deletenode(int pos)
{
  Node *temp=head,*tail;
  if(temp==NULL)
  {
    cout<<"No item in the list";
    return;
  }
  if(temp->next==NULL)
  {
    cout<<"Deleted item is"<<temp->data;
    head=NULL;
    free(temp);
    return;
  }
  int count=1;
  while (count<pos-1)
  {
    count++;
    temp=temp->next;
  }
  tail=temp->next;
  temp->next=tail->next;
  tail->next->prev=temp;
  tail->next=NULL;
  tail->prev=NULL;
  free(tail);
}
void printlist()
{
  Node *temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<"->";
    temp=temp->next;
  }
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
      insertBeg(data);
    }
    cout<<"Insert At Beginning"<<endl;
    printlist();
    head=NULL;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>data;
      insertEnd(data);
    }
    cout<<"Insert At End"<<endl;
    printlist();
    cout<<endl;
    int pos;
    cin>>pos;
    cin>>data;
    cout<<"Insert after Position"<<pos<<":";
    insertAtMid(data,pos);
    printlist();
    cout<<endl;
    cout<<"Delete Beginning"<<endl;
    deleteBeg();
    printlist();
    cout<<endl;
    cout<<"Delete End"<<endl;
    deleteEnd();
    printlist();
    cout<<endl;
    cout<<"Enter the position you want to delete:"<<endl;
    int pos1;
    cin>>pos1;
    deletenode(pos1);
    printlist();
    cout<<endl;
  }
  return 0;

}
