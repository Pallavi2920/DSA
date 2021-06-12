#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    Node* left, *right;
    int data;
}Node;
Node *root=NULL;
Node *insert(Node*root,int key)
{
      if(root==NULL)
      {
          Node* newNode = (Node*)malloc(sizeof(Node));
          newNode->data = key;
          newNode->left = NULL;
          newNode->right = NULL;
          return newNode;
      }
      if(key<root->data)
      {
          root->left = insert(root->left,key);
      }
      else if(key>root->data)
      {
          root->right = insert(root->right,key);
      }
      return root;
}
void addNode(int key)
{
    root = insert(root,key);
}
void inOrder(Node *root,std::vector<int> &v)
{
    if(root==NULL)  return;
    inOrder(root->left,v);
    v.push_back(root->data);
    inOrder(root->right,v);
}
int main()
{
    std::vector<int> v;
    int n;
    cout<<"Enter the number of value you want to insert:";
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        addNode(ele);
    }
    int l,u;
    cout<<"Enter the lower bound and upper bound:"<<endl;
    cin>>l>>u;
    inOrder(root,v);
    int freq = 0;

    for(int i=0;i<v.size();i++)
    {
        if(v[i]>=l && v[i]<=u)
        {
            freq++;
        }
    }
    cout<<freq<<endl;
}
