#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
};
Node *head = NULL;
Node *tail = NULL;
void printlist()
{
    Node *temp = head;
    while (temp != NULL)
    {
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<"\n";
}
void rotatelist()
{
    if (head==tail)
      return;
    Node *temp = head;
    while (temp->next != tail)
    {
      temp = temp->next;
    }
    temp->next = NULL;
    tail->next = head;
    head = tail;
}
void addtolist(int num)
{
    Node *temp = new Node();
    temp->data=num;
    temp->next=NULL;
    if (head==NULL)
    {
      head=temp;
      tail=temp;
      return;
    }
    tail->next=temp;
    tail=temp;
}
int main()
{
    int t;
    cin>>t;
    for (int q=0; q<t; q++)
    {
      head = NULL;
      tail = NULL;
      int n;
      cin>>n;
      int num;
      for (int i=0; i<n; i++)
      {
        cin>>num;
        addtolist(num);
      }
      rotatelist();
      printlist();
    }
    return 0;
}
