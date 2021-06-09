#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    int hd;
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
int height(Node *root)
{
    if(root==NULL)  return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1+(max(left,right));
}
bool isBalanced(Node *root)
{
    if(root==NULL)
    {
        return true;
    }
    int lh =height(root->left);
    int rh =height(root->right);
    if(abs(lh-rh)<=1 && isBalanced(root->left) &&isBalanced(root->right)) return true;
    else
      return false;
}
int main()
{
    std::vector<int> v1;
    Node *root = (Node *)malloc(sizeof(Node));
    root = create();
    cout<<isBalanced(root)<<endl;

}
