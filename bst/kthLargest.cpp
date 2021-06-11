// Kth largest element in BST
// Given a Binary search tree. Your task is to complete the function which will return the Kth largest element
#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *left,*right;
}Node;
Node *root = NULL;
Node *insert(Node *root,int key)
{
    if(root==NULL)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if(root->data>key)
    {
        root->left = insert(root->left,key);
    }
    else if(root->data<key)
    {
        root->right = insert(root->right,key);
    }
    return root;
}
void inOrder(Node *root,std::vector<int> &v)
{
      if(root)
      {
          inOrder(root->left,v);
          v.push_back(root->data);
          inOrder(root->right,v);
      }
}
void  addNode(int key)
{
    root = insert(root,key);
}
int main()
{
    int n;
    std::vector<int> v;
    cout<<"Enter the number of elements you want to insert:"<<endl;
    cin>>n;
    cout<<"Enter the elements if PreOrder Traversal:"<<endl;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        addNode(ele);
    }
    inOrder(root,v);
    reverse(v.begin(),v.end());
    cout<<"Enter the value of k:";
    int k;
    cin>>k;
    cout<<"The "<<k<<"th largest element is "<<v[k-1];
}
