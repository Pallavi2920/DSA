// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.

#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *left,*right;
}Node;
struct Info
{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};
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
Info largestBST(Node *root)
{
    if(root==NULL)  return{0,INT_MAX,INT_MIN,0,true};
    if(root->left == NULL && root->right == NULL)
    {
        return{1,root->data,root->data,1,true};
    }
    Info infoLeft = largestBST(root->left);
    Info infoRight = largestBST(root->right);
    Info curr;
    curr.size = (1 + infoLeft.size + infoRight.size);
    if(infoLeft.isBST && infoRight.isBST && infoLeft.max<root->data && infoRight.min>root->data)
    {
        curr.min = min(infoLeft.min,min(infoRight.min,root->data));
        curr.max = max(infoRight.max,max(infoLeft.max,root->data));
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(infoLeft.ans,infoRight.ans);
    curr.isBST = false;
    return curr;
}

int main()
{
    Node *root = (Node *)malloc(sizeof(Node));
    root = create();
    cout<<"Largest BST in the Binary Tree : "<<largestBST(root).ans<<endl;

}
