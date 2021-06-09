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
void leftView(Node *root)
{
    std::vector<int> v;
    queue<Node*>q;
    if(root==NULL)  return ;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=1;i<n;i++)
        {
            Node *current=(Node*)malloc(sizeof(Node));
            current = q.front();
            q.pop();
            if(i==1)  cout<<current->data<<" ";
            if(current->left!=NULL) q.push(current->left);
            if(current->right!=NULL) q.push(current->right);
        }
      }
}
int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    leftView(root);

}
