#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
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
void diagonal(Node *root)
{
    if(root==NULL)  return;
    queue<Node *>q;
    std::vector<int> v;
    q.push(root);
    while(!q.empty())
    {
        Node *current = (Node*)malloc(sizeof(Node));
        current = q.front();
        q.pop();
        while(current)
        {
            if(current->left) q.push(current->left);
            v.push_back(current->data);
            current = current->right;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
int main()
{
    std::vector<int> v;
    Node *root = (Node *)malloc(sizeof(Node));
    root = create();
    diagonal(root);
    cout<<endl;

}
