// Populate Inorder Successor for all nodes
// Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.
#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    Node *left,*right;
}Node;
Node *root = NULL;
std::vector<int> v;
Node *create()
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    int x;
    cout<<"Enter the value (-1 for no value):";
    cin>>x;
    if(x==-1) return 0;
    newNode->data = x;
    cout<<"Enter the left child of "<<x;
    newNode->left = create();
    cout<<"Enter the right child of "<<x;
    newNode->right = create();
    return newNode;
}
void inOrder(Node *root)
{

    if(root==NULL)  return;
    inOrder(root->left);
    v.push_back(root->data);
    inOrder(root->right);
}
int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    inOrder(root);
    for(int i=0;i<v.size();i++)
    {
        if(i==v.size()-1)
        {
            cout<<v[i]<<"->-1";
        }
        else
        {
            cout<<v[i]<<"->"<<v[i+1]<<" ";
        }
    }
}
