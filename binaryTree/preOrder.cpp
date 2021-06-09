// PreOrder Traversal of a tree without recursion
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};
typedef Node Node;
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
void preOrder(Node *root)
{
    stack<Node*>s;
    s.push(root);
    while(!s.empty())
    {
        Node *current = (Node*)malloc(sizeof(Node));
        current = s.top();
        s.pop();
        cout<<current->data<<" ";
        if(current->right!=NULL)  s.push(current->right);
        if(current->left!=NULL)  s.push(current->left);
    }
}



int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    preOrder(root);

}
