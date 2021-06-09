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
std::vector<int>zigZagLevelOrder(Node *root)
{
    std::vector<int> v;
    if(root == NULL)  return v;
    queue<Node*>q;
    q.push(root);
    int flag = 1;
    while(!q.empty())
    {
        int size ;
        std::vector<int> temp;
        size = q.size();
        while(size--)
        {
            Node *current = (Node *)malloc(sizeof(Node));
            current = q.front();
            q.pop();
            temp.push_back(current->data);
            if(current->left!=NULL) q.push(current->left);
            if(current->right!=NULL)  q.push(current->right);
        }
        if(flag%2==0) reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
        {
            v.push_back(temp[i]);
        }
        flag = !flag;
    }
return v;
}
int main()
{
    std::vector<int> v1;
    Node *root = (Node *)malloc(sizeof(Node));
    root = create();
    v1 = zigZagLevelOrder(root);
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}
