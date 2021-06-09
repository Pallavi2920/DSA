#include<bits/stdc++.h>
using namespace std;
std::vector<int> v;
struct Node
{
    int data;
    int temp;
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
int twoSum(Node *root)
{
    if(root == NULL)  return 0;
    int oldVal = root->data;
    int left = twoSum(root->left);
    int right = twoSum(root->right);
    root->data = left+right;
    return oldVal+left+right;
}
void preOrder(Node * root)
{
    if(root==NULL)  return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    std::vector<int> v;
    Node *root = (Node *)malloc(sizeof(Node));
    root = create();
    twoSum(root);
    preOrder(root);

}
