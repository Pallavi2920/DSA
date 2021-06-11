// Preorder to Postorder
// Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.
#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    Node *left,*right;
}Node;
Node *root = NULL;
Node *insert(Node*root,int key)
{
    if(root==NULL)
    {
        Node *newNode=(Node*)malloc(sizeof(Node));
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
void  addNode(int key)
{
    root = insert(root,key);
}
void postOrder(Node *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}


int main()
{
    int n;
    cout<<"Enter the number of elements you want to insert:"<<endl;
    cin>>n;
    cout<<"Enter the elements of PreOrder Traversal:"<<endl;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        addNode(ele);
    }
    postOrder(root);
    cout<<endl;
}
