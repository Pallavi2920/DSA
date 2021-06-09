#include<bits/stdc++.h>
using namespace std;
std::vector<int> v;
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
void leftboundary(Node *root,std::vector<int> &v)
{
    if(root==NULL)  return;
    if(root->left)
    {
        v.push_back(root->data);
        leftboundary(root->left,v);
    }
    else if(root->right)
    {
        v.push_back(root->data);
        leftboundary(root->right,v);
    }

}
void leafNodes(Node *root,std::vector<int> &v)
{
    if(root==NULL)  return;
    if(root->left)  leafNodes(root->left,v);
    if(root->left == NULL && root->right == NULL)
    {
        v.push_back(root->data);
    }
    if(root->right) leafNodes(root->right,v);
}
void rightBoundary(Node *root,std::vector<int> &v)
{

    if(root==NULL)  return;
    if(root->left)
    {
        v.push_back(root->data);
        rightBoundary(root->right,v);

    }
    else if(root->right)
    {
        v.push_back(root->data);
        rightBoundary(root->left,v);
    }

}
int main()
{
    std::vector<int> v;
    Node *root = (Node *)malloc(sizeof(Node));
    root = create();
    v.push_back(root->data);
    leftboundary(root->left,v);
    leafNodes(root,v);
    rightBoundary(root->right,v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

}
