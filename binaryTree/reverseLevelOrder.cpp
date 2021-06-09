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
std::vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*>q;
    std::vector<int> v;
    if(root==NULL)  return v;
    q.push(root);
    while(!q.empty())
    {
        Node *current = (Node*)malloc(sizeof(Node));
        current = q.front();
        q.pop();
        v.push_back(current->data);
        if(current->right!=NULL)  q.push(current->right);
        if(current->left!=NULL)   q.push(current->left);
    }
    return v;
}

int main()
{
    Node *root = (Node*)malloc(sizeof(Node));
    root = create();
    std::vector<int> v1;
    v1 = reverseLevelOrder(root);
    reverse(v1.begin(),v1.end());
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

}
