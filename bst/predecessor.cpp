#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *left,*right;
}Node;
Node *root = NULL;
Node *insert(Node *root,int key)
{
    if(root == NULL)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
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
void addData(int key)
{
    insert(root,key);
}

int main()
{
    int n;
    cout<<"Enter the number of elements you want to insert:";
    cin>>n;
    for(int i =0 ;i<n;i++)
    {
        int ele;
        cin>>ele;
        addData(ele);
    }
}
