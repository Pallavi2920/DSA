// Lowest Common Ancestor in a BST
// Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.
#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    Node* left, *right;
    int data;
}Node;
Node *root=NULL;
Node *insert(Node*root,int key)
{
      if(root==NULL)
      {
          Node* newNode = (Node*)malloc(sizeof(Node));
          newNode->data = key;
          newNode->left = NULL;
          newNode->right = NULL;
          return newNode;
      }
      if(key<root->data)
      {
          root->left = insert(root->left,key);
      }
      else if(key>root->data)
      {
          root->right = insert(root->right,key);
      }
      return root;
}
void addNode(int key)
{
    root = insert(root,key);
}
Node *LCA(Node *root,int n1,int n2)
{
    if(root==NULL)  return 0;
    if(root->data<n1 && root->data<n2)
    {
        return LCA(root->right,n1,n2);
    }
    else if(root->data>n1 && root->data>n2)
    {
        return LCA(root->left,n1,n2);
    }
    return root;
}
int main()
{
    int n;
    cout<<"Enter the number of elements you want to insert:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        addNode(ele);
    }
    int n1,n2;
    cout<<"Enter the value for n1 and n2 : ";
    cin>>n1>>n2;
    Node *newNode = LCA(root,n1,n2);
    cout<<newNode->data<<endl;
}
