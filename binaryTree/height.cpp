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
int height(Node *root)
{
    if(root==NULL)  return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1+max(left,right);
}

int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    cout<<"Height of a tree is: "<<height(root);

}
