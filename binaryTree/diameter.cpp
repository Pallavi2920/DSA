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

int diameter(Node *root)
{
    if(root==NULL)  return 0;
    int opt1 = height(root->left)+height(root->right);
    int opt2 = diameter(root->left);
    int opt3 = diameter(root->right);
    return max(opt1,max(opt2,opt3));
}

int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    cout<<"Diameter of tree is: "<<diameter(root)+1;

}
