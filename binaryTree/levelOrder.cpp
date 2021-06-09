#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};
typedef Node Node;
void preorder(Node *root)
{
    if(root==0) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if(root==0) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if(root==0) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelorder(Node *root)
{
    if(root==0) return;
    Node *current = (Node*)malloc(sizeof(Node));
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        current= q.front();
        q.pop();
        cout<<current->data<<" ";
        if(current->left!=NULL) q.push(current->left);
        if(current->right!=NULL)  q.push(current->right);
    }
}
vector<int>leftView(Node *root)
{

      std::vector<int> v;
      queue<Node*>q;
      if(root==NULL)  return v;
      q.push(root);
      while(!q.empty())
      {
          int n=q.size();
          for(int i=1;i<=n;i++)
          {
              Node *current=(Node*)malloc(sizeof(Node));
              current = q.front();
              q.pop();
              if(i==1)  v.push_back(current->data);
              if(current->left!=NULL) q.push(current->left);
              if(current->right!=NULL) q.push(current->right);
          }
        }
        return v;
}
vector<int>rightView(Node *root)
{

      std::vector<int> v;
      queue<Node*>q;
      if(root==NULL)  return v;
      q.push(root);
      while(!q.empty())
      {
          int n=q.size();
          for(int i=1;i<=n;i++)
          {
              Node *current=(Node*)malloc(sizeof(Node));
              current = q.front();
              q.pop();
              if(i==n)  v.push_back(current->data);
              if(current->left!=NULL) q.push(current->left);
              if(current->right!=NULL) q.push(current->right);
          }
        }
        return v;
}

int height(Node *root)
{
    if(root==NULL)  return -1;
    int left = height(root->left);
    int right = height(root->right);
    return 1+max(left,right);
}
int size(Node *root)
{
    if(root==0) return 0;
    return 1+(size(root->left)+size(root->right));
}
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

int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;
    cout<<"Height of tree is "<<height(root)<<endl;
    cout<<"Size of tree is "<<size(root)<<endl;
    std::vector<int> v=leftView(root);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    std::vector<int> v1=rightView(root);
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}
