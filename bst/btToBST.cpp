// Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
// Steps:
//   1.InOrder Traversal of binary tree and store it in a vector.
//   2.Sort the vector.
//   3.Traverse the binary tree in InOrder and replace the root value with the value in vector.
#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *left,*right;
}Node;

int i=0;
Node *create()
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    int x;
    cout<<"Enter the data (-1 for no data):"<<endl;
    cin>>x;
    if(x==-1)  return 0;
    newNode->data = x;
    cout<<"Enter the left child of "<<x<<":"<<endl;
    newNode->left = create();
    cout<<"Enter the right child of "<<x<<":"<<endl;
    newNode->right = create();
    return newNode;
}
void inOrder(Node*root,std::vector<int> &v)
{
    if(root==NULL)  return;
    inOrder(root->left,v);
    v.push_back(root->data);
    inOrder(root->right,v);
}
void changeToBST(Node *root,std::vector<int> &v,int &i)
{
    if(root==NULL)  return;
    changeToBST(root->left,v,i);
    root->data = v[i];
    i++;
    changeToBST(root->right,v,i);
}
void inOrderT(Node * root)
{
    if(root==NULL)  return;
    inOrderT(root->left);
    cout<<root->data<<" ";
    inOrderT(root->right);
}
int main()
{
    int i =0;
    std::vector<int> v;
    Node *root = (Node*)malloc(sizeof(Node));
    root=create();
    cout<<"The Inorder Traversal of Binary Tree is:"<<endl;
    inOrderT(root);
    inOrder(root,v);
    sort(v.begin(),v.end());
    changeToBST(root,v,i);
    cout<<"The Inorder Traversal of BST is:"<<endl;
    inOrderT(root);
}
