#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *head=NULL,*tail=NULL;
bool isPalindrome(int n)
{
  int count=0;
  Node *temp1=head,*temp2=tail;
  while(count<n/2)
  {
    if(temp1->data == temp2->data)
    {
      count++;
      temp1=temp1->next;
      temp2=temp2->prev;
    }
    else
    {
      return false;
    }
  }
  return true;
}
void insertEnd(int data)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    else
    {
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;

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
    int n;
    while(t--)
    {

        cin>>n;
        for(int i=0;i<n;i++)
        {
            int data;
            cin>>data;
            insertEnd(data);

        }
        if(isPalindrome(n)?cout<<"true"<<endl:cout<<"false"<<endl);
        free(head);
    }
}
