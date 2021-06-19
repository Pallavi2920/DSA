#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
typedef struct Node Node;

Node *create()
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    int x;
    cout<<"Enter the value (-1 for no entry):"<<endl;
    cin>>x;
    if(x==-1) return 0;
    newNode->data = x;
    cout<<"Enter the left child of "<<x<<":";
    newNode->left=create();
    cout<<"Enter the right child of "<<x<<":";
    newNode->right=create();
    return newNode;
}
void inOrder(Node *root)
{
    if(root==NULL)  return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    inOrder(root);

}
