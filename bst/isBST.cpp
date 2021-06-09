// Given a binary Tree check if it is a binary tree or not
// Approach :Calculate the inOrder Traversal and see if it is in sorted order or not.
#include<bits/stdc++.h>
using namespace std;
std::vector<int> v;
typedef struct Node
{
    int data;
    Node *left,*right;
}Node;
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
void inOrder(Node *root)
{

    if(root==NULL)  return;
    inOrder(root->left);
    v.push_back(root->data);
    inOrder(root->right);

}
bool isBST(Node* root)
{
    inOrder(root);
    for(int i=0;i<v.size()-1;i++)
    {
          if(v[i]>=v[i+1])
              return false;
    }
    return true;
}
int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    if(isBST(root)) cout<<"1";
    else  cout<<"0";
    return 0;
}
