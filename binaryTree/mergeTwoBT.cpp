#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    Node *left,*right;
    int data;
}Node;
Node *root = NULL;

Node *create()
{
    int x;
    Node *newNode=(Node*)malloc(sizeof(Node));
    cout<<"Enter the value (-1 for no data):";
    cin>>x;
    if(x==-1) return 0;
    newNode->data = x;
    cout<<"Enter the left child of "<<x<<" ";
    newNode->left = create();
    cout<<"Enter the right child of "<<x<<" ";
    newNode->right = create();
    return newNode;
}
Node *mergeTwoBT(Node*root1,Node*root2)
{
    if(root1==NULL) return root2;
    if(root2==NULL) return root1;
    root1->data += root2->data;
    root1->left = mergeTwoBT(root1->left,root2->left);
    root1->right = mergeTwoBT(root1->right,root2->right);
    return root1;
}
void inOrder(Node*root)
{
    if(root)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
int main()
{
    Node *root1 = (Node*)malloc(sizeof(Node));
    Node *root2 = (Node*)malloc(sizeof(Node));
    cout<<"Enter the values of tree1:"<<endl;
    root1 = create();
    cout<<"Enter the values of tree2:"<<endl;
    root2 = create();
    root1 = mergeTwoBT(root1,root2);
    cout<<"The Inorder Traversal of two merged trees is:"<<endl;
    inOrder(root1);
}
