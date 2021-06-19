#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    Node *left,*right;
    int data;
}Node;

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

bool cousins(Node *root, int x1, int x2)
{
    queue<pair<Node *,Node *>>q;
    Node *temp = NULL;
    Node *parA = NULL;
    Node *parB = NULL;
    pair<Node*, Node*> ele;
    q.push(make_pair(root,temp));
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; i++ )
        {
            ele = q.front();
            q.pop();
            if(x1 == ele.first->data)
            {
                parA = ele.second;
            }
            if(x2 == ele.first->data)
            {
                parB = ele.second;
            }
            if(ele.first->left != NULL)
            {
                q.push(make_pair(ele.first->left, ele.first));
            }
            if(ele.first->right != NULL)
            {
                q.push(make_pair(ele.first->right, ele.first));
            }
            if(parA && parB)
            {
                break;
            }
        }
        if(parA && parB)
        {
            if(parA == parB)  return false;
            else if (parA != parB) {
              return true;
            }
        }
        if(parA || parB)  return false;
    }

    return false;
}
int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    int x1,x2;
    cout<<"Enter the value of x1 and x2:";
    cin>>x1>>x2;
    cout<<cousins(root,x1,x2);
}
