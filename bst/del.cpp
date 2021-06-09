// Insertion, Deletion and Searching in BST
#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    Node *left,*right;
}Node;
Node *root = NULL;
Node *insert(Node *temp,int key)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(temp == NULL)
    {
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if(temp->data<key)
    {
        temp->right = insert(temp->right , key);
    }
    else if(temp->data>key)
    {
        temp->left = insert(temp->left , key);
    }
    return temp;
}
int findMax(Node *node)
{
    int maxVal = node->data;
    while(node->right!=NULL)
    {
        maxVal = node->right->data;
        node = node->right;
    }
    // cout<<"MaxValue is:"<<maxVal;
    return maxVal;
}
Node *deleteNode(Node *node, int key)
{
    if(key < node->data)
    {
        node->left = deleteNode(node->left, key);
    }
    else if(key>node->data)
    {
        node->right = deleteNode(node->right, key);
    }
    else
    {
        if(node->left==NULL)
        {
            node = node->right;
        }
        else if(node->right==NULL)
        {
            node = node->left;
        }
        else
        {
            node->data = findMax(node->left);
            node->left = deleteNode(node->left , node->data);
        }

    }
    return node;
}
void addNode(int key)
{
    root = insert(root , key);
}
void preOrder(Node*root)
{
    if(root==NULL)  return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node*root)
{
    if(root==NULL)  return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main()
{
    int n;
    cout<<"Enter the number of value you want to insert:";
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        addNode(ele);

    }
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"Enter the value you want to delete:";
    int x;
    cin>>x;
    deleteNode(root ,x);
    preOrder(root);
    cout<<endl;
    inOrder(root);

}
