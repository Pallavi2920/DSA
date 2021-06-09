#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *left,*right;
}Node;

Node *insert(Node *root,int key)
{
    if(root == NULL)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
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
void findNode(Node *node , Node *&pre,Node *&suc,int key)
{
    if(node==NULL)  return;
    if(key==node->data)
    {
        if(node->left!=NULL)
        {
            Node *temp = node->left;
            while(temp->right)
            {
                temp = temp->right;
            }
            pre = temp;
        }
        if(node->right!=NULL)
        {
            Node  *temp1 = node->right;
            while(temp1->left)
            {
                temp1 = temp1->left;
            }
            suc = temp1;
        }
        return;
    }
    if(key<node->data)
    {
        suc = node;
        findNode(node->left,pre,suc,key);
    }
    else
    {
        pre = node;
        findNode(node->right,pre,suc,key);
    }
}
int main()
{
    Node *root = NULL;
    root = insert(root , 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    Node *pre = NULL,*suc = NULL;
    int x;
    cout<<"Enter the key for whom you want to search for predecessor and successor"<<endl;
    cin>>x;
    findNode(root,pre,suc,x);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor"<<endl;

    if (suc != NULL)
      cout << "Successor is " << suc->data;
    else
      cout << "No Successor"<<endl;


    return 0;
}
