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
int sumTree(Node *root)
{
    if(root == NULL)  return 0;
    if(root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    return (root->data+sumTree(root->left)+sumTree(root->right));
}

int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    int sum = sumTree(root)-root->data;
    if(sum==root->data)
    {
        cout<<"1";
    }
    else  cout<<"0";

}
