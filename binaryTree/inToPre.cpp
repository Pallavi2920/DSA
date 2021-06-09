#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left,*right;
};
typedef struct Node Node;
int search(int inOrder[], int lb,int ub,int val)
{
    for(int i = lb;i < ub;i++)
    {
        if(val==inOrder[i])
          return i;
    }
}
Node *inToPre(int inOrder[],int preOrder[],int lb,int ub)
{
    static int i=0;
    if(lb>ub) return NULL ;
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = preOrder[i++];
    if(lb==ub)  return newNode;
    int mid = search(inOrder,lb,ub,newNode->data);
    newNode->left = inToPre(inOrder,preOrder,lb,mid-1);
    newNode->right = inToPre(inOrder,preOrder,mid+1,ub);
    return newNode;
}
void postOrder(Node *root)
{
    if(root==NULL)  return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int n;
    cin>>n;
    int inOrder[n],preOrder[n];
    for(int i=0;i<n;i++)
    {
        cin>>inOrder[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>preOrder[i];
    }
    Node *root = (Node*)malloc(sizeof(Node));
    root = inToPre(inOrder,preOrder,0,n-1);
    postOrder(root);
}
