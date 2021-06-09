// InOrder Traversal of a tree without recursion
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
void inOrder(Node *root)
{
    stack<Node*>s;
    s.push(root);
    while(!s.empty())
    {
        Node *current = (Node*)malloc(sizeof(Node));
        current = s.top();
        if(current->left!=NULL) s.push(current->left);
        else
        {
            s.pop();
            cout<<current->data<<" ";
            s.push(current->right);
        }
    }
}



int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    inOrder(root);

}
