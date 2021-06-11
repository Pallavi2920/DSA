// Construct Binary Search Tree from Preorder Traversal
#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *left,*right;
}Node;
Node *root = NULL;
Node *insert(Node*root,int key)
{
    if(root==NULL)
    {
        Node *newNode=(Node*)malloc(sizeof(Node));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if(key<root->data)
    {
        root->left = insert(root->left,key);
    }
    else if(key>root->data)
    {
        root->right = insert(root->right,key);
    }
    return root;
}
void  addNode(int key)
{
    root = insert(root,key);
}
void inOrder(Node *root)
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
    std::vector<int>preOrder;
    int n;
    cout<<"Enter the number of elements you want to insert:"<<endl;
    cin>>n;
    cout<<"Enter the elements if PreOrder Traversal:"<<endl;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        preOrder.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        addNode(preOrder[i]);
    }
    inOrder(root);
}
