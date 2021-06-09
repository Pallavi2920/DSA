#include<bits/stdc++.h>
using namespace std;
struct Node
{
    Node *left,*right;
    int data;
};
typedef struct Node Node;
Node *insert(Node * temp,int key)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(temp == NULL)
    {
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if(key<temp->data)
    {
        temp->left =  insert(temp->left,key);
    }
    else if(key>temp->data)
    {
        temp->right = insert(temp->right,key);
    }
    return temp;
}
void *search(Node*root,int key)
{
    if(key==root->data) delete root;
    else if(key<root->data) search(root->left,key);
    else if(key>root->data) search(root->right,key);
}
void preOrder(Node *root)
{
    if(root==NULL)  return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}
void inOrder(Node *root)
{
    if(root==NULL)  return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main()
{
    int pre[] = {20, 10, 5, 15, 13, 35, 30, 42};
    Node *root = (Node*)malloc(sizeof(Node));
    root->data = pre[0];
    for(int i=1;i<8;i++)
    {
        insert(root,pre[i]);
    }
    preOrder(root);
    cout<<endl;
    inOrder(root);
    search(root,42);
    inOrder(root);

}
