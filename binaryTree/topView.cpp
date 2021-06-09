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
void left(Node*root)
{
    if (root==NULL) return;
    left(root->left);
    cout<<root->data<<" ";
}
void right(Node*root)
{
    if (root==NULL) return;
    cout<<root->data<<" ";
    right(root->right);
}



int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    left(root);
    right(root->right);

}
