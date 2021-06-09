#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};
typedef Node Node;
Node *create()
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    int x;
    cout<<"Enter the node value(-1 for no node)"<<endl;
    cin>>x;
    if(x==-1) return 0;
    newNode->data = x;
    cout<<"Enter the left child of x:"<<x<<endl;
    newNode->left = create();
    cout<<"Enter the right child of x:"<<x<<endl;
    newNode->right = create();
    return newNode;
}
int mirror(Node *root)
{
    if(root==NULL) return 0;
    mirror(root->left);
    mirror(root->right);
    swap(root->left,root->right);
}
void preOrder(Node *root)
{
    if(root==NULL)  return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    preOrder(root);
    mirror(root);
    preOrder(root);

}
