// Given a binary search tree, return a balanced binary search tree with the same node values.

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
    if(root==NULL)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if(root->data>key)
    {
        root->left = insert(root->left,key);
    }
    else if(root->data<key)
    {
        root->right = insert(root->right,key);
    }
    return root;
}
void  addNode(int key)
{
    root = insert(root,key);
}
void inOrder(Node *root,std::vector<int> &v)
{
      if(root)
      {
          inOrder(root->left,v);
          v.push_back(root->data);
          inOrder(root->right,v);
      }
}
void preOrder(Node *root)
{
      if(root)
      {
          cout<<root->data<<" ";
          preOrder(root->left);
          preOrder(root->right);
      }
}
Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
Node *balancedBST(int start,int end,std::vector<int> v)
{
    if (start > end)  return NULL;
    int mid = (start + end)/2;
    Node *root = newNode(v[mid]);
    root->left = balancedBST(start, mid - 1,v);
    root->right = balancedBST(mid + 1, end,v);
    return root;
}
int main()
{
    int n;
    std::vector<int> v;
    cout<<"Enter the number of elements you want to insert:"<<endl;
    cin>>n;
    cout<<"Enter the elements if PreOrder Traversal:"<<endl;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        addNode(ele);
    }
    inOrder(root,v);
    preOrder(root);
    cout<<endl;
    root = balancedBST(0,n-1,v);
    preOrder(root);
    cout<<endl;

}
