#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    Node *left,*right;
    int data;
}Node;
int sum = 0;
Node *create()
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    int x;
    cout<<"Enter the data (-1 for no data)";
    cin>>x;
    if(x==-1) return 0;
    newNode->data = x;
    cout<<"Enter the left child of "<<x<<":"<<endl;
    newNode->left = create();
    cout<<"Enter the right child of "<<x<<":"<<endl;
    newNode->right = create();
    return newNode;
}
Node *LAC(Node *root,int n1,int n2)
{
    if(root==NULL)  return 0;
    if(n1==root->data || n2==root->data)  return root;
    Node *l = LAC(root->left,n1,n2);
    Node *r = LAC(root->right,n1,n2);
    if(l && r)  return root;
    if(l) return l;
    else return r;
}
int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    Node *newNode = (Node*)malloc(sizeof(Node));
    int n1,n2;
    cout<<"Enter the value of n1 and n2 : ";
    cin>>n1>>n2;
    newNode = LAC(root,n1,n2);
    cout<<"The Lowest Common Ancestor of "<<n1<<" and "<<n2<<" is:"<<newNode->data;

}
