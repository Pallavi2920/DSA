#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};
typedef Node Node;
int ans = 1;
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
void leafNode(Node *root,int level,int &levelNode)
{
    if(root==NULL)  return;
    if(root->left==NULL && root->right == NULL)
    {
        if(level == -1)
        {
            levelNode = level;
        }
        else if(level !=levelNode)
        {
            ans = 0;
        }
    }
    leafNode(root->left,level+1,levelNode);
    leafNode(root->right,level+1,levelNode);

}
bool levelLeafNode(Node *root)
{
      int level = -1;
      int levelNode = 0;
      leafNode(root,level,levelNode);
      if(ans==0)  return false;
      else  return true;
}
int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    cout<<levelLeafNode(root);

}
