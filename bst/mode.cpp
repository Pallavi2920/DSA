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
void inOrder(Node *root)
{
    if(root==NULL)  return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int findMax(Node *node)
{
    int max = node->data;
    while(node->right!=NULL)
    {
        max =node->right->data;
        node = node->right;
    }
    return max;
}
Node *deleteNode(Node *node,int key)
{
      if(node->data>key)
      {
          deleteNode(node->left,key);
      }
      else if(node->data<key)
      {
          deleteNode(node->right,key);
      }
      else if(node->data==key)
      {
          if(node->left && node->right)
          {
              node->data = findMax(node->left);
              node->left = deleteNode(node->left,node->data);
          }
          else if(node->left==NULL)
          {
              node = node->right;
          }
          else if(node->right==NULL)
          {
              node = node->left;
          }
      }
      return node;
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
    int key;
    cout<<"Enter the key you want to delete:"<<endl;
    cin>>key;
    deleteNode(root,key);
    inOrder(root);
}
