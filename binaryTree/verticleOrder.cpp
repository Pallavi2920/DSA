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
void preOrder(Node *root)
{
    if(root==NULL)  return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void topView(Node *root)
{
    if(root == NULL)  return;
    queue<Node*>q;
    map<int , int>mp;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    while(!q.empty())
    {
        Node * current = (Node*)malloc(sizeof(Node));
        current = q.front();
        int hd = current->hd;
        q.pop();
        if(mp.count(hd) == 0)
        {
            mp[hd] = current->data;
        }
        if(current->left !=NULL)
        {
            current->left->hd = hd-1;
            q.push(current->left);
        }
        if(current->right !=NULL)
        {
            current->right->hd = hd+1;
            q.push(current->right);
        }

    }
    map<int , int>::iterator it;
    for(it = mp.begin(); it!=mp.end() ; it++)
    {
        cout<<it->second<<" ";
    }


}
void bottomView(Node *root)
{
    if(root == NULL)  return;
    queue<Node*>q;
    map<int , int>mp;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    while(!q.empty())
    {
        Node * current = (Node*)malloc(sizeof(Node));
        current = q.front();
        int hd = current->hd;
        q.pop();
        if(mp.count(hd) >= 0)
        {
            mp[hd] = current->data;
        }
        if(current->left !=NULL)
        {
            current->left->hd = hd-1;
            q.push(current->left);
        }
        if(current->right !=NULL)
        {
            current->right->hd = hd+1;
            q.push(current->right);
        }

    }
    map<int , int>::iterator it;
    for(it = mp.begin(); it!=mp.end() ; it++)
    {
        cout<<it->second<<" ";
    }


}
int main()
{
    Node *root = (Node *)malloc(sizeof(Node));
    root = create();
    preOrder(root);
    cout<<endl;
    topView(root);
    cout<<endl;
    bottomView(root);
    cout<<endl;
}
