#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    Node *left,*right;
    int data;
}Node;
int sum = 0;
Node *create()
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    int x;
    cout<<"Enter the data (-1 for no data)";
    cin>>x;
    if(x==-1) return 0;
    newNode->data = x;
    cout<<"Enter the left child of "<<x<<":"<<endl;
    newNode->left = create();
    cout<<"Enter the right child of "<<x<<":"<<endl;
    newNode->right = create();
    return newNode;
}
void preOrder(Node *root)
{
    if(root==NULL)  return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void pTest(Node *root,int n)
{
    if(root==NULL)  return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node *current = (Node*)malloc(sizeof(Node));
        current = q.front();
        q.pop();
        if(current->data!=n)
        {
            sum+=current->data;
            if(current->left!=NULL)  q.push(current->left);
            if(current->right!=NULL)  q.push(current->right);
        }
    }
}

int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    preOrder(root);
    int n;
    cin>>n;
    pTest(root,n);
    cout<<sum<<endl;
}
